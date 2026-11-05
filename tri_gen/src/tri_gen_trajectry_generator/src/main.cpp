#include <rclcpp/rclcpp.hpp>
#include "tri_gen_trajectry_generator/trajectory_generator_node.hpp"

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::executors::MultiThreadedExecutor executor;
    auto node = std::make_shared<TrajectoryGeneratorNode>();
    executor.add_node(node);
    executor.spin();
    rclcpp::shutdown();
    return 0;
}
