// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from safety_interfaces:msg/SafetyStatus.idl
// generated code does not contain a copyright notice
#include "safety_interfaces/msg/detail/safety_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
safety_interfaces__msg__SafetyStatus__init(safety_interfaces__msg__SafetyStatus * msg)
{
  if (!msg) {
    return false;
  }
  // front_clear
  // back_clear
  // left_clear
  // right_clear
  return true;
}

void
safety_interfaces__msg__SafetyStatus__fini(safety_interfaces__msg__SafetyStatus * msg)
{
  if (!msg) {
    return;
  }
  // front_clear
  // back_clear
  // left_clear
  // right_clear
}

bool
safety_interfaces__msg__SafetyStatus__are_equal(const safety_interfaces__msg__SafetyStatus * lhs, const safety_interfaces__msg__SafetyStatus * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // front_clear
  if (lhs->front_clear != rhs->front_clear) {
    return false;
  }
  // back_clear
  if (lhs->back_clear != rhs->back_clear) {
    return false;
  }
  // left_clear
  if (lhs->left_clear != rhs->left_clear) {
    return false;
  }
  // right_clear
  if (lhs->right_clear != rhs->right_clear) {
    return false;
  }
  return true;
}

bool
safety_interfaces__msg__SafetyStatus__copy(
  const safety_interfaces__msg__SafetyStatus * input,
  safety_interfaces__msg__SafetyStatus * output)
{
  if (!input || !output) {
    return false;
  }
  // front_clear
  output->front_clear = input->front_clear;
  // back_clear
  output->back_clear = input->back_clear;
  // left_clear
  output->left_clear = input->left_clear;
  // right_clear
  output->right_clear = input->right_clear;
  return true;
}

safety_interfaces__msg__SafetyStatus *
safety_interfaces__msg__SafetyStatus__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  safety_interfaces__msg__SafetyStatus * msg = (safety_interfaces__msg__SafetyStatus *)allocator.allocate(sizeof(safety_interfaces__msg__SafetyStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(safety_interfaces__msg__SafetyStatus));
  bool success = safety_interfaces__msg__SafetyStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
safety_interfaces__msg__SafetyStatus__destroy(safety_interfaces__msg__SafetyStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    safety_interfaces__msg__SafetyStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
safety_interfaces__msg__SafetyStatus__Sequence__init(safety_interfaces__msg__SafetyStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  safety_interfaces__msg__SafetyStatus * data = NULL;

  if (size) {
    data = (safety_interfaces__msg__SafetyStatus *)allocator.zero_allocate(size, sizeof(safety_interfaces__msg__SafetyStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = safety_interfaces__msg__SafetyStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        safety_interfaces__msg__SafetyStatus__fini(&data[i - 1]);
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
safety_interfaces__msg__SafetyStatus__Sequence__fini(safety_interfaces__msg__SafetyStatus__Sequence * array)
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
      safety_interfaces__msg__SafetyStatus__fini(&array->data[i]);
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

safety_interfaces__msg__SafetyStatus__Sequence *
safety_interfaces__msg__SafetyStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  safety_interfaces__msg__SafetyStatus__Sequence * array = (safety_interfaces__msg__SafetyStatus__Sequence *)allocator.allocate(sizeof(safety_interfaces__msg__SafetyStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = safety_interfaces__msg__SafetyStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
safety_interfaces__msg__SafetyStatus__Sequence__destroy(safety_interfaces__msg__SafetyStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    safety_interfaces__msg__SafetyStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
safety_interfaces__msg__SafetyStatus__Sequence__are_equal(const safety_interfaces__msg__SafetyStatus__Sequence * lhs, const safety_interfaces__msg__SafetyStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!safety_interfaces__msg__SafetyStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
safety_interfaces__msg__SafetyStatus__Sequence__copy(
  const safety_interfaces__msg__SafetyStatus__Sequence * input,
  safety_interfaces__msg__SafetyStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(safety_interfaces__msg__SafetyStatus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    safety_interfaces__msg__SafetyStatus * data =
      (safety_interfaces__msg__SafetyStatus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!safety_interfaces__msg__SafetyStatus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          safety_interfaces__msg__SafetyStatus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!safety_interfaces__msg__SafetyStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
