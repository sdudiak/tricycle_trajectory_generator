// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tri_gen_msgs:msg/Trajectory.idl
// generated code does not contain a copyright notice
#include "tri_gen_msgs/msg/detail/trajectory__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `states`
#include "tri_gen_msgs/msg/detail/state__functions.h"
// Member `controls`
#include "tri_gen_msgs/msg/detail/control__functions.h"

bool
tri_gen_msgs__msg__Trajectory__init(tri_gen_msgs__msg__Trajectory * msg)
{
  if (!msg) {
    return false;
  }
  // states
  if (!tri_gen_msgs__msg__State__Sequence__init(&msg->states, 0)) {
    tri_gen_msgs__msg__Trajectory__fini(msg);
    return false;
  }
  // controls
  if (!tri_gen_msgs__msg__Control__Sequence__init(&msg->controls, 0)) {
    tri_gen_msgs__msg__Trajectory__fini(msg);
    return false;
  }
  return true;
}

void
tri_gen_msgs__msg__Trajectory__fini(tri_gen_msgs__msg__Trajectory * msg)
{
  if (!msg) {
    return;
  }
  // states
  tri_gen_msgs__msg__State__Sequence__fini(&msg->states);
  // controls
  tri_gen_msgs__msg__Control__Sequence__fini(&msg->controls);
}

bool
tri_gen_msgs__msg__Trajectory__are_equal(const tri_gen_msgs__msg__Trajectory * lhs, const tri_gen_msgs__msg__Trajectory * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // states
  if (!tri_gen_msgs__msg__State__Sequence__are_equal(
      &(lhs->states), &(rhs->states)))
  {
    return false;
  }
  // controls
  if (!tri_gen_msgs__msg__Control__Sequence__are_equal(
      &(lhs->controls), &(rhs->controls)))
  {
    return false;
  }
  return true;
}

bool
tri_gen_msgs__msg__Trajectory__copy(
  const tri_gen_msgs__msg__Trajectory * input,
  tri_gen_msgs__msg__Trajectory * output)
{
  if (!input || !output) {
    return false;
  }
  // states
  if (!tri_gen_msgs__msg__State__Sequence__copy(
      &(input->states), &(output->states)))
  {
    return false;
  }
  // controls
  if (!tri_gen_msgs__msg__Control__Sequence__copy(
      &(input->controls), &(output->controls)))
  {
    return false;
  }
  return true;
}

tri_gen_msgs__msg__Trajectory *
tri_gen_msgs__msg__Trajectory__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tri_gen_msgs__msg__Trajectory * msg = (tri_gen_msgs__msg__Trajectory *)allocator.allocate(sizeof(tri_gen_msgs__msg__Trajectory), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tri_gen_msgs__msg__Trajectory));
  bool success = tri_gen_msgs__msg__Trajectory__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tri_gen_msgs__msg__Trajectory__destroy(tri_gen_msgs__msg__Trajectory * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tri_gen_msgs__msg__Trajectory__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tri_gen_msgs__msg__Trajectory__Sequence__init(tri_gen_msgs__msg__Trajectory__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tri_gen_msgs__msg__Trajectory * data = NULL;

  if (size) {
    data = (tri_gen_msgs__msg__Trajectory *)allocator.zero_allocate(size, sizeof(tri_gen_msgs__msg__Trajectory), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tri_gen_msgs__msg__Trajectory__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tri_gen_msgs__msg__Trajectory__fini(&data[i - 1]);
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
tri_gen_msgs__msg__Trajectory__Sequence__fini(tri_gen_msgs__msg__Trajectory__Sequence * array)
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
      tri_gen_msgs__msg__Trajectory__fini(&array->data[i]);
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

tri_gen_msgs__msg__Trajectory__Sequence *
tri_gen_msgs__msg__Trajectory__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tri_gen_msgs__msg__Trajectory__Sequence * array = (tri_gen_msgs__msg__Trajectory__Sequence *)allocator.allocate(sizeof(tri_gen_msgs__msg__Trajectory__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tri_gen_msgs__msg__Trajectory__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tri_gen_msgs__msg__Trajectory__Sequence__destroy(tri_gen_msgs__msg__Trajectory__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tri_gen_msgs__msg__Trajectory__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tri_gen_msgs__msg__Trajectory__Sequence__are_equal(const tri_gen_msgs__msg__Trajectory__Sequence * lhs, const tri_gen_msgs__msg__Trajectory__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tri_gen_msgs__msg__Trajectory__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tri_gen_msgs__msg__Trajectory__Sequence__copy(
  const tri_gen_msgs__msg__Trajectory__Sequence * input,
  tri_gen_msgs__msg__Trajectory__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tri_gen_msgs__msg__Trajectory);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tri_gen_msgs__msg__Trajectory * data =
      (tri_gen_msgs__msg__Trajectory *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tri_gen_msgs__msg__Trajectory__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tri_gen_msgs__msg__Trajectory__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tri_gen_msgs__msg__Trajectory__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
