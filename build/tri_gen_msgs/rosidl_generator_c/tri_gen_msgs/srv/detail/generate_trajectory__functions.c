// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tri_gen_msgs:srv/GenerateTrajectory.idl
// generated code does not contain a copyright notice
#include "tri_gen_msgs/srv/detail/generate_trajectory__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `start`
// Member `goal`
#include "tri_gen_msgs/msg/detail/state__functions.h"

bool
tri_gen_msgs__srv__GenerateTrajectory_Request__init(tri_gen_msgs__srv__GenerateTrajectory_Request * msg)
{
  if (!msg) {
    return false;
  }
  // start
  if (!tri_gen_msgs__msg__State__init(&msg->start)) {
    tri_gen_msgs__srv__GenerateTrajectory_Request__fini(msg);
    return false;
  }
  // goal
  if (!tri_gen_msgs__msg__State__init(&msg->goal)) {
    tri_gen_msgs__srv__GenerateTrajectory_Request__fini(msg);
    return false;
  }
  // dt
  // phi_min
  // phi_max
  // omega_phi_min
  // omega_phi_max
  // v_min
  // v_max
  // a_min
  // a_max
  return true;
}

void
tri_gen_msgs__srv__GenerateTrajectory_Request__fini(tri_gen_msgs__srv__GenerateTrajectory_Request * msg)
{
  if (!msg) {
    return;
  }
  // start
  tri_gen_msgs__msg__State__fini(&msg->start);
  // goal
  tri_gen_msgs__msg__State__fini(&msg->goal);
  // dt
  // phi_min
  // phi_max
  // omega_phi_min
  // omega_phi_max
  // v_min
  // v_max
  // a_min
  // a_max
}

bool
tri_gen_msgs__srv__GenerateTrajectory_Request__are_equal(const tri_gen_msgs__srv__GenerateTrajectory_Request * lhs, const tri_gen_msgs__srv__GenerateTrajectory_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // start
  if (!tri_gen_msgs__msg__State__are_equal(
      &(lhs->start), &(rhs->start)))
  {
    return false;
  }
  // goal
  if (!tri_gen_msgs__msg__State__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  // dt
  if (lhs->dt != rhs->dt) {
    return false;
  }
  // phi_min
  if (lhs->phi_min != rhs->phi_min) {
    return false;
  }
  // phi_max
  if (lhs->phi_max != rhs->phi_max) {
    return false;
  }
  // omega_phi_min
  if (lhs->omega_phi_min != rhs->omega_phi_min) {
    return false;
  }
  // omega_phi_max
  if (lhs->omega_phi_max != rhs->omega_phi_max) {
    return false;
  }
  // v_min
  if (lhs->v_min != rhs->v_min) {
    return false;
  }
  // v_max
  if (lhs->v_max != rhs->v_max) {
    return false;
  }
  // a_min
  if (lhs->a_min != rhs->a_min) {
    return false;
  }
  // a_max
  if (lhs->a_max != rhs->a_max) {
    return false;
  }
  return true;
}

bool
tri_gen_msgs__srv__GenerateTrajectory_Request__copy(
  const tri_gen_msgs__srv__GenerateTrajectory_Request * input,
  tri_gen_msgs__srv__GenerateTrajectory_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // start
  if (!tri_gen_msgs__msg__State__copy(
      &(input->start), &(output->start)))
  {
    return false;
  }
  // goal
  if (!tri_gen_msgs__msg__State__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  // dt
  output->dt = input->dt;
  // phi_min
  output->phi_min = input->phi_min;
  // phi_max
  output->phi_max = input->phi_max;
  // omega_phi_min
  output->omega_phi_min = input->omega_phi_min;
  // omega_phi_max
  output->omega_phi_max = input->omega_phi_max;
  // v_min
  output->v_min = input->v_min;
  // v_max
  output->v_max = input->v_max;
  // a_min
  output->a_min = input->a_min;
  // a_max
  output->a_max = input->a_max;
  return true;
}

tri_gen_msgs__srv__GenerateTrajectory_Request *
tri_gen_msgs__srv__GenerateTrajectory_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tri_gen_msgs__srv__GenerateTrajectory_Request * msg = (tri_gen_msgs__srv__GenerateTrajectory_Request *)allocator.allocate(sizeof(tri_gen_msgs__srv__GenerateTrajectory_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tri_gen_msgs__srv__GenerateTrajectory_Request));
  bool success = tri_gen_msgs__srv__GenerateTrajectory_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tri_gen_msgs__srv__GenerateTrajectory_Request__destroy(tri_gen_msgs__srv__GenerateTrajectory_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tri_gen_msgs__srv__GenerateTrajectory_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tri_gen_msgs__srv__GenerateTrajectory_Request__Sequence__init(tri_gen_msgs__srv__GenerateTrajectory_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tri_gen_msgs__srv__GenerateTrajectory_Request * data = NULL;

  if (size) {
    data = (tri_gen_msgs__srv__GenerateTrajectory_Request *)allocator.zero_allocate(size, sizeof(tri_gen_msgs__srv__GenerateTrajectory_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tri_gen_msgs__srv__GenerateTrajectory_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tri_gen_msgs__srv__GenerateTrajectory_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
tri_gen_msgs__srv__GenerateTrajectory_Request__Sequence__fini(tri_gen_msgs__srv__GenerateTrajectory_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      tri_gen_msgs__srv__GenerateTrajectory_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

tri_gen_msgs__srv__GenerateTrajectory_Request__Sequence *
tri_gen_msgs__srv__GenerateTrajectory_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tri_gen_msgs__srv__GenerateTrajectory_Request__Sequence * array = (tri_gen_msgs__srv__GenerateTrajectory_Request__Sequence *)allocator.allocate(sizeof(tri_gen_msgs__srv__GenerateTrajectory_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tri_gen_msgs__srv__GenerateTrajectory_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tri_gen_msgs__srv__GenerateTrajectory_Request__Sequence__destroy(tri_gen_msgs__srv__GenerateTrajectory_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tri_gen_msgs__srv__GenerateTrajectory_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tri_gen_msgs__srv__GenerateTrajectory_Request__Sequence__are_equal(const tri_gen_msgs__srv__GenerateTrajectory_Request__Sequence * lhs, const tri_gen_msgs__srv__GenerateTrajectory_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tri_gen_msgs__srv__GenerateTrajectory_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tri_gen_msgs__srv__GenerateTrajectory_Request__Sequence__copy(
  const tri_gen_msgs__srv__GenerateTrajectory_Request__Sequence * input,
  tri_gen_msgs__srv__GenerateTrajectory_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tri_gen_msgs__srv__GenerateTrajectory_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tri_gen_msgs__srv__GenerateTrajectory_Request * data =
      (tri_gen_msgs__srv__GenerateTrajectory_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tri_gen_msgs__srv__GenerateTrajectory_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tri_gen_msgs__srv__GenerateTrajectory_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tri_gen_msgs__srv__GenerateTrajectory_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `trajectory`
#include "tri_gen_msgs/msg/detail/trajectory__functions.h"
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

bool
tri_gen_msgs__srv__GenerateTrajectory_Response__init(tri_gen_msgs__srv__GenerateTrajectory_Response * msg)
{
  if (!msg) {
    return false;
  }
  // trajectory
  if (!tri_gen_msgs__msg__Trajectory__init(&msg->trajectory)) {
    tri_gen_msgs__srv__GenerateTrajectory_Response__fini(msg);
    return false;
  }
  // total_length
  // max_velocity
  // max_curvature
  // generation_time_ms
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    tri_gen_msgs__srv__GenerateTrajectory_Response__fini(msg);
    return false;
  }
  return true;
}

void
tri_gen_msgs__srv__GenerateTrajectory_Response__fini(tri_gen_msgs__srv__GenerateTrajectory_Response * msg)
{
  if (!msg) {
    return;
  }
  // trajectory
  tri_gen_msgs__msg__Trajectory__fini(&msg->trajectory);
  // total_length
  // max_velocity
  // max_curvature
  // generation_time_ms
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
tri_gen_msgs__srv__GenerateTrajectory_Response__are_equal(const tri_gen_msgs__srv__GenerateTrajectory_Response * lhs, const tri_gen_msgs__srv__GenerateTrajectory_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // trajectory
  if (!tri_gen_msgs__msg__Trajectory__are_equal(
      &(lhs->trajectory), &(rhs->trajectory)))
  {
    return false;
  }
  // total_length
  if (lhs->total_length != rhs->total_length) {
    return false;
  }
  // max_velocity
  if (lhs->max_velocity != rhs->max_velocity) {
    return false;
  }
  // max_curvature
  if (lhs->max_curvature != rhs->max_curvature) {
    return false;
  }
  // generation_time_ms
  if (lhs->generation_time_ms != rhs->generation_time_ms) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
tri_gen_msgs__srv__GenerateTrajectory_Response__copy(
  const tri_gen_msgs__srv__GenerateTrajectory_Response * input,
  tri_gen_msgs__srv__GenerateTrajectory_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // trajectory
  if (!tri_gen_msgs__msg__Trajectory__copy(
      &(input->trajectory), &(output->trajectory)))
  {
    return false;
  }
  // total_length
  output->total_length = input->total_length;
  // max_velocity
  output->max_velocity = input->max_velocity;
  // max_curvature
  output->max_curvature = input->max_curvature;
  // generation_time_ms
  output->generation_time_ms = input->generation_time_ms;
  // success
  output->success = input->success;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

tri_gen_msgs__srv__GenerateTrajectory_Response *
tri_gen_msgs__srv__GenerateTrajectory_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tri_gen_msgs__srv__GenerateTrajectory_Response * msg = (tri_gen_msgs__srv__GenerateTrajectory_Response *)allocator.allocate(sizeof(tri_gen_msgs__srv__GenerateTrajectory_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tri_gen_msgs__srv__GenerateTrajectory_Response));
  bool success = tri_gen_msgs__srv__GenerateTrajectory_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tri_gen_msgs__srv__GenerateTrajectory_Response__destroy(tri_gen_msgs__srv__GenerateTrajectory_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tri_gen_msgs__srv__GenerateTrajectory_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tri_gen_msgs__srv__GenerateTrajectory_Response__Sequence__init(tri_gen_msgs__srv__GenerateTrajectory_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tri_gen_msgs__srv__GenerateTrajectory_Response * data = NULL;

  if (size) {
    data = (tri_gen_msgs__srv__GenerateTrajectory_Response *)allocator.zero_allocate(size, sizeof(tri_gen_msgs__srv__GenerateTrajectory_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tri_gen_msgs__srv__GenerateTrajectory_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tri_gen_msgs__srv__GenerateTrajectory_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
tri_gen_msgs__srv__GenerateTrajectory_Response__Sequence__fini(tri_gen_msgs__srv__GenerateTrajectory_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      tri_gen_msgs__srv__GenerateTrajectory_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

tri_gen_msgs__srv__GenerateTrajectory_Response__Sequence *
tri_gen_msgs__srv__GenerateTrajectory_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tri_gen_msgs__srv__GenerateTrajectory_Response__Sequence * array = (tri_gen_msgs__srv__GenerateTrajectory_Response__Sequence *)allocator.allocate(sizeof(tri_gen_msgs__srv__GenerateTrajectory_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tri_gen_msgs__srv__GenerateTrajectory_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tri_gen_msgs__srv__GenerateTrajectory_Response__Sequence__destroy(tri_gen_msgs__srv__GenerateTrajectory_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tri_gen_msgs__srv__GenerateTrajectory_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tri_gen_msgs__srv__GenerateTrajectory_Response__Sequence__are_equal(const tri_gen_msgs__srv__GenerateTrajectory_Response__Sequence * lhs, const tri_gen_msgs__srv__GenerateTrajectory_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tri_gen_msgs__srv__GenerateTrajectory_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tri_gen_msgs__srv__GenerateTrajectory_Response__Sequence__copy(
  const tri_gen_msgs__srv__GenerateTrajectory_Response__Sequence * input,
  tri_gen_msgs__srv__GenerateTrajectory_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tri_gen_msgs__srv__GenerateTrajectory_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tri_gen_msgs__srv__GenerateTrajectory_Response * data =
      (tri_gen_msgs__srv__GenerateTrajectory_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tri_gen_msgs__srv__GenerateTrajectory_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tri_gen_msgs__srv__GenerateTrajectory_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tri_gen_msgs__srv__GenerateTrajectory_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
