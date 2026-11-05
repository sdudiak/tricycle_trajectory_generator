// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tri_gen_msgs:msg/Control.idl
// generated code does not contain a copyright notice

#ifndef TRI_GEN_MSGS__MSG__DETAIL__CONTROL__TRAITS_HPP_
#define TRI_GEN_MSGS__MSG__DETAIL__CONTROL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "tri_gen_msgs/msg/detail/control__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'duration'
#include "builtin_interfaces/msg/detail/duration__traits.hpp"

namespace tri_gen_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Control & msg,
  std::ostream & out)
{
  out << "{";
  // member: omega_phi
  {
    out << "omega_phi: ";
    rosidl_generator_traits::value_to_yaml(msg.omega_phi, out);
    out << ", ";
  }

  // member: a
  {
    out << "a: ";
    rosidl_generator_traits::value_to_yaml(msg.a, out);
    out << ", ";
  }

  // member: duration
  {
    out << "duration: ";
    to_flow_style_yaml(msg.duration, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Control & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: omega_phi
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "omega_phi: ";
    rosidl_generator_traits::value_to_yaml(msg.omega_phi, out);
    out << "\n";
  }

  // member: a
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "a: ";
    rosidl_generator_traits::value_to_yaml(msg.a, out);
    out << "\n";
  }

  // member: duration
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "duration:\n";
    to_block_style_yaml(msg.duration, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Control & msg, bool use_flow_style = false)
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
  const tri_gen_msgs::msg::Control & msg,
  std::ostream & out, size_t indentation = 0)
{
  tri_gen_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tri_gen_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const tri_gen_msgs::msg::Control & msg)
{
  return tri_gen_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<tri_gen_msgs::msg::Control>()
{
  return "tri_gen_msgs::msg::Control";
}

template<>
inline const char * name<tri_gen_msgs::msg::Control>()
{
  return "tri_gen_msgs/msg/Control";
}

template<>
struct has_fixed_size<tri_gen_msgs::msg::Control>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Duration>::value> {};

template<>
struct has_bounded_size<tri_gen_msgs::msg::Control>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Duration>::value> {};

template<>
struct is_message<tri_gen_msgs::msg::Control>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TRI_GEN_MSGS__MSG__DETAIL__CONTROL__TRAITS_HPP_
