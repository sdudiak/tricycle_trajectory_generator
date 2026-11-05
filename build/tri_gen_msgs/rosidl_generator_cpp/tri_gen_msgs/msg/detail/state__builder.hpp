// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tri_gen_msgs:msg/State.idl
// generated code does not contain a copyright notice

#ifndef TRI_GEN_MSGS__MSG__DETAIL__STATE__BUILDER_HPP_
#define TRI_GEN_MSGS__MSG__DETAIL__STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tri_gen_msgs/msg/detail/state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tri_gen_msgs
{

namespace msg
{

namespace builder
{

class Init_State_stamp_from_start
{
public:
  explicit Init_State_stamp_from_start(::tri_gen_msgs::msg::State & msg)
  : msg_(msg)
  {}
  ::tri_gen_msgs::msg::State stamp_from_start(::tri_gen_msgs::msg::State::_stamp_from_start_type arg)
  {
    msg_.stamp_from_start = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tri_gen_msgs::msg::State msg_;
};

class Init_State_v
{
public:
  explicit Init_State_v(::tri_gen_msgs::msg::State & msg)
  : msg_(msg)
  {}
  Init_State_stamp_from_start v(::tri_gen_msgs::msg::State::_v_type arg)
  {
    msg_.v = std::move(arg);
    return Init_State_stamp_from_start(msg_);
  }

private:
  ::tri_gen_msgs::msg::State msg_;
};

class Init_State_omega_phi
{
public:
  explicit Init_State_omega_phi(::tri_gen_msgs::msg::State & msg)
  : msg_(msg)
  {}
  Init_State_v omega_phi(::tri_gen_msgs::msg::State::_omega_phi_type arg)
  {
    msg_.omega_phi = std::move(arg);
    return Init_State_v(msg_);
  }

private:
  ::tri_gen_msgs::msg::State msg_;
};

class Init_State_phi
{
public:
  explicit Init_State_phi(::tri_gen_msgs::msg::State & msg)
  : msg_(msg)
  {}
  Init_State_omega_phi phi(::tri_gen_msgs::msg::State::_phi_type arg)
  {
    msg_.phi = std::move(arg);
    return Init_State_omega_phi(msg_);
  }

private:
  ::tri_gen_msgs::msg::State msg_;
};

class Init_State_theta
{
public:
  explicit Init_State_theta(::tri_gen_msgs::msg::State & msg)
  : msg_(msg)
  {}
  Init_State_phi theta(::tri_gen_msgs::msg::State::_theta_type arg)
  {
    msg_.theta = std::move(arg);
    return Init_State_phi(msg_);
  }

private:
  ::tri_gen_msgs::msg::State msg_;
};

class Init_State_y
{
public:
  explicit Init_State_y(::tri_gen_msgs::msg::State & msg)
  : msg_(msg)
  {}
  Init_State_theta y(::tri_gen_msgs::msg::State::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_State_theta(msg_);
  }

private:
  ::tri_gen_msgs::msg::State msg_;
};

class Init_State_x
{
public:
  Init_State_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_State_y x(::tri_gen_msgs::msg::State::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_State_y(msg_);
  }

private:
  ::tri_gen_msgs::msg::State msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tri_gen_msgs::msg::State>()
{
  return tri_gen_msgs::msg::builder::Init_State_x();
}

}  // namespace tri_gen_msgs

#endif  // TRI_GEN_MSGS__MSG__DETAIL__STATE__BUILDER_HPP_
