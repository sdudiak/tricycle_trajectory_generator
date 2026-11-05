// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from tri_gen_msgs:msg/Trajectory.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "tri_gen_msgs/msg/detail/trajectory__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace tri_gen_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Trajectory_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) tri_gen_msgs::msg::Trajectory(_init);
}

void Trajectory_fini_function(void * message_memory)
{
  auto typed_message = static_cast<tri_gen_msgs::msg::Trajectory *>(message_memory);
  typed_message->~Trajectory();
}

size_t size_function__Trajectory__states(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<tri_gen_msgs::msg::State> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Trajectory__states(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<tri_gen_msgs::msg::State> *>(untyped_member);
  return &member[index];
}

void * get_function__Trajectory__states(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<tri_gen_msgs::msg::State> *>(untyped_member);
  return &member[index];
}

void fetch_function__Trajectory__states(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const tri_gen_msgs::msg::State *>(
    get_const_function__Trajectory__states(untyped_member, index));
  auto & value = *reinterpret_cast<tri_gen_msgs::msg::State *>(untyped_value);
  value = item;
}

void assign_function__Trajectory__states(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<tri_gen_msgs::msg::State *>(
    get_function__Trajectory__states(untyped_member, index));
  const auto & value = *reinterpret_cast<const tri_gen_msgs::msg::State *>(untyped_value);
  item = value;
}

void resize_function__Trajectory__states(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<tri_gen_msgs::msg::State> *>(untyped_member);
  member->resize(size);
}

size_t size_function__Trajectory__controls(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<tri_gen_msgs::msg::Control> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Trajectory__controls(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<tri_gen_msgs::msg::Control> *>(untyped_member);
  return &member[index];
}

void * get_function__Trajectory__controls(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<tri_gen_msgs::msg::Control> *>(untyped_member);
  return &member[index];
}

void fetch_function__Trajectory__controls(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const tri_gen_msgs::msg::Control *>(
    get_const_function__Trajectory__controls(untyped_member, index));
  auto & value = *reinterpret_cast<tri_gen_msgs::msg::Control *>(untyped_value);
  value = item;
}

void assign_function__Trajectory__controls(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<tri_gen_msgs::msg::Control *>(
    get_function__Trajectory__controls(untyped_member, index));
  const auto & value = *reinterpret_cast<const tri_gen_msgs::msg::Control *>(untyped_value);
  item = value;
}

void resize_function__Trajectory__controls(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<tri_gen_msgs::msg::Control> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Trajectory_message_member_array[2] = {
  {
    "states",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<tri_gen_msgs::msg::State>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tri_gen_msgs::msg::Trajectory, states),  // bytes offset in struct
    nullptr,  // default value
    size_function__Trajectory__states,  // size() function pointer
    get_const_function__Trajectory__states,  // get_const(index) function pointer
    get_function__Trajectory__states,  // get(index) function pointer
    fetch_function__Trajectory__states,  // fetch(index, &value) function pointer
    assign_function__Trajectory__states,  // assign(index, value) function pointer
    resize_function__Trajectory__states  // resize(index) function pointer
  },
  {
    "controls",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<tri_gen_msgs::msg::Control>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tri_gen_msgs::msg::Trajectory, controls),  // bytes offset in struct
    nullptr,  // default value
    size_function__Trajectory__controls,  // size() function pointer
    get_const_function__Trajectory__controls,  // get_const(index) function pointer
    get_function__Trajectory__controls,  // get(index) function pointer
    fetch_function__Trajectory__controls,  // fetch(index, &value) function pointer
    assign_function__Trajectory__controls,  // assign(index, value) function pointer
    resize_function__Trajectory__controls  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Trajectory_message_members = {
  "tri_gen_msgs::msg",  // message namespace
  "Trajectory",  // message name
  2,  // number of fields
  sizeof(tri_gen_msgs::msg::Trajectory),
  Trajectory_message_member_array,  // message members
  Trajectory_init_function,  // function to initialize message memory (memory has to be allocated)
  Trajectory_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Trajectory_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Trajectory_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace tri_gen_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<tri_gen_msgs::msg::Trajectory>()
{
  return &::tri_gen_msgs::msg::rosidl_typesupport_introspection_cpp::Trajectory_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tri_gen_msgs, msg, Trajectory)() {
  return &::tri_gen_msgs::msg::rosidl_typesupport_introspection_cpp::Trajectory_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
