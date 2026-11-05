// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tri_gen_msgs:srv/GenerateTrajectory.idl
// generated code does not contain a copyright notice

#ifndef TRI_GEN_MSGS__SRV__DETAIL__GENERATE_TRAJECTORY__BUILDER_HPP_
#define TRI_GEN_MSGS__SRV__DETAIL__GENERATE_TRAJECTORY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tri_gen_msgs/srv/detail/generate_trajectory__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tri_gen_msgs
{

namespace srv
{

namespace builder
{

class Init_GenerateTrajectory_Request_a_max
{
public:
  explicit Init_GenerateTrajectory_Request_a_max(::tri_gen_msgs::srv::GenerateTrajectory_Request & msg)
  : msg_(msg)
  {}
  ::tri_gen_msgs::srv::GenerateTrajectory_Request a_max(::tri_gen_msgs::srv::GenerateTrajectory_Request::_a_max_type arg)
  {
    msg_.a_max = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tri_gen_msgs::srv::GenerateTrajectory_Request msg_;
};

class Init_GenerateTrajectory_Request_a_min
{
public:
  explicit Init_GenerateTrajectory_Request_a_min(::tri_gen_msgs::srv::GenerateTrajectory_Request & msg)
  : msg_(msg)
  {}
  Init_GenerateTrajectory_Request_a_max a_min(::tri_gen_msgs::srv::GenerateTrajectory_Request::_a_min_type arg)
  {
    msg_.a_min = std::move(arg);
    return Init_GenerateTrajectory_Request_a_max(msg_);
  }

private:
  ::tri_gen_msgs::srv::GenerateTrajectory_Request msg_;
};

class Init_GenerateTrajectory_Request_v_max
{
public:
  explicit Init_GenerateTrajectory_Request_v_max(::tri_gen_msgs::srv::GenerateTrajectory_Request & msg)
  : msg_(msg)
  {}
  Init_GenerateTrajectory_Request_a_min v_max(::tri_gen_msgs::srv::GenerateTrajectory_Request::_v_max_type arg)
  {
    msg_.v_max = std::move(arg);
    return Init_GenerateTrajectory_Request_a_min(msg_);
  }

private:
  ::tri_gen_msgs::srv::GenerateTrajectory_Request msg_;
};

class Init_GenerateTrajectory_Request_v_min
{
public:
  explicit Init_GenerateTrajectory_Request_v_min(::tri_gen_msgs::srv::GenerateTrajectory_Request & msg)
  : msg_(msg)
  {}
  Init_GenerateTrajectory_Request_v_max v_min(::tri_gen_msgs::srv::GenerateTrajectory_Request::_v_min_type arg)
  {
    msg_.v_min = std::move(arg);
    return Init_GenerateTrajectory_Request_v_max(msg_);
  }

private:
  ::tri_gen_msgs::srv::GenerateTrajectory_Request msg_;
};

class Init_GenerateTrajectory_Request_omega_phi_max
{
public:
  explicit Init_GenerateTrajectory_Request_omega_phi_max(::tri_gen_msgs::srv::GenerateTrajectory_Request & msg)
  : msg_(msg)
  {}
  Init_GenerateTrajectory_Request_v_min omega_phi_max(::tri_gen_msgs::srv::GenerateTrajectory_Request::_omega_phi_max_type arg)
  {
    msg_.omega_phi_max = std::move(arg);
    return Init_GenerateTrajectory_Request_v_min(msg_);
  }

private:
  ::tri_gen_msgs::srv::GenerateTrajectory_Request msg_;
};

class Init_GenerateTrajectory_Request_omega_phi_min
{
public:
  explicit Init_GenerateTrajectory_Request_omega_phi_min(::tri_gen_msgs::srv::GenerateTrajectory_Request & msg)
  : msg_(msg)
  {}
  Init_GenerateTrajectory_Request_omega_phi_max omega_phi_min(::tri_gen_msgs::srv::GenerateTrajectory_Request::_omega_phi_min_type arg)
  {
    msg_.omega_phi_min = std::move(arg);
    return Init_GenerateTrajectory_Request_omega_phi_max(msg_);
  }

private:
  ::tri_gen_msgs::srv::GenerateTrajectory_Request msg_;
};

class Init_GenerateTrajectory_Request_phi_max
{
public:
  explicit Init_GenerateTrajectory_Request_phi_max(::tri_gen_msgs::srv::GenerateTrajectory_Request & msg)
  : msg_(msg)
  {}
  Init_GenerateTrajectory_Request_omega_phi_min phi_max(::tri_gen_msgs::srv::GenerateTrajectory_Request::_phi_max_type arg)
  {
    msg_.phi_max = std::move(arg);
    return Init_GenerateTrajectory_Request_omega_phi_min(msg_);
  }

private:
  ::tri_gen_msgs::srv::GenerateTrajectory_Request msg_;
};

class Init_GenerateTrajectory_Request_phi_min
{
public:
  explicit Init_GenerateTrajectory_Request_phi_min(::tri_gen_msgs::srv::GenerateTrajectory_Request & msg)
  : msg_(msg)
  {}
  Init_GenerateTrajectory_Request_phi_max phi_min(::tri_gen_msgs::srv::GenerateTrajectory_Request::_phi_min_type arg)
  {
    msg_.phi_min = std::move(arg);
    return Init_GenerateTrajectory_Request_phi_max(msg_);
  }

private:
  ::tri_gen_msgs::srv::GenerateTrajectory_Request msg_;
};

class Init_GenerateTrajectory_Request_dt
{
public:
  explicit Init_GenerateTrajectory_Request_dt(::tri_gen_msgs::srv::GenerateTrajectory_Request & msg)
  : msg_(msg)
  {}
  Init_GenerateTrajectory_Request_phi_min dt(::tri_gen_msgs::srv::GenerateTrajectory_Request::_dt_type arg)
  {
    msg_.dt = std::move(arg);
    return Init_GenerateTrajectory_Request_phi_min(msg_);
  }

private:
  ::tri_gen_msgs::srv::GenerateTrajectory_Request msg_;
};

class Init_GenerateTrajectory_Request_goal
{
public:
  explicit Init_GenerateTrajectory_Request_goal(::tri_gen_msgs::srv::GenerateTrajectory_Request & msg)
  : msg_(msg)
  {}
  Init_GenerateTrajectory_Request_dt goal(::tri_gen_msgs::srv::GenerateTrajectory_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return Init_GenerateTrajectory_Request_dt(msg_);
  }

private:
  ::tri_gen_msgs::srv::GenerateTrajectory_Request msg_;
};

class Init_GenerateTrajectory_Request_start
{
public:
  Init_GenerateTrajectory_Request_start()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GenerateTrajectory_Request_goal start(::tri_gen_msgs::srv::GenerateTrajectory_Request::_start_type arg)
  {
    msg_.start = std::move(arg);
    return Init_GenerateTrajectory_Request_goal(msg_);
  }

private:
  ::tri_gen_msgs::srv::GenerateTrajectory_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tri_gen_msgs::srv::GenerateTrajectory_Request>()
{
  return tri_gen_msgs::srv::builder::Init_GenerateTrajectory_Request_start();
}

}  // namespace tri_gen_msgs


namespace tri_gen_msgs
{

namespace srv
{

namespace builder
{

class Init_GenerateTrajectory_Response_message
{
public:
  explicit Init_GenerateTrajectory_Response_message(::tri_gen_msgs::srv::GenerateTrajectory_Response & msg)
  : msg_(msg)
  {}
  ::tri_gen_msgs::srv::GenerateTrajectory_Response message(::tri_gen_msgs::srv::GenerateTrajectory_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tri_gen_msgs::srv::GenerateTrajectory_Response msg_;
};

class Init_GenerateTrajectory_Response_success
{
public:
  explicit Init_GenerateTrajectory_Response_success(::tri_gen_msgs::srv::GenerateTrajectory_Response & msg)
  : msg_(msg)
  {}
  Init_GenerateTrajectory_Response_message success(::tri_gen_msgs::srv::GenerateTrajectory_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_GenerateTrajectory_Response_message(msg_);
  }

private:
  ::tri_gen_msgs::srv::GenerateTrajectory_Response msg_;
};

class Init_GenerateTrajectory_Response_generation_time_ms
{
public:
  explicit Init_GenerateTrajectory_Response_generation_time_ms(::tri_gen_msgs::srv::GenerateTrajectory_Response & msg)
  : msg_(msg)
  {}
  Init_GenerateTrajectory_Response_success generation_time_ms(::tri_gen_msgs::srv::GenerateTrajectory_Response::_generation_time_ms_type arg)
  {
    msg_.generation_time_ms = std::move(arg);
    return Init_GenerateTrajectory_Response_success(msg_);
  }

private:
  ::tri_gen_msgs::srv::GenerateTrajectory_Response msg_;
};

class Init_GenerateTrajectory_Response_max_curvature
{
public:
  explicit Init_GenerateTrajectory_Response_max_curvature(::tri_gen_msgs::srv::GenerateTrajectory_Response & msg)
  : msg_(msg)
  {}
  Init_GenerateTrajectory_Response_generation_time_ms max_curvature(::tri_gen_msgs::srv::GenerateTrajectory_Response::_max_curvature_type arg)
  {
    msg_.max_curvature = std::move(arg);
    return Init_GenerateTrajectory_Response_generation_time_ms(msg_);
  }

private:
  ::tri_gen_msgs::srv::GenerateTrajectory_Response msg_;
};

class Init_GenerateTrajectory_Response_max_velocity
{
public:
  explicit Init_GenerateTrajectory_Response_max_velocity(::tri_gen_msgs::srv::GenerateTrajectory_Response & msg)
  : msg_(msg)
  {}
  Init_GenerateTrajectory_Response_max_curvature max_velocity(::tri_gen_msgs::srv::GenerateTrajectory_Response::_max_velocity_type arg)
  {
    msg_.max_velocity = std::move(arg);
    return Init_GenerateTrajectory_Response_max_curvature(msg_);
  }

private:
  ::tri_gen_msgs::srv::GenerateTrajectory_Response msg_;
};

class Init_GenerateTrajectory_Response_total_length
{
public:
  explicit Init_GenerateTrajectory_Response_total_length(::tri_gen_msgs::srv::GenerateTrajectory_Response & msg)
  : msg_(msg)
  {}
  Init_GenerateTrajectory_Response_max_velocity total_length(::tri_gen_msgs::srv::GenerateTrajectory_Response::_total_length_type arg)
  {
    msg_.total_length = std::move(arg);
    return Init_GenerateTrajectory_Response_max_velocity(msg_);
  }

private:
  ::tri_gen_msgs::srv::GenerateTrajectory_Response msg_;
};

class Init_GenerateTrajectory_Response_trajectory
{
public:
  Init_GenerateTrajectory_Response_trajectory()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GenerateTrajectory_Response_total_length trajectory(::tri_gen_msgs::srv::GenerateTrajectory_Response::_trajectory_type arg)
  {
    msg_.trajectory = std::move(arg);
    return Init_GenerateTrajectory_Response_total_length(msg_);
  }

private:
  ::tri_gen_msgs::srv::GenerateTrajectory_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tri_gen_msgs::srv::GenerateTrajectory_Response>()
{
  return tri_gen_msgs::srv::builder::Init_GenerateTrajectory_Response_trajectory();
}

}  // namespace tri_gen_msgs

#endif  // TRI_GEN_MSGS__SRV__DETAIL__GENERATE_TRAJECTORY__BUILDER_HPP_
