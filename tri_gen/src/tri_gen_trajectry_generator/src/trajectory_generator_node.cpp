#include "tri_gen_trajectry_generator/trajectory_generator_node.hpp"
#include <algorithm>
#include <cmath>
#include <stdexcept>

TrajectoryGeneratorNode::TrajectoryGeneratorNode() : Node("trajectory_generator_node")
{
    callback_group_ = this->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);

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

    wheelbase_ = declare_parameter<double>("wheelbase", 1.3);
    trajectory_generator_p_ = std::make_shared<NLPTrajectoryGeneratorFixedDt>(wheelbase_);
    RCLCPP_INFO(get_logger(), "Trajectory Generator Node initialized");
}

void TrajectoryGeneratorNode::generateTrajectoryCb(
    const std::shared_ptr<GenerateTrajectorySrv::Request> request,
    std::shared_ptr<GenerateTrajectorySrv::Response> response)
    {
        RCLCPP_INFO(get_logger(), "Trajectory requested");
        response->success = false;
        if (!verifyConstraints(request))
        {
            response->message = "The passed constraints were incorrect";
            return;
        }

        int number_of_optimizer_steps;
        try {
            number_of_optimizer_steps = estimateNumberOfOptimizationSteps(
                request->start, request->goal, request->dt,
                std::max(std::abs(request->v_min), std::abs(request->v_max)),
                std::max(std::abs(request->a_min), std::abs(request->a_max)),
                std::max(std::abs(request->omega_phi_min), std::abs(request->omega_phi_max)),
                std::max(std::abs(request->phi_min), std::abs(request->phi_max)));
        } catch (const std::exception &e) {
            response->message = e.what();
            return;
        }

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
        trajectory_generator_p_->setHorizon(number_of_optimizer_steps);
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

        for (size_t i = 0; i < trajectory.states.size(); ++i) {
            const auto &state = trajectory.states[i];
            response->max_velocity = std::max(response->max_velocity, std::abs(state.v));
            // Curvature of the drive-wheel path: (theta_dot + phi_dot) / v.
            if (std::abs(state.v) > 1e-6) {
                response->max_curvature = std::max(response->max_curvature,
                    std::abs(std::sin(state.phi) / wheelbase_ + state.omega_phi / state.v));
            }
            if (i < trajectory.controls.size()) {
                const double next_v = trajectory.states[i + 1].v;
                const double sum = std::abs(state.v) + std::abs(next_v);
                response->total_length += state.v * next_v < 0.0 ?
                    request->dt * (state.v * state.v + next_v * next_v) / (2.0 * sum) :
                    request->dt * sum / 2.0;
            }
        }

        response->trajectory = trajectory;
        response->success = true;
        response->generation_time_ms = duration_ms;
        response->message = "Trajectory generated successfully";
        trajectory_publisher_->publish(trajectory);
        publishTrajectoryMarkers(trajectory, request->start, request->goal);
        RCLCPP_INFO(get_logger(), "Trajectory generated successfully");
    }


    bool TrajectoryGeneratorNode::verifyConstraints(const std::shared_ptr<GenerateTrajectorySrv::Request> request) const
    {
        for (double value : {request->dt, request->phi_min, request->phi_max,
                request->omega_phi_min, request->omega_phi_max, request->v_min,
                request->v_max, request->a_min, request->a_max}) {
            if (!std::isfinite(value)) return false;
        }
        if (request->dt <= 0.0) return false;
        for (const auto *state : {&request->start, &request->goal}) {
            for (double value : {state->x, state->y, state->theta, state->phi, state->v,
                                state->omega_phi}) {
                if (!std::isfinite(value)) return false;
            }
            if (state->phi < request->phi_min || state->phi > request->phi_max ||
                state->v < request->v_min || state->v > request->v_max) return false;
        }
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

    int TrajectoryGeneratorNode::estimateNumberOfOptimizationSteps(
        const StateMsg &start, const StateMsg &goal, double dt, double speed,
        double acceleration, double steering_rate, double max_steering) const
    {
        const double distance = std::hypot(goal.x - start.x, goal.y - start.y);
        const double heading = std::abs(std::atan2(std::sin(goal.theta - start.theta),
                                                  std::cos(goal.theta - start.theta)));
        const double yaw_rate = speed * std::sin(std::min(max_steering, M_PI / 2)) / wheelbase_;
        if (heading > 1e-6 && yaw_rate <= 0.0)
            throw std::invalid_argument("Heading change requires steering authority");
        // Conservative heuristic, not a feasibility guarantee for nonholonomic motion.
        const double duration = 2.0 * distance / speed + 2.0 * speed / acceleration +
            (heading > 1e-6 ? 2.0 * heading / yaw_rate : 0.0) +
            2.0 * max_steering / steering_rate;
        const double steps = std::max(20.0, std::ceil(duration / dt));
        if (!std::isfinite(steps) || steps > 1000)
            throw std::invalid_argument("Requested horizon exceeds the 1000-step limit");
        return static_cast<int>(steps);
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
