// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tri_gen_msgs:srv/GenerateTrajectory.idl
// generated code does not contain a copyright notice

#ifndef TRI_GEN_MSGS__SRV__DETAIL__GENERATE_TRAJECTORY__TRAITS_HPP_
#define TRI_GEN_MSGS__SRV__DETAIL__GENERATE_TRAJECTORY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "tri_gen_msgs/srv/detail/generate_trajectory__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'start'
// Member 'goal'
#include "tri_gen_msgs/msg/detail/state__traits.hpp"

namespace tri_gen_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GenerateTrajectory_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: start
  {
    out << "start: ";
    to_flow_style_yaml(msg.start, out);
    out << ", ";
  }

  // member: goal
  {
    out << "goal: ";
    to_flow_style_yaml(msg.goal, out);
    out << ", ";
  }

  // member: dt
  {
    out << "dt: ";
    rosidl_generator_traits::value_to_yaml(msg.dt, out);
    out << ", ";
  }

  // member: phi_min
  {
    out << "phi_min: ";
    rosidl_generator_traits::value_to_yaml(msg.phi_min, out);
    out << ", ";
  }

  // member: phi_max
  {
    out << "phi_max: ";
    rosidl_generator_traits::value_to_yaml(msg.phi_max, out);
    out << ", ";
  }

  // member: omega_phi_min
  {
    out << "omega_phi_min: ";
    rosidl_generator_traits::value_to_yaml(msg.omega_phi_min, out);
    out << ", ";
  }

  // member: omega_phi_max
  {
    out << "omega_phi_max: ";
    rosidl_generator_traits::value_to_yaml(msg.omega_phi_max, out);
    out << ", ";
  }

  // member: v_min
  {
    out << "v_min: ";
    rosidl_generator_traits::value_to_yaml(msg.v_min, out);
    out << ", ";
  }

  // member: v_max
  {
    out << "v_max: ";
    rosidl_generator_traits::value_to_yaml(msg.v_max, out);
    out << ", ";
  }

  // member: a_min
  {
    out << "a_min: ";
    rosidl_generator_traits::value_to_yaml(msg.a_min, out);
    out << ", ";
  }

  // member: a_max
  {
    out << "a_max: ";
    rosidl_generator_traits::value_to_yaml(msg.a_max, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GenerateTrajectory_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: start
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "start:\n";
    to_block_style_yaml(msg.start, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_block_style_yaml(msg.goal, out, indentation + 2);
  }

  // member: dt
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dt: ";
    rosidl_generator_traits::value_to_yaml(msg.dt, out);
    out << "\n";
  }

  // member: phi_min
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "phi_min: ";
    rosidl_generator_traits::value_to_yaml(msg.phi_min, out);
    out << "\n";
  }

  // member: phi_max
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "phi_max: ";
    rosidl_generator_traits::value_to_yaml(msg.phi_max, out);
    out << "\n";
  }

  // member: omega_phi_min
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "omega_phi_min: ";
    rosidl_generator_traits::value_to_yaml(msg.omega_phi_min, out);
    out << "\n";
  }

  // member: omega_phi_max
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "omega_phi_max: ";
    rosidl_generator_traits::value_to_yaml(msg.omega_phi_max, out);
    out << "\n";
  }

  // member: v_min
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "v_min: ";
    rosidl_generator_traits::value_to_yaml(msg.v_min, out);
    out << "\n";
  }

  // member: v_max
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "v_max: ";
    rosidl_generator_traits::value_to_yaml(msg.v_max, out);
    out << "\n";
  }

  // member: a_min
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "a_min: ";
    rosidl_generator_traits::value_to_yaml(msg.a_min, out);
    out << "\n";
  }

  // member: a_max
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "a_max: ";
    rosidl_generator_traits::value_to_yaml(msg.a_max, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GenerateTrajectory_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace tri_gen_msgs

namespace rosidl_generator_traits
{

[[deprecated("use tri_gen_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tri_gen_msgs::srv::GenerateTrajectory_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  tri_gen_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tri_gen_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const tri_gen_msgs::srv::GenerateTrajectory_Request & msg)
{
  return tri_gen_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<tri_gen_msgs::srv::GenerateTrajectory_Request>()
{
  return "tri_gen_msgs::srv::GenerateTrajectory_Request";
}

template<>
inline const char * name<tri_gen_msgs::srv::GenerateTrajectory_Request>()
{
  return "tri_gen_msgs/srv/GenerateTrajectory_Request";
}

template<>
struct has_fixed_size<tri_gen_msgs::srv::GenerateTrajectory_Request>
  : std::integral_constant<bool, has_fixed_size<tri_gen_msgs::msg::State>::value> {};

template<>
struct has_bounded_size<tri_gen_msgs::srv::GenerateTrajectory_Request>
  : std::integral_constant<bool, has_bounded_size<tri_gen_msgs::msg::State>::value> {};

template<>
struct is_message<tri_gen_msgs::srv::GenerateTrajectory_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'trajectory'
#include "tri_gen_msgs/msg/detail/trajectory__traits.hpp"

namespace tri_gen_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GenerateTrajectory_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: trajectory
  {
    out << "trajectory: ";
    to_flow_style_yaml(msg.trajectory, out);
    out << ", ";
  }

  // member: total_length
  {
    out << "total_length: ";
    rosidl_generator_traits::value_to_yaml(msg.total_length, out);
    out << ", ";
  }

  // member: max_velocity
  {
    out << "max_velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.max_velocity, out);
    out << ", ";
  }

  // member: max_curvature
  {
    out << "max_curvature: ";
    rosidl_generator_traits::value_to_yaml(msg.max_curvature, out);
    out << ", ";
  }

  // member: generation_time_ms
  {
    out << "generation_time_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.generation_time_ms, out);
    out << ", ";
  }

  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GenerateTrajectory_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: trajectory
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "trajectory:\n";
    to_block_style_yaml(msg.trajectory, out, indentation + 2);
  }

  // member: total_length
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "total_length: ";
    rosidl_generator_traits::value_to_yaml(msg.total_length, out);
    out << "\n";
  }

  // member: max_velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.max_velocity, out);
    out << "\n";
  }

  // member: max_curvature
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_curvature: ";
    rosidl_generator_traits::value_to_yaml(msg.max_curvature, out);
    out << "\n";
  }

  // member: generation_time_ms
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "generation_time_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.generation_time_ms, out);
    out << "\n";
  }

  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GenerateTrajectory_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace tri_gen_msgs

namespace rosidl_generator_traits
{

[[deprecated("use tri_gen_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tri_gen_msgs::srv::GenerateTrajectory_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  tri_gen_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tri_gen_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const tri_gen_msgs::srv::GenerateTrajectory_Response & msg)
{
  return tri_gen_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<tri_gen_msgs::srv::GenerateTrajectory_Response>()
{
  return "tri_gen_msgs::srv::GenerateTrajectory_Response";
}

template<>
inline const char * name<tri_gen_msgs::srv::GenerateTrajectory_Response>()
{
  return "tri_gen_msgs/srv/GenerateTrajectory_Response";
}

template<>
struct has_fixed_size<tri_gen_msgs::srv::GenerateTrajectory_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tri_gen_msgs::srv::GenerateTrajectory_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<tri_gen_msgs::srv::GenerateTrajectory_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<tri_gen_msgs::srv::GenerateTrajectory>()
{
  return "tri_gen_msgs::srv::GenerateTrajectory";
}

template<>
inline const char * name<tri_gen_msgs::srv::GenerateTrajectory>()
{
  return "tri_gen_msgs/srv/GenerateTrajectory";
}

template<>
struct has_fixed_size<tri_gen_msgs::srv::GenerateTrajectory>
  : std::integral_constant<
    bool,
    has_fixed_size<tri_gen_msgs::srv::GenerateTrajectory_Request>::value &&
    has_fixed_size<tri_gen_msgs::srv::GenerateTrajectory_Response>::value
  >
{
};

template<>
struct has_bounded_size<tri_gen_msgs::srv::GenerateTrajectory>
  : std::integral_constant<
    bool,
    has_bounded_size<tri_gen_msgs::srv::GenerateTrajectory_Request>::value &&
    has_bounded_size<tri_gen_msgs::srv::GenerateTrajectory_Response>::value
  >
{
};

template<>
struct is_service<tri_gen_msgs::srv::GenerateTrajectory>
  : std::true_type
{
};

template<>
struct is_service_request<tri_gen_msgs::srv::GenerateTrajectory_Request>
  : std::true_type
{
};

template<>
struct is_service_response<tri_gen_msgs::srv::GenerateTrajectory_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // TRI_GEN_MSGS__SRV__DETAIL__GENERATE_TRAJECTORY__TRAITS_HPP_
