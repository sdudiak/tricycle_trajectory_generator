// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tri_gen_msgs:msg/State.idl
// generated code does not contain a copyright notice

#ifndef TRI_GEN_MSGS__MSG__DETAIL__STATE__STRUCT_H_
#define TRI_GEN_MSGS__MSG__DETAIL__STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'stamp_from_start'
#include "builtin_interfaces/msg/detail/duration__struct.h"

/// Struct defined in msg/State in the package tri_gen_msgs.
typedef struct tri_gen_msgs__msg__State
{
  /// X position in the map frame
  double x;
  /// Y position in the map frame
  double y;
  /// orientation of the entire platform
  double theta;
  /// steering angle of the front wheel
  double phi;
  /// angular velocity of the steering angle (dphi/dt)
  double omega_phi;
  /// linear velocity of the drive wheel
  double v;
  /// time since the beginning of the trajectory
  builtin_interfaces__msg__Duration stamp_from_start;
} tri_gen_msgs__msg__State;

// Struct for a sequence of tri_gen_msgs__msg__State.
typedef struct tri_gen_msgs__msg__State__Sequence
{
  tri_gen_msgs__msg__State * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tri_gen_msgs__msg__State__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TRI_GEN_MSGS__MSG__DETAIL__STATE__STRUCT_H_
