// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tri_gen_msgs:msg/Control.idl
// generated code does not contain a copyright notice

#ifndef TRI_GEN_MSGS__MSG__DETAIL__CONTROL__BUILDER_HPP_
#define TRI_GEN_MSGS__MSG__DETAIL__CONTROL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tri_gen_msgs/msg/detail/control__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tri_gen_msgs
{

namespace msg
{

namespace builder
{

class Init_Control_duration
{
public:
  explicit Init_Control_duration(::tri_gen_msgs::msg::Control & msg)
  : msg_(msg)
  {}
  ::tri_gen_msgs::msg::Control duration(::tri_gen_msgs::msg::Control::_duration_type arg)
  {
    msg_.duration = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tri_gen_msgs::msg::Control msg_;
};

class Init_Control_a
{
public:
  explicit Init_Control_a(::tri_gen_msgs::msg::Control & msg)
  : msg_(msg)
  {}
  Init_Control_duration a(::tri_gen_msgs::msg::Control::_a_type arg)
  {
    msg_.a = std::move(arg);
    return Init_Control_duration(msg_);
  }

private:
  ::tri_gen_msgs::msg::Control msg_;
};

class Init_Control_omega_phi
{
public:
  Init_Control_omega_phi()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Control_a omega_phi(::tri_gen_msgs::msg::Control::_omega_phi_type arg)
  {
    msg_.omega_phi = std::move(arg);
    return Init_Control_a(msg_);
  }

private:
  ::tri_gen_msgs::msg::Control msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tri_gen_msgs::msg::Control>()
{
  return tri_gen_msgs::msg::builder::Init_Control_omega_phi();
}

}  // namespace tri_gen_msgs

#endif  // TRI_GEN_MSGS__MSG__DETAIL__CONTROL__BUILDER_HPP_
