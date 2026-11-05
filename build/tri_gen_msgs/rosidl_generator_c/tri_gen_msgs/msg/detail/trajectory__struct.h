// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tri_gen_msgs:msg/Trajectory.idl
// generated code does not contain a copyright notice

#ifndef TRI_GEN_MSGS__MSG__DETAIL__TRAJECTORY__STRUCT_H_
#define TRI_GEN_MSGS__MSG__DETAIL__TRAJECTORY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'states'
#include "tri_gen_msgs/msg/detail/state__struct.h"
// Member 'controls'
#include "tri_gen_msgs/msg/detail/control__struct.h"

/// Struct defined in msg/Trajectory in the package tri_gen_msgs.
/**
  * List of states and controls creating a trajectory
 */
typedef struct tri_gen_msgs__msg__Trajectory
{
  /// sequence of all trajectory points (with timestamps)
  tri_gen_msgs__msg__State__Sequence states;
  /// sequence of control commands between consecutive points
  tri_gen_msgs__msg__Control__Sequence controls;
} tri_gen_msgs__msg__Trajectory;

// Struct for a sequence of tri_gen_msgs__msg__Trajectory.
typedef struct tri_gen_msgs__msg__Trajectory__Sequence
{
  tri_gen_msgs__msg__Trajectory * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tri_gen_msgs__msg__Trajectory__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TRI_GEN_MSGS__MSG__DETAIL__TRAJECTORY__STRUCT_H_
