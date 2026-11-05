// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tri_gen_msgs:msg/Trajectory.idl
// generated code does not contain a copyright notice

#ifndef TRI_GEN_MSGS__MSG__DETAIL__TRAJECTORY__BUILDER_HPP_
#define TRI_GEN_MSGS__MSG__DETAIL__TRAJECTORY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tri_gen_msgs/msg/detail/trajectory__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tri_gen_msgs
{

namespace msg
{

namespace builder
{

class Init_Trajectory_controls
{
public:
  explicit Init_Trajectory_controls(::tri_gen_msgs::msg::Trajectory & msg)
  : msg_(msg)
  {}
  ::tri_gen_msgs::msg::Trajectory controls(::tri_gen_msgs::msg::Trajectory::_controls_type arg)
  {
    msg_.controls = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tri_gen_msgs::msg::Trajectory msg_;
};

class Init_Trajectory_states
{
public:
  Init_Trajectory_states()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Trajectory_controls states(::tri_gen_msgs::msg::Trajectory::_states_type arg)
  {
    msg_.states = std::move(arg);
    return Init_Trajectory_controls(msg_);
  }

private:
  ::tri_gen_msgs::msg::Trajectory msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tri_gen_msgs::msg::Trajectory>()
{
  return tri_gen_msgs::msg::builder::Init_Trajectory_states();
}

}  // namespace tri_gen_msgs

#endif  // TRI_GEN_MSGS__MSG__DETAIL__TRAJECTORY__BUILDER_HPP_
