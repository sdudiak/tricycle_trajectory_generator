// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from tri_gen_msgs:srv/GenerateTrajectory.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "tri_gen_msgs/srv/detail/generate_trajectory__rosidl_typesupport_introspection_c.h"
#include "tri_gen_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "tri_gen_msgs/srv/detail/generate_trajectory__functions.h"
#include "tri_gen_msgs/srv/detail/generate_trajectory__struct.h"


// Include directives for member types
// Member `start`
// Member `goal`
#include "tri_gen_msgs/msg/state.h"
// Member `start`
// Member `goal`
#include "tri_gen_msgs/msg/detail/state__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void tri_gen_msgs__srv__GenerateTrajectory_Request__rosidl_typesupport_introspection_c__GenerateTrajectory_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tri_gen_msgs__srv__GenerateTrajectory_Request__init(message_memory);
}

void tri_gen_msgs__srv__GenerateTrajectory_Request__rosidl_typesupport_introspection_c__GenerateTrajectory_Request_fini_function(void * message_memory)
{
  tri_gen_msgs__srv__GenerateTrajectory_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember tri_gen_msgs__srv__GenerateTrajectory_Request__rosidl_typesupport_introspection_c__GenerateTrajectory_Request_message_member_array[11] = {
  {
    "start",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tri_gen_msgs__srv__GenerateTrajectory_Request, start),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "goal",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tri_gen_msgs__srv__GenerateTrajectory_Request, goal),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "dt",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tri_gen_msgs__srv__GenerateTrajectory_Request, dt),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "phi_min",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tri_gen_msgs__srv__GenerateTrajectory_Request, phi_min),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "phi_max",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tri_gen_msgs__srv__GenerateTrajectory_Request, phi_max),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "omega_phi_min",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tri_gen_msgs__srv__GenerateTrajectory_Request, omega_phi_min),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "omega_phi_max",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tri_gen_msgs__srv__GenerateTrajectory_Request, omega_phi_max),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "v_min",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tri_gen_msgs__srv__GenerateTrajectory_Request, v_min),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "v_max",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tri_gen_msgs__srv__GenerateTrajectory_Request, v_max),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "a_min",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tri_gen_msgs__srv__GenerateTrajectory_Request, a_min),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "a_max",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tri_gen_msgs__srv__GenerateTrajectory_Request, a_max),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers tri_gen_msgs__srv__GenerateTrajectory_Request__rosidl_typesupport_introspection_c__GenerateTrajectory_Request_message_members = {
  "tri_gen_msgs__srv",  // message namespace
  "GenerateTrajectory_Request",  // message name
  11,  // number of fields
  sizeof(tri_gen_msgs__srv__GenerateTrajectory_Request),
  tri_gen_msgs__srv__GenerateTrajectory_Request__rosidl_typesupport_introspection_c__GenerateTrajectory_Request_message_member_array,  // message members
  tri_gen_msgs__srv__GenerateTrajectory_Request__rosidl_typesupport_introspection_c__GenerateTrajectory_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  tri_gen_msgs__srv__GenerateTrajectory_Request__rosidl_typesupport_introspection_c__GenerateTrajectory_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tri_gen_msgs__srv__GenerateTrajectory_Request__rosidl_typesupport_introspection_c__GenerateTrajectory_Request_message_type_support_handle = {
  0,
  &tri_gen_msgs__srv__GenerateTrajectory_Request__rosidl_typesupport_introspection_c__GenerateTrajectory_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tri_gen_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tri_gen_msgs, srv, GenerateTrajectory_Request)() {
  tri_gen_msgs__srv__GenerateTrajectory_Request__rosidl_typesupport_introspection_c__GenerateTrajectory_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tri_gen_msgs, msg, State)();
  tri_gen_msgs__srv__GenerateTrajectory_Request__rosidl_typesupport_introspection_c__GenerateTrajectory_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tri_gen_msgs, msg, State)();
  if (!tri_gen_msgs__srv__GenerateTrajectory_Request__rosidl_typesupport_introspection_c__GenerateTrajectory_Request_message_type_support_handle.typesupport_identifier) {
    tri_gen_msgs__srv__GenerateTrajectory_Request__rosidl_typesupport_introspection_c__GenerateTrajectory_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tri_gen_msgs__srv__GenerateTrajectory_Request__rosidl_typesupport_introspection_c__GenerateTrajectory_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "tri_gen_msgs/srv/detail/generate_trajectory__rosidl_typesupport_introspection_c.h"
// already included above
// #include "tri_gen_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "tri_gen_msgs/srv/detail/generate_trajectory__functions.h"
// already included above
// #include "tri_gen_msgs/srv/detail/generate_trajectory__struct.h"


// Include directives for member types
// Member `trajectory`
#include "tri_gen_msgs/msg/trajectory.h"
// Member `trajectory`
#include "tri_gen_msgs/msg/detail/trajectory__rosidl_typesupport_introspection_c.h"
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void tri_gen_msgs__srv__GenerateTrajectory_Response__rosidl_typesupport_introspection_c__GenerateTrajectory_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tri_gen_msgs__srv__GenerateTrajectory_Response__init(message_memory);
}

void tri_gen_msgs__srv__GenerateTrajectory_Response__rosidl_typesupport_introspection_c__GenerateTrajectory_Response_fini_function(void * message_memory)
{
  tri_gen_msgs__srv__GenerateTrajectory_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember tri_gen_msgs__srv__GenerateTrajectory_Response__rosidl_typesupport_introspection_c__GenerateTrajectory_Response_message_member_array[7] = {
  {
    "trajectory",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tri_gen_msgs__srv__GenerateTrajectory_Response, trajectory),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "total_length",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tri_gen_msgs__srv__GenerateTrajectory_Response, total_length),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "max_velocity",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tri_gen_msgs__srv__GenerateTrajectory_Response, max_velocity),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "max_curvature",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tri_gen_msgs__srv__GenerateTrajectory_Response, max_curvature),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "generation_time_ms",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tri_gen_msgs__srv__GenerateTrajectory_Response, generation_time_ms),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tri_gen_msgs__srv__GenerateTrajectory_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tri_gen_msgs__srv__GenerateTrajectory_Response, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers tri_gen_msgs__srv__GenerateTrajectory_Response__rosidl_typesupport_introspection_c__GenerateTrajectory_Response_message_members = {
  "tri_gen_msgs__srv",  // message namespace
  "GenerateTrajectory_Response",  // message name
  7,  // number of fields
  sizeof(tri_gen_msgs__srv__GenerateTrajectory_Response),
  tri_gen_msgs__srv__GenerateTrajectory_Response__rosidl_typesupport_introspection_c__GenerateTrajectory_Response_message_member_array,  // message members
  tri_gen_msgs__srv__GenerateTrajectory_Response__rosidl_typesupport_introspection_c__GenerateTrajectory_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  tri_gen_msgs__srv__GenerateTrajectory_Response__rosidl_typesupport_introspection_c__GenerateTrajectory_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tri_gen_msgs__srv__GenerateTrajectory_Response__rosidl_typesupport_introspection_c__GenerateTrajectory_Response_message_type_support_handle = {
  0,
  &tri_gen_msgs__srv__GenerateTrajectory_Response__rosidl_typesupport_introspection_c__GenerateTrajectory_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tri_gen_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tri_gen_msgs, srv, GenerateTrajectory_Response)() {
  tri_gen_msgs__srv__GenerateTrajectory_Response__rosidl_typesupport_introspection_c__GenerateTrajectory_Response_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tri_gen_msgs, msg, Trajectory)();
  if (!tri_gen_msgs__srv__GenerateTrajectory_Response__rosidl_typesupport_introspection_c__GenerateTrajectory_Response_message_type_support_handle.typesupport_identifier) {
    tri_gen_msgs__srv__GenerateTrajectory_Response__rosidl_typesupport_introspection_c__GenerateTrajectory_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tri_gen_msgs__srv__GenerateTrajectory_Response__rosidl_typesupport_introspection_c__GenerateTrajectory_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "tri_gen_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "tri_gen_msgs/srv/detail/generate_trajectory__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers tri_gen_msgs__srv__detail__generate_trajectory__rosidl_typesupport_introspection_c__GenerateTrajectory_service_members = {
  "tri_gen_msgs__srv",  // service namespace
  "GenerateTrajectory",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // tri_gen_msgs__srv__detail__generate_trajectory__rosidl_typesupport_introspection_c__GenerateTrajectory_Request_message_type_support_handle,
  NULL  // response message
  // tri_gen_msgs__srv__detail__generate_trajectory__rosidl_typesupport_introspection_c__GenerateTrajectory_Response_message_type_support_handle
};

static rosidl_service_type_support_t tri_gen_msgs__srv__detail__generate_trajectory__rosidl_typesupport_introspection_c__GenerateTrajectory_service_type_support_handle = {
  0,
  &tri_gen_msgs__srv__detail__generate_trajectory__rosidl_typesupport_introspection_c__GenerateTrajectory_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tri_gen_msgs, srv, GenerateTrajectory_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tri_gen_msgs, srv, GenerateTrajectory_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tri_gen_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tri_gen_msgs, srv, GenerateTrajectory)() {
  if (!tri_gen_msgs__srv__detail__generate_trajectory__rosidl_typesupport_introspection_c__GenerateTrajectory_service_type_support_handle.typesupport_identifier) {
    tri_gen_msgs__srv__detail__generate_trajectory__rosidl_typesupport_introspection_c__GenerateTrajectory_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)tri_gen_msgs__srv__detail__generate_trajectory__rosidl_typesupport_introspection_c__GenerateTrajectory_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tri_gen_msgs, srv, GenerateTrajectory_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tri_gen_msgs, srv, GenerateTrajectory_Response)()->data;
  }

  return &tri_gen_msgs__srv__detail__generate_trajectory__rosidl_typesupport_introspection_c__GenerateTrajectory_service_type_support_handle;
}
