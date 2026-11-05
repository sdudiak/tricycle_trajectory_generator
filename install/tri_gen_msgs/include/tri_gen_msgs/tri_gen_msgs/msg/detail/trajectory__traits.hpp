// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tri_gen_msgs:msg/Trajectory.idl
// generated code does not contain a copyright notice

#ifndef TRI_GEN_MSGS__MSG__DETAIL__TRAJECTORY__TRAITS_HPP_
#define TRI_GEN_MSGS__MSG__DETAIL__TRAJECTORY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "tri_gen_msgs/msg/detail/trajectory__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'states'
#include "tri_gen_msgs/msg/detail/state__traits.hpp"
// Member 'controls'
#include "tri_gen_msgs/msg/detail/control__traits.hpp"

namespace tri_gen_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Trajectory & msg,
  std::ostream & out)
{
  out << "{";
  // member: states
  {
    if (msg.states.size() == 0) {
      out << "states: []";
    } else {
      out << "states: [";
      size_t pending_items = msg.states.size();
      for (auto item : msg.states) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: controls
  {
    if (msg.controls.size() == 0) {
      out << "controls: []";
    } else {
      out << "controls: [";
      size_t pending_items = msg.controls.size();
      for (auto item : msg.controls) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Trajectory & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: states
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.states.size() == 0) {
      out << "states: []\n";
    } else {
      out << "states:\n";
      for (auto item : msg.states) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: controls
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.controls.size() == 0) {
      out << "controls: []\n";
    } else {
      out << "controls:\n";
      for (auto item : msg.controls) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Trajectory & msg, bool use_flow_style = false)
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
  const tri_gen_msgs::msg::Trajectory & msg,
  std::ostream & out, size_t indentation = 0)
{
  tri_gen_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tri_gen_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const tri_gen_msgs::msg::Trajectory & msg)
{
  return tri_gen_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<tri_gen_msgs::msg::Trajectory>()
{
  return "tri_gen_msgs::msg::Trajectory";
}

template<>
inline const char * name<tri_gen_msgs::msg::Trajectory>()
{
  return "tri_gen_msgs/msg/Trajectory";
}

template<>
struct has_fixed_size<tri_gen_msgs::msg::Trajectory>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tri_gen_msgs::msg::Trajectory>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<tri_gen_msgs::msg::Trajectory>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TRI_GEN_MSGS__MSG__DETAIL__TRAJECTORY__TRAITS_HPP_
