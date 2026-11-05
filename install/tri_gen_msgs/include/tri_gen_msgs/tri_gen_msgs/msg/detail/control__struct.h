// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tri_gen_msgs:msg/Control.idl
// generated code does not contain a copyright notice

#ifndef TRI_GEN_MSGS__MSG__DETAIL__CONTROL__STRUCT_H_
#define TRI_GEN_MSGS__MSG__DETAIL__CONTROL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'duration'
#include "builtin_interfaces/msg/detail/duration__struct.h"

/// Struct defined in msg/Control in the package tri_gen_msgs.
/**
  * This message describes the desired control command
 */
typedef struct tri_gen_msgs__msg__Control
{
  /// dphi/dt – desired angular velocity of the wheel
  double omega_phi;
  /// dv/dt – desired linear acceleration
  double a;
  /// duration of the given control command
  builtin_interfaces__msg__Duration duration;
} tri_gen_msgs__msg__Control;

// Struct for a sequence of tri_gen_msgs__msg__Control.
typedef struct tri_gen_msgs__msg__Control__Sequence
{
  tri_gen_msgs__msg__Control * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tri_gen_msgs__msg__Control__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TRI_GEN_MSGS__MSG__DETAIL__CONTROL__STRUCT_H_
