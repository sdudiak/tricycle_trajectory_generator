// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tri_gen_msgs:srv/GenerateTrajectory.idl
// generated code does not contain a copyright notice

#ifndef TRI_GEN_MSGS__SRV__DETAIL__GENERATE_TRAJECTORY__STRUCT_H_
#define TRI_GEN_MSGS__SRV__DETAIL__GENERATE_TRAJECTORY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'start'
// Member 'goal'
#include "tri_gen_msgs/msg/detail/state__struct.h"

/// Struct defined in srv/GenerateTrajectory in the package tri_gen_msgs.
typedef struct tri_gen_msgs__srv__GenerateTrajectory_Request
{
  /// initial state
  tri_gen_msgs__msg__State start;
  /// goal state
  tri_gen_msgs__msg__State goal;
  /// trajectory sampling time step (in seconds)
  double dt;
  double phi_min;
  double phi_max;
  double omega_phi_min;
  double omega_phi_max;
  double v_min;
  double v_max;
  double a_min;
  double a_max;
} tri_gen_msgs__srv__GenerateTrajectory_Request;

// Struct for a sequence of tri_gen_msgs__srv__GenerateTrajectory_Request.
typedef struct tri_gen_msgs__srv__GenerateTrajectory_Request__Sequence
{
  tri_gen_msgs__srv__GenerateTrajectory_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tri_gen_msgs__srv__GenerateTrajectory_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'trajectory'
#include "tri_gen_msgs/msg/detail/trajectory__struct.h"
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/GenerateTrajectory in the package tri_gen_msgs.
typedef struct tri_gen_msgs__srv__GenerateTrajectory_Response
{
  tri_gen_msgs__msg__Trajectory trajectory;
  /// total trajectory length (meters)
  double total_length;
  /// maximum linear velocity in the trajectory
  double max_velocity;
  /// maximum trajectory curvature (1/turn radius)
  double max_curvature;
  /// trajectory generation time in milliseconds
  double generation_time_ms;
  /// success flag
  bool success;
  /// descriptive message
  rosidl_runtime_c__String message;
} tri_gen_msgs__srv__GenerateTrajectory_Response;

// Struct for a sequence of tri_gen_msgs__srv__GenerateTrajectory_Response.
typedef struct tri_gen_msgs__srv__GenerateTrajectory_Response__Sequence
{
  tri_gen_msgs__srv__GenerateTrajectory_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tri_gen_msgs__srv__GenerateTrajectory_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TRI_GEN_MSGS__SRV__DETAIL__GENERATE_TRAJECTORY__STRUCT_H_
