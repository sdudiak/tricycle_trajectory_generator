// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tri_gen_msgs:msg/State.idl
// generated code does not contain a copyright notice

#ifndef TRI_GEN_MSGS__MSG__DETAIL__STATE__TRAITS_HPP_
#define TRI_GEN_MSGS__MSG__DETAIL__STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "tri_gen_msgs/msg/detail/state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'stamp_from_start'
#include "builtin_interfaces/msg/detail/duration__traits.hpp"

namespace tri_gen_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const State & msg,
  std::ostream & out)
{
  out << "{";
  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: theta
  {
    out << "theta: ";
    rosidl_generator_traits::value_to_yaml(msg.theta, out);
    out << ", ";
  }

  // member: phi
  {
    out << "phi: ";
    rosidl_generator_traits::value_to_yaml(msg.phi, out);
    out << ", ";
  }

  // member: omega_phi
  {
    out << "omega_phi: ";
    rosidl_generator_traits::value_to_yaml(msg.omega_phi, out);
    out << ", ";
  }

  // member: v
  {
    out << "v: ";
    rosidl_generator_traits::value_to_yaml(msg.v, out);
    out << ", ";
  }

  // member: stamp_from_start
  {
    out << "stamp_from_start: ";
    to_flow_style_yaml(msg.stamp_from_start, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const State & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: theta
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "theta: ";
    rosidl_generator_traits::value_to_yaml(msg.theta, out);
    out << "\n";
  }

  // member: phi
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "phi: ";
    rosidl_generator_traits::value_to_yaml(msg.phi, out);
    out << "\n";
  }

  // member: omega_phi
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "omega_phi: ";
    rosidl_generator_traits::value_to_yaml(msg.omega_phi, out);
    out << "\n";
  }

  // member: v
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "v: ";
    rosidl_generator_traits::value_to_yaml(msg.v, out);
    out << "\n";
  }

  // member: stamp_from_start
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp_from_start:\n";
    to_block_style_yaml(msg.stamp_from_start, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const State & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace tri_gen_msgs

namespace rosidl_generator_traits
{

[[deprecated("use tri_gen_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tri_gen_msgs::msg::State & msg,
  std::ostream & out, size_t indentation = 0)
{
  tri_gen_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tri_gen_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const tri_gen_msgs::msg::State & msg)
{
  return tri_gen_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<tri_gen_msgs::msg::State>()
{
  return "tri_gen_msgs::msg::State";
}

template<>
inline const char * name<tri_gen_msgs::msg::State>()
{
  return "tri_gen_msgs/msg/State";
}

template<>
struct has_fixed_size<tri_gen_msgs::msg::State>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Duration>::value> {};

template<>
struct has_bounded_size<tri_gen_msgs::msg::State>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Duration>::value> {};

template<>
struct is_message<tri_gen_msgs::msg::State>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TRI_GEN_MSGS__MSG__DETAIL__STATE__TRAITS_HPP_
