#pragma once

#include <rclcpp/rclcpp.hpp>

#include <tri_gen_msgs/msg/control.hpp>
#include <tri_gen_msgs/msg/state.hpp>
#include <tri_gen_msgs/msg/trajectory.hpp>
#include <tri_gen_msgs/srv/generate_trajectory.hpp>

#include "tri_gen_trajectry_generator/trajectory_generator.hpp"
#include "tri_gen_trajectry_generator/utils.hpp"

#include <visualization_msgs/msg/marker_array.hpp>
#include <geometry_msgs/msg/point.hpp>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>

/**
 * @brief ROS 2 node for tricycle vehicle trajectory generation.
 *
 * Exposes a service to generate a trajectory from a start to a goal state using nonlinear optimization.
 * Publishes the generated trajectory and visual markers for RViz.
 */
class TrajectoryGeneratorNode : public rclcpp::Node
{
public:
    using ControlMsg = tri_gen_msgs::msg::Control;
    using StateMsg = tri_gen_msgs::msg::State;
    using TrajectoryMsg = tri_gen_msgs::msg::Trajectory;
    using GenerateTrajectorySrv = tri_gen_msgs::srv::GenerateTrajectory;

    /**
     * @brief Constructor that initializes the node, service, and publishers.
     */
    TrajectoryGeneratorNode();

private:
    /// Callback group for sequential handling of trajectory generation requests.
    rclcpp::CallbackGroup::SharedPtr callback_group_;

    /// ROS2 service for receiving trajectory generation requests.
    rclcpp::Service<GenerateTrajectorySrv>::SharedPtr generate_trajectory_service_;

    /// Publisher for broadcasting generated trajectories.
    rclcpp::Publisher<TrajectoryMsg>::SharedPtr trajectory_publisher_;

    /**
     * @brief Callback executed upon receiving a trajectory generation request.
     *
     * This function handles converting messages, invoking the NLP solver, and returning the result.
     *
     * @param request The incoming request containing start, goal, and constraints.
     * @param response The response object that will be populated with the result trajectory.
     */
    void generateTrajectoryCb(
        const std::shared_ptr<GenerateTrajectorySrv::Request> request,
        std::shared_ptr<GenerateTrajectorySrv::Response> response);

    /**
     * @brief Verifies that the requested constraints are valid and within solver limits.
     * @param request The incoming service request.
     * @return True if constraints are valid, false otherwise.
     */
    bool verifyConstraints(const std::shared_ptr<GenerateTrajectorySrv::Request> request) const;

    /**
     * @brief Estimates how many optimization steps (N) are needed between start and goal.
     *
     * This helps adjust the NLP horizon dynamically based on distance and speed.
     *
     * @param start Start state.
     * @param goal Goal state.
     * @param dt Time step.
     * @param v_max Maximum velocity.
     * @return Estimated number of steps.
     */
    int estimateNumberOfOptimizationSteps(const StateMsg &start, const StateMsg &goal, double dt, double speed, double acceleration, double steering_rate, double max_steering) const;

    /**
     * @brief Publishes visualization markers for the trajectory, start, and goal poses.
     * @param trajectory The computed trajectory.
     * @param start_state Start state of the vehicle.
     * @param goal_state Desired target state.
     */
    void publishTrajectoryMarkers(const TrajectoryMsg &trajectory, const StateMsg &start_state, const StateMsg &goal_state);

    double wheelbase_;

    /// Pointer to the underlying NLP-based trajectory generator.
    std::shared_ptr<NLPTrajectoryGeneratorBase> trajectory_generator_p_;

    /// Publisher for RViz visualization of the trajectory as markers.
    rclcpp::Publisher<visualization_msgs::msg::MarkerArray>::SharedPtr trajectory_marker_pub_;
};
