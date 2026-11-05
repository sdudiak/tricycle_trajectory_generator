// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from tri_gen_msgs:srv/GenerateTrajectory.idl
// generated code does not contain a copyright notice
#include "tri_gen_msgs/srv/detail/generate_trajectory__rosidl_typesupport_fastrtps_cpp.hpp"
#include "tri_gen_msgs/srv/detail/generate_trajectory__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace tri_gen_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const tri_gen_msgs::msg::State &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  tri_gen_msgs::msg::State &);
size_t get_serialized_size(
  const tri_gen_msgs::msg::State &,
  size_t current_alignment);
size_t
max_serialized_size_State(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace tri_gen_msgs

// functions for tri_gen_msgs::msg::State already declared above


namespace tri_gen_msgs
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tri_gen_msgs
cdr_serialize(
  const tri_gen_msgs::srv::GenerateTrajectory_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: start
  tri_gen_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.start,
    cdr);
  // Member: goal
  tri_gen_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.goal,
    cdr);
  // Member: dt
  cdr << ros_message.dt;
  // Member: phi_min
  cdr << ros_message.phi_min;
  // Member: phi_max
  cdr << ros_message.phi_max;
  // Member: omega_phi_min
  cdr << ros_message.omega_phi_min;
  // Member: omega_phi_max
  cdr << ros_message.omega_phi_max;
  // Member: v_min
  cdr << ros_message.v_min;
  // Member: v_max
  cdr << ros_message.v_max;
  // Member: a_min
  cdr << ros_message.a_min;
  // Member: a_max
  cdr << ros_message.a_max;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tri_gen_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  tri_gen_msgs::srv::GenerateTrajectory_Request & ros_message)
{
  // Member: start
  tri_gen_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.start);

  // Member: goal
  tri_gen_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.goal);

  // Member: dt
  cdr >> ros_message.dt;

  // Member: phi_min
  cdr >> ros_message.phi_min;

  // Member: phi_max
  cdr >> ros_message.phi_max;

  // Member: omega_phi_min
  cdr >> ros_message.omega_phi_min;

  // Member: omega_phi_max
  cdr >> ros_message.omega_phi_max;

  // Member: v_min
  cdr >> ros_message.v_min;

  // Member: v_max
  cdr >> ros_message.v_max;

  // Member: a_min
  cdr >> ros_message.a_min;

  // Member: a_max
  cdr >> ros_message.a_max;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tri_gen_msgs
get_serialized_size(
  const tri_gen_msgs::srv::GenerateTrajectory_Request & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: start

  current_alignment +=
    tri_gen_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.start, current_alignment);
  // Member: goal

  current_alignment +=
    tri_gen_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.goal, current_alignment);
  // Member: dt
  {
    size_t item_size = sizeof(ros_message.dt);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: phi_min
  {
    size_t item_size = sizeof(ros_message.phi_min);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: phi_max
  {
    size_t item_size = sizeof(ros_message.phi_max);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: omega_phi_min
  {
    size_t item_size = sizeof(ros_message.omega_phi_min);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: omega_phi_max
  {
    size_t item_size = sizeof(ros_message.omega_phi_max);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: v_min
  {
    size_t item_size = sizeof(ros_message.v_min);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: v_max
  {
    size_t item_size = sizeof(ros_message.v_max);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: a_min
  {
    size_t item_size = sizeof(ros_message.a_min);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: a_max
  {
    size_t item_size = sizeof(ros_message.a_max);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tri_gen_msgs
max_serialized_size_GenerateTrajectory_Request(
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


  // Member: start
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        tri_gen_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_State(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: goal
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        tri_gen_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_State(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: dt
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: phi_min
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: phi_max
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: omega_phi_min
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: omega_phi_max
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: v_min
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: v_max
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: a_min
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: a_max
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
    using DataType = tri_gen_msgs::srv::GenerateTrajectory_Request;
    is_plain =
      (
      offsetof(DataType, a_max) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _GenerateTrajectory_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const tri_gen_msgs::srv::GenerateTrajectory_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _GenerateTrajectory_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<tri_gen_msgs::srv::GenerateTrajectory_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _GenerateTrajectory_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const tri_gen_msgs::srv::GenerateTrajectory_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _GenerateTrajectory_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_GenerateTrajectory_Request(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _GenerateTrajectory_Request__callbacks = {
  "tri_gen_msgs::srv",
  "GenerateTrajectory_Request",
  _GenerateTrajectory_Request__cdr_serialize,
  _GenerateTrajectory_Request__cdr_deserialize,
  _GenerateTrajectory_Request__get_serialized_size,
  _GenerateTrajectory_Request__max_serialized_size
};

static rosidl_message_type_support_t _GenerateTrajectory_Request__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_GenerateTrajectory_Request__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace tri_gen_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_tri_gen_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<tri_gen_msgs::srv::GenerateTrajectory_Request>()
{
  return &tri_gen_msgs::srv::typesupport_fastrtps_cpp::_GenerateTrajectory_Request__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, tri_gen_msgs, srv, GenerateTrajectory_Request)() {
  return &tri_gen_msgs::srv::typesupport_fastrtps_cpp::_GenerateTrajectory_Request__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include <limits>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
// already included above
// #include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace tri_gen_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const tri_gen_msgs::msg::Trajectory &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  tri_gen_msgs::msg::Trajectory &);
size_t get_serialized_size(
  const tri_gen_msgs::msg::Trajectory &,
  size_t current_alignment);
size_t
max_serialized_size_Trajectory(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace tri_gen_msgs


namespace tri_gen_msgs
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tri_gen_msgs
cdr_serialize(
  const tri_gen_msgs::srv::GenerateTrajectory_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: trajectory
  tri_gen_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.trajectory,
    cdr);
  // Member: total_length
  cdr << ros_message.total_length;
  // Member: max_velocity
  cdr << ros_message.max_velocity;
  // Member: max_curvature
  cdr << ros_message.max_curvature;
  // Member: generation_time_ms
  cdr << ros_message.generation_time_ms;
  // Member: success
  cdr << (ros_message.success ? true : false);
  // Member: message
  cdr << ros_message.message;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tri_gen_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  tri_gen_msgs::srv::GenerateTrajectory_Response & ros_message)
{
  // Member: trajectory
  tri_gen_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.trajectory);

  // Member: total_length
  cdr >> ros_message.total_length;

  // Member: max_velocity
  cdr >> ros_message.max_velocity;

  // Member: max_curvature
  cdr >> ros_message.max_curvature;

  // Member: generation_time_ms
  cdr >> ros_message.generation_time_ms;

  // Member: success
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.success = tmp ? true : false;
  }

  // Member: message
  cdr >> ros_message.message;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tri_gen_msgs
get_serialized_size(
  const tri_gen_msgs::srv::GenerateTrajectory_Response & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: trajectory

  current_alignment +=
    tri_gen_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.trajectory, current_alignment);
  // Member: total_length
  {
    size_t item_size = sizeof(ros_message.total_length);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: max_velocity
  {
    size_t item_size = sizeof(ros_message.max_velocity);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: max_curvature
  {
    size_t item_size = sizeof(ros_message.max_curvature);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: generation_time_ms
  {
    size_t item_size = sizeof(ros_message.generation_time_ms);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: success
  {
    size_t item_size = sizeof(ros_message.success);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: message
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.message.size() + 1);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tri_gen_msgs
max_serialized_size_GenerateTrajectory_Response(
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


  // Member: trajectory
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        tri_gen_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Trajectory(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: total_length
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: max_velocity
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: max_curvature
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: generation_time_ms
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: success
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: message
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
    using DataType = tri_gen_msgs::srv::GenerateTrajectory_Response;
    is_plain =
      (
      offsetof(DataType, message) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _GenerateTrajectory_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const tri_gen_msgs::srv::GenerateTrajectory_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _GenerateTrajectory_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<tri_gen_msgs::srv::GenerateTrajectory_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _GenerateTrajectory_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const tri_gen_msgs::srv::GenerateTrajectory_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _GenerateTrajectory_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_GenerateTrajectory_Response(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _GenerateTrajectory_Response__callbacks = {
  "tri_gen_msgs::srv",
  "GenerateTrajectory_Response",
  _GenerateTrajectory_Response__cdr_serialize,
  _GenerateTrajectory_Response__cdr_deserialize,
  _GenerateTrajectory_Response__get_serialized_size,
  _GenerateTrajectory_Response__max_serialized_size
};

static rosidl_message_type_support_t _GenerateTrajectory_Response__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_GenerateTrajectory_Response__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace tri_gen_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_tri_gen_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<tri_gen_msgs::srv::GenerateTrajectory_Response>()
{
  return &tri_gen_msgs::srv::typesupport_fastrtps_cpp::_GenerateTrajectory_Response__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, tri_gen_msgs, srv, GenerateTrajectory_Response)() {
  return &tri_gen_msgs::srv::typesupport_fastrtps_cpp::_GenerateTrajectory_Response__handle;
}

#ifdef __cplusplus
}
#endif

#include "rmw/error_handling.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support_decl.hpp"

namespace tri_gen_msgs
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

static service_type_support_callbacks_t _GenerateTrajectory__callbacks = {
  "tri_gen_msgs::srv",
  "GenerateTrajectory",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, tri_gen_msgs, srv, GenerateTrajectory_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, tri_gen_msgs, srv, GenerateTrajectory_Response)(),
};

static rosidl_service_type_support_t _GenerateTrajectory__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_GenerateTrajectory__callbacks,
  get_service_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace tri_gen_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_tri_gen_msgs
const rosidl_service_type_support_t *
get_service_type_support_handle<tri_gen_msgs::srv::GenerateTrajectory>()
{
  return &tri_gen_msgs::srv::typesupport_fastrtps_cpp::_GenerateTrajectory__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, tri_gen_msgs, srv, GenerateTrajectory)() {
  return &tri_gen_msgs::srv::typesupport_fastrtps_cpp::_GenerateTrajectory__handle;
}

#ifdef __cplusplus
}
#endif
