// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from tri_gen_msgs:msg/Trajectory.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "tri_gen_msgs/msg/detail/trajectory__rosidl_typesupport_introspection_c.h"
#include "tri_gen_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "tri_gen_msgs/msg/detail/trajectory__functions.h"
#include "tri_gen_msgs/msg/detail/trajectory__struct.h"


// Include directives for member types
// Member `states`
#include "tri_gen_msgs/msg/state.h"
// Member `states`
#include "tri_gen_msgs/msg/detail/state__rosidl_typesupport_introspection_c.h"
// Member `controls`
#include "tri_gen_msgs/msg/control.h"
// Member `controls`
#include "tri_gen_msgs/msg/detail/control__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void tri_gen_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__Trajectory_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tri_gen_msgs__msg__Trajectory__init(message_memory);
}

void tri_gen_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__Trajectory_fini_function(void * message_memory)
{
  tri_gen_msgs__msg__Trajectory__fini(message_memory);
}

size_t tri_gen_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__size_function__Trajectory__states(
  const void * untyped_member)
{
  const tri_gen_msgs__msg__State__Sequence * member =
    (const tri_gen_msgs__msg__State__Sequence *)(untyped_member);
  return member->size;
}

const void * tri_gen_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__get_const_function__Trajectory__states(
  const void * untyped_member, size_t index)
{
  const tri_gen_msgs__msg__State__Sequence * member =
    (const tri_gen_msgs__msg__State__Sequence *)(untyped_member);
  return &member->data[index];
}

void * tri_gen_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__get_function__Trajectory__states(
  void * untyped_member, size_t index)
{
  tri_gen_msgs__msg__State__Sequence * member =
    (tri_gen_msgs__msg__State__Sequence *)(untyped_member);
  return &member->data[index];
}

void tri_gen_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__fetch_function__Trajectory__states(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const tri_gen_msgs__msg__State * item =
    ((const tri_gen_msgs__msg__State *)
    tri_gen_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__get_const_function__Trajectory__states(untyped_member, index));
  tri_gen_msgs__msg__State * value =
    (tri_gen_msgs__msg__State *)(untyped_value);
  *value = *item;
}

void tri_gen_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__assign_function__Trajectory__states(
  void * untyped_member, size_t index, const void * untyped_value)
{
  tri_gen_msgs__msg__State * item =
    ((tri_gen_msgs__msg__State *)
    tri_gen_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__get_function__Trajectory__states(untyped_member, index));
  const tri_gen_msgs__msg__State * value =
    (const tri_gen_msgs__msg__State *)(untyped_value);
  *item = *value;
}

bool tri_gen_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__resize_function__Trajectory__states(
  void * untyped_member, size_t size)
{
  tri_gen_msgs__msg__State__Sequence * member =
    (tri_gen_msgs__msg__State__Sequence *)(untyped_member);
  tri_gen_msgs__msg__State__Sequence__fini(member);
  return tri_gen_msgs__msg__State__Sequence__init(member, size);
}

size_t tri_gen_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__size_function__Trajectory__controls(
  const void * untyped_member)
{
  const tri_gen_msgs__msg__Control__Sequence * member =
    (const tri_gen_msgs__msg__Control__Sequence *)(untyped_member);
  return member->size;
}

const void * tri_gen_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__get_const_function__Trajectory__controls(
  const void * untyped_member, size_t index)
{
  const tri_gen_msgs__msg__Control__Sequence * member =
    (const tri_gen_msgs__msg__Control__Sequence *)(untyped_member);
  return &member->data[index];
}

void * tri_gen_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__get_function__Trajectory__controls(
  void * untyped_member, size_t index)
{
  tri_gen_msgs__msg__Control__Sequence * member =
    (tri_gen_msgs__msg__Control__Sequence *)(untyped_member);
  return &member->data[index];
}

void tri_gen_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__fetch_function__Trajectory__controls(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const tri_gen_msgs__msg__Control * item =
    ((const tri_gen_msgs__msg__Control *)
    tri_gen_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__get_const_function__Trajectory__controls(untyped_member, index));
  tri_gen_msgs__msg__Control * value =
    (tri_gen_msgs__msg__Control *)(untyped_value);
  *value = *item;
}

void tri_gen_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__assign_function__Trajectory__controls(
  void * untyped_member, size_t index, const void * untyped_value)
{
  tri_gen_msgs__msg__Control * item =
    ((tri_gen_msgs__msg__Control *)
    tri_gen_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__get_function__Trajectory__controls(untyped_member, index));
  const tri_gen_msgs__msg__Control * value =
    (const tri_gen_msgs__msg__Control *)(untyped_value);
  *item = *value;
}

bool tri_gen_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__resize_function__Trajectory__controls(
  void * untyped_member, size_t size)
{
  tri_gen_msgs__msg__Control__Sequence * member =
    (tri_gen_msgs__msg__Control__Sequence *)(untyped_member);
  tri_gen_msgs__msg__Control__Sequence__fini(member);
  return tri_gen_msgs__msg__Control__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember tri_gen_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__Trajectory_message_member_array[2] = {
  {
    "states",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tri_gen_msgs__msg__Trajectory, states),  // bytes offset in struct
    NULL,  // default value
    tri_gen_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__size_function__Trajectory__states,  // size() function pointer
    tri_gen_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__get_const_function__Trajectory__states,  // get_const(index) function pointer
    tri_gen_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__get_function__Trajectory__states,  // get(index) function pointer
    tri_gen_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__fetch_function__Trajectory__states,  // fetch(index, &value) function pointer
    tri_gen_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__assign_function__Trajectory__states,  // assign(index, value) function pointer
    tri_gen_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__resize_function__Trajectory__states  // resize(index) function pointer
  },
  {
    "controls",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tri_gen_msgs__msg__Trajectory, controls),  // bytes offset in struct
    NULL,  // default value
    tri_gen_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__size_function__Trajectory__controls,  // size() function pointer
    tri_gen_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__get_const_function__Trajectory__controls,  // get_const(index) function pointer
    tri_gen_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__get_function__Trajectory__controls,  // get(index) function pointer
    tri_gen_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__fetch_function__Trajectory__controls,  // fetch(index, &value) function pointer
    tri_gen_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__assign_function__Trajectory__controls,  // assign(index, value) function pointer
    tri_gen_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__resize_function__Trajectory__controls  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers tri_gen_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__Trajectory_message_members = {
  "tri_gen_msgs__msg",  // message namespace
  "Trajectory",  // message name
  2,  // number of fields
  sizeof(tri_gen_msgs__msg__Trajectory),
  tri_gen_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__Trajectory_message_member_array,  // message members
  tri_gen_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__Trajectory_init_function,  // function to initialize message memory (memory has to be allocated)
  tri_gen_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__Trajectory_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tri_gen_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__Trajectory_message_type_support_handle = {
  0,
  &tri_gen_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__Trajectory_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tri_gen_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tri_gen_msgs, msg, Trajectory)() {
  tri_gen_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__Trajectory_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tri_gen_msgs, msg, State)();
  tri_gen_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__Trajectory_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tri_gen_msgs, msg, Control)();
  if (!tri_gen_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__Trajectory_message_type_support_handle.typesupport_identifier) {
    tri_gen_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__Trajectory_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tri_gen_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__Trajectory_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
