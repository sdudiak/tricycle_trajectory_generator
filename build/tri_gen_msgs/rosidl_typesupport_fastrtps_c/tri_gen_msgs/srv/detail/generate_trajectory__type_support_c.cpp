// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from tri_gen_msgs:srv/GenerateTrajectory.idl
// generated code does not contain a copyright notice
#include "tri_gen_msgs/srv/detail/generate_trajectory__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "tri_gen_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "tri_gen_msgs/srv/detail/generate_trajectory__struct.h"
#include "tri_gen_msgs/srv/detail/generate_trajectory__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "tri_gen_msgs/msg/detail/state__functions.h"  // goal, start

// forward declare type support functions
size_t get_serialized_size_tri_gen_msgs__msg__State(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_tri_gen_msgs__msg__State(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, tri_gen_msgs, msg, State)();


using _GenerateTrajectory_Request__ros_msg_type = tri_gen_msgs__srv__GenerateTrajectory_Request;

static bool _GenerateTrajectory_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _GenerateTrajectory_Request__ros_msg_type * ros_message = static_cast<const _GenerateTrajectory_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: start
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, tri_gen_msgs, msg, State
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->start, cdr))
    {
      return false;
    }
  }

  // Field name: goal
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, tri_gen_msgs, msg, State
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->goal, cdr))
    {
      return false;
    }
  }

  // Field name: dt
  {
    cdr << ros_message->dt;
  }

  // Field name: phi_min
  {
    cdr << ros_message->phi_min;
  }

  // Field name: phi_max
  {
    cdr << ros_message->phi_max;
  }

  // Field name: omega_phi_min
  {
    cdr << ros_message->omega_phi_min;
  }

  // Field name: omega_phi_max
  {
    cdr << ros_message->omega_phi_max;
  }

  // Field name: v_min
  {
    cdr << ros_message->v_min;
  }

  // Field name: v_max
  {
    cdr << ros_message->v_max;
  }

  // Field name: a_min
  {
    cdr << ros_message->a_min;
  }

  // Field name: a_max
  {
    cdr << ros_message->a_max;
  }

  return true;
}

static bool _GenerateTrajectory_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _GenerateTrajectory_Request__ros_msg_type * ros_message = static_cast<_GenerateTrajectory_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: start
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, tri_gen_msgs, msg, State
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->start))
    {
      return false;
    }
  }

  // Field name: goal
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, tri_gen_msgs, msg, State
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->goal))
    {
      return false;
    }
  }

  // Field name: dt
  {
    cdr >> ros_message->dt;
  }

  // Field name: phi_min
  {
    cdr >> ros_message->phi_min;
  }

  // Field name: phi_max
  {
    cdr >> ros_message->phi_max;
  }

  // Field name: omega_phi_min
  {
    cdr >> ros_message->omega_phi_min;
  }

  // Field name: omega_phi_max
  {
    cdr >> ros_message->omega_phi_max;
  }

  // Field name: v_min
  {
    cdr >> ros_message->v_min;
  }

  // Field name: v_max
  {
    cdr >> ros_message->v_max;
  }

  // Field name: a_min
  {
    cdr >> ros_message->a_min;
  }

  // Field name: a_max
  {
    cdr >> ros_message->a_max;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tri_gen_msgs
size_t get_serialized_size_tri_gen_msgs__srv__GenerateTrajectory_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _GenerateTrajectory_Request__ros_msg_type * ros_message = static_cast<const _GenerateTrajectory_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name start

  current_alignment += get_serialized_size_tri_gen_msgs__msg__State(
    &(ros_message->start), current_alignment);
  // field.name goal

  current_alignment += get_serialized_size_tri_gen_msgs__msg__State(
    &(ros_message->goal), current_alignment);
  // field.name dt
  {
    size_t item_size = sizeof(ros_message->dt);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name phi_min
  {
    size_t item_size = sizeof(ros_message->phi_min);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name phi_max
  {
    size_t item_size = sizeof(ros_message->phi_max);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name omega_phi_min
  {
    size_t item_size = sizeof(ros_message->omega_phi_min);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name omega_phi_max
  {
    size_t item_size = sizeof(ros_message->omega_phi_max);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name v_min
  {
    size_t item_size = sizeof(ros_message->v_min);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name v_max
  {
    size_t item_size = sizeof(ros_message->v_max);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name a_min
  {
    size_t item_size = sizeof(ros_message->a_min);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name a_max
  {
    size_t item_size = sizeof(ros_message->a_max);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _GenerateTrajectory_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_tri_gen_msgs__srv__GenerateTrajectory_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tri_gen_msgs
size_t max_serialized_size_tri_gen_msgs__srv__GenerateTrajectory_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: start
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_tri_gen_msgs__msg__State(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: goal
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_tri_gen_msgs__msg__State(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: dt
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: phi_min
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: phi_max
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: omega_phi_min
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: omega_phi_max
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: v_min
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: v_max
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: a_min
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: a_max
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = tri_gen_msgs__srv__GenerateTrajectory_Request;
    is_plain =
      (
      offsetof(DataType, a_max) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _GenerateTrajectory_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_tri_gen_msgs__srv__GenerateTrajectory_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_GenerateTrajectory_Request = {
  "tri_gen_msgs::srv",
  "GenerateTrajectory_Request",
  _GenerateTrajectory_Request__cdr_serialize,
  _GenerateTrajectory_Request__cdr_deserialize,
  _GenerateTrajectory_Request__get_serialized_size,
  _GenerateTrajectory_Request__max_serialized_size
};

static rosidl_message_type_support_t _GenerateTrajectory_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_GenerateTrajectory_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, tri_gen_msgs, srv, GenerateTrajectory_Request)() {
  return &_GenerateTrajectory_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "tri_gen_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "tri_gen_msgs/srv/detail/generate_trajectory__struct.h"
// already included above
// #include "tri_gen_msgs/srv/detail/generate_trajectory__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // message
#include "rosidl_runtime_c/string_functions.h"  // message
#include "tri_gen_msgs/msg/detail/trajectory__functions.h"  // trajectory

// forward declare type support functions
size_t get_serialized_size_tri_gen_msgs__msg__Trajectory(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_tri_gen_msgs__msg__Trajectory(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, tri_gen_msgs, msg, Trajectory)();


using _GenerateTrajectory_Response__ros_msg_type = tri_gen_msgs__srv__GenerateTrajectory_Response;

static bool _GenerateTrajectory_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _GenerateTrajectory_Response__ros_msg_type * ros_message = static_cast<const _GenerateTrajectory_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: trajectory
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, tri_gen_msgs, msg, Trajectory
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->trajectory, cdr))
    {
      return false;
    }
  }

  // Field name: total_length
  {
    cdr << ros_message->total_length;
  }

  // Field name: max_velocity
  {
    cdr << ros_message->max_velocity;
  }

  // Field name: max_curvature
  {
    cdr << ros_message->max_curvature;
  }

  // Field name: generation_time_ms
  {
    cdr << ros_message->generation_time_ms;
  }

  // Field name: success
  {
    cdr << (ros_message->success ? true : false);
  }

  // Field name: message
  {
    const rosidl_runtime_c__String * str = &ros_message->message;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

static bool _GenerateTrajectory_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _GenerateTrajectory_Response__ros_msg_type * ros_message = static_cast<_GenerateTrajectory_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: trajectory
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, tri_gen_msgs, msg, Trajectory
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->trajectory))
    {
      return false;
    }
  }

  // Field name: total_length
  {
    cdr >> ros_message->total_length;
  }

  // Field name: max_velocity
  {
    cdr >> ros_message->max_velocity;
  }

  // Field name: max_curvature
  {
    cdr >> ros_message->max_curvature;
  }

  // Field name: generation_time_ms
  {
    cdr >> ros_message->generation_time_ms;
  }

  // Field name: success
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->success = tmp ? true : false;
  }

  // Field name: message
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->message.data) {
      rosidl_runtime_c__String__init(&ros_message->message);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->message,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'message'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tri_gen_msgs
size_t get_serialized_size_tri_gen_msgs__srv__GenerateTrajectory_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _GenerateTrajectory_Response__ros_msg_type * ros_message = static_cast<const _GenerateTrajectory_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name trajectory

  current_alignment += get_serialized_size_tri_gen_msgs__msg__Trajectory(
    &(ros_message->trajectory), current_alignment);
  // field.name total_length
  {
    size_t item_size = sizeof(ros_message->total_length);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name max_velocity
  {
    size_t item_size = sizeof(ros_message->max_velocity);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name max_curvature
  {
    size_t item_size = sizeof(ros_message->max_curvature);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name generation_time_ms
  {
    size_t item_size = sizeof(ros_message->generation_time_ms);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name success
  {
    size_t item_size = sizeof(ros_message->success);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name message
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->message.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _GenerateTrajectory_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_tri_gen_msgs__srv__GenerateTrajectory_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tri_gen_msgs
size_t max_serialized_size_tri_gen_msgs__srv__GenerateTrajectory_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: trajectory
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_tri_gen_msgs__msg__Trajectory(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: total_length
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: max_velocity
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: max_curvature
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: generation_time_ms
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: success
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: message
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = tri_gen_msgs__srv__GenerateTrajectory_Response;
    is_plain =
      (
      offsetof(DataType, message) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _GenerateTrajectory_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_tri_gen_msgs__srv__GenerateTrajectory_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_GenerateTrajectory_Response = {
  "tri_gen_msgs::srv",
  "GenerateTrajectory_Response",
  _GenerateTrajectory_Response__cdr_serialize,
  _GenerateTrajectory_Response__cdr_deserialize,
  _GenerateTrajectory_Response__get_serialized_size,
  _GenerateTrajectory_Response__max_serialized_size
};

static rosidl_message_type_support_t _GenerateTrajectory_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_GenerateTrajectory_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, tri_gen_msgs, srv, GenerateTrajectory_Response)() {
  return &_GenerateTrajectory_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "tri_gen_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "tri_gen_msgs/srv/generate_trajectory.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t GenerateTrajectory__callbacks = {
  "tri_gen_msgs::srv",
  "GenerateTrajectory",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, tri_gen_msgs, srv, GenerateTrajectory_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, tri_gen_msgs, srv, GenerateTrajectory_Response)(),
};

static rosidl_service_type_support_t GenerateTrajectory__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &GenerateTrajectory__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, tri_gen_msgs, srv, GenerateTrajectory)() {
  return &GenerateTrajectory__handle;
}

#if defined(__cplusplus)
}
#endif
