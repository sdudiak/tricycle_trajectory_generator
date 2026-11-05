#include "tri_gen_trajectry_generator/trajectory_generator_node.hpp"

TrajectoryGeneratorNode::TrajectoryGeneratorNode() : Node("trajectory_generator_node")
{
    callback_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);

    generate_trajectory_service_ = this->create_service<GenerateTrajectorySrv>(
        "generate_trajectory",
        std::bind(
            &TrajectoryGeneratorNode::generateTrajectoryCb,
            this,
            std::placeholders::_1,
            std::placeholders::_2),
        rmw_qos_profile_services_default,
        callback_group_);
    
    trajectory_publisher_ = this->create_publisher<TrajectoryMsg>
    ("trajectory_preview",10);
    trajectory_marker_pub_ = this->create_publisher<visualization_msgs::msg::MarkerArray>("trajectory_markers", 1);

    //TODO add proper parameter loading and handling 

    trajectory_generator_p_ = std::make_shared<NLPTrajectoryGeneratorFixedDt>(NLPTrajectoryGeneratorFixedDt(1.3)); // Fixed L for now
    RCLCPP_INFO(get_logger(), "Trajector Generator Node initialized");
}

void TrajectoryGeneratorNode::generateTrajectoryCb(
    const std::shared_ptr<GenerateTrajectorySrv::Request> request,
    std::shared_ptr<GenerateTrajectorySrv::Response> response)
    {
        RCLCPP_INFO(get_logger(), "Trajectory requested");
        response->success = false;
        if(trajectory_is_being_generated_)
        {
            RCLCPP_WARN(get_logger(), "Requested another trajectory while one is being processed. Skipping the request");
            response->message = "A trajectory is already being generated";
            return;
        }

        if (!verifyConstraints(request))
        {
            response->message = "The passed constraints were incorrect";
            return;
        }

        int number_of_optimizer_steps = estimateNumberOfOptimizationSteps(request->start, request->goal, request->dt, request->v_max);
        
        Constraints constraints;
        constraints.phi_min = request->phi_min;
        constraints.phi_max = request->phi_max;
        constraints.omega_min = request->omega_phi_min;
        constraints.omega_max = request->omega_phi_max;
        constraints.v_min = request->v_min;
        constraints.v_max = request->v_max;
        constraints.acc_min = request->a_min;
        constraints.acc_max = request->a_max;

        // Prepare the trajectory generator
        trajectory_generator_p_->setDt(request->dt);
        trajectory_generator_p_->setHorizon(number_of_optimizer_steps + 10); // Additional number of steps to help with achieving the goal
        trajectory_generator_p_->setConstraints(constraints);

        // Generate the trajectory
        RCLCPP_INFO(get_logger(), "Generating trajectory...");
        // Use ROS 2 clock to get start time
        rclcpp::Clock steady_clock(RCL_STEADY_TIME);
        rclcpp::Time start_time = steady_clock.now();
        TrajectoryMsg trajectory;
        try
        {
            trajectory = trajectory_generator_p_->generateTrajectory(request->start, request->goal);
        }
        catch(const std::exception& e)
        {
            RCLCPP_ERROR_STREAM(get_logger(),"Failed to generate trajectory: " << e.what());
            response->message = e.what();
            return;
        }
        rclcpp::Time end_time = steady_clock.now();
        double duration_ms = (end_time - start_time).seconds() * 1000.0;

        RCLCPP_INFO(get_logger(), "Trajectory generated in %.2f ms.", duration_ms);

        //TODO: Trajectory checking - was the goal achieved
        //TODO: Constraints checking
        //TODO: Calculate trajectory length
        //TODO: Calculate the curvature

        response->trajectory = trajectory;
        response->success = true;
        response->generation_time_ms = duration_ms;
        response->message = "Trajectory generated succesfully";
        trajectory_publisher_->publish(trajectory);
        publishTrajectoryMarkers(trajectory, request->start, request->goal);
        RCLCPP_INFO(get_logger(), "Trajectory generated succesfully");
    }


    bool TrajectoryGeneratorNode::verifyConstraints(const std::shared_ptr<GenerateTrajectorySrv::Request> request) const
    {
        // Add phimin phimax parameters
        if (request->phi_min >= request->phi_max)
        {
            RCLCPP_WARN(get_logger(), "Invalid constraints: phi_min >= phi_max");
            return false;
        }

        if (request->omega_phi_min >= request->omega_phi_max)
        {
            RCLCPP_WARN(get_logger(), "Invalid constraints: omega_phi_min >= omega_phi_max");
            return false;
        }

        if (request->v_min >= request->v_max)
        {
            RCLCPP_WARN(get_logger(), "Invalid constraints: v_min >= v_max");
            return false;
        }

        if (request->a_min >= request->a_max)
        {
            RCLCPP_WARN(get_logger(), "Invalid constraints: a_min >= a_max");
            return false;
        }

        return true;
    }

    int TrajectoryGeneratorNode::estimateNumberOfOptimizationSteps(const StateMsg &start, const StateMsg &goal, double dt, int v_max) const
    {
        double dx = goal.x - start.x;
        double dy = goal.y - start.y;
        double linear_distance = std::sqrt(dx * dx + dy * dy);

        // Estimate the number of steps (round up to ensure full coverage)
        int steps = static_cast<int>(std::ceil(linear_distance / (v_max * dt)));

        // Ensure at least one step
        return std::max(steps, 1);
    }
    void TrajectoryGeneratorNode::publishTrajectoryMarkers(const TrajectoryMsg &trajectory, const StateMsg &start_state, const StateMsg &goal_state)
    {
        visualization_msgs::msg::MarkerArray marker_array;

        visualization_msgs::msg::Marker clear_all;
        clear_all.action = visualization_msgs::msg::Marker::DELETEALL;
        clear_all.header.frame_id = "map";
        clear_all.header.stamp = this->now();
        marker_array.markers.push_back(clear_all);


        int id = 0;
        for (const auto &state : trajectory.states)
        {
            // Base pose
            geometry_msgs::msg::Point origin;
            origin.x = state.x;
            origin.y = state.y;
            origin.z = 0.0;

            // Orientation quaternion for theta (vehicle heading)
            tf2::Quaternion q_theta;
            q_theta.setRPY(0, 0, state.theta);

            // Green arrow (vehicle heading)
            visualization_msgs::msg::Marker heading_marker;
            heading_marker.header.frame_id = "map";
            heading_marker.header.stamp = this->now();
            heading_marker.ns = "vehicle_heading";
            heading_marker.id = id++;
            heading_marker.type = visualization_msgs::msg::Marker::ARROW;
            heading_marker.action = visualization_msgs::msg::Marker::ADD;
            heading_marker.pose.position = origin;
            heading_marker.pose.orientation = tf2::toMsg(q_theta);
            heading_marker.scale.x = 0.6; // arrow length
            heading_marker.scale.y = 0.15;
            heading_marker.scale.z = 0.15;
            heading_marker.color.r = 0.0f;
            heading_marker.color.g = 1.0f;
            heading_marker.color.b = 0.0f;
            heading_marker.color.a = 1.0f;
            heading_marker.lifetime = rclcpp::Duration::from_seconds(0.0); // persistent
            marker_array.markers.push_back(heading_marker);

            // Orientation quaternion for (theta + phi)
            tf2::Quaternion q_steering;
            q_steering.setRPY(0, 0, state.theta + state.phi); // Combine heading and steering angle

            // Blue arrow (steering direction)
            visualization_msgs::msg::Marker steering_marker = heading_marker;
            steering_marker.ns = "steering_direction";
            steering_marker.id = id++;
            steering_marker.pose.orientation = tf2::toMsg(q_steering);
            steering_marker.scale.x = 0.3; // shorter arrow
            steering_marker.color.r = 0.0f;
            steering_marker.color.g = 0.0f;
            steering_marker.color.b = 1.0f;
            steering_marker.color.a = 1.0f;

            marker_array.markers.push_back(steering_marker);
        }
        // Helper to create an arrow marker
        auto createArrowMarker = [&](const StateMsg &state, const std::string &ns, int id,
                                     float r, float g, float b) -> visualization_msgs::msg::Marker
        {
            tf2::Quaternion q;
            q.setRPY(0, 0, state.theta);

            visualization_msgs::msg::Marker marker;
            marker.header.frame_id = "map";
            marker.header.stamp = this->now();
            marker.ns = ns;
            marker.id = id;
            marker.type = visualization_msgs::msg::Marker::ARROW;
            marker.action = visualization_msgs::msg::Marker::ADD;
            marker.pose.position.x = state.x;
            marker.pose.position.y = state.y;
            marker.pose.position.z = 0.0;
            marker.pose.orientation = tf2::toMsg(q);
            marker.scale.x = 0.7; // arrow length
            marker.scale.y = 0.2;
            marker.scale.z = 0.2;
            marker.color.r = r;
            marker.color.g = g;
            marker.color.b = b;
            marker.color.a = 1.0;
            marker.lifetime = rclcpp::Duration::from_seconds(0.0);
            return marker;
        };

        // Add start (yellow) and goal (red) markers
        marker_array.markers.push_back(createArrowMarker(start_state, "start_state", id++, 1.0f, 1.0f, 0.0f));
        marker_array.markers.push_back(createArrowMarker(goal_state, "goal_state", id++, 1.0f, 0.0f, 0.0f));

        trajectory_marker_pub_->publish(marker_array);
    }
