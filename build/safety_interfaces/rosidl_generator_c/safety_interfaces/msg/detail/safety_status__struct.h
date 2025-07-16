// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from safety_interfaces:msg/SafetyStatus.idl
// generated code does not contain a copyright notice

#ifndef SAFETY_INTERFACES__MSG__DETAIL__SAFETY_STATUS__STRUCT_H_
#define SAFETY_INTERFACES__MSG__DETAIL__SAFETY_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/SafetyStatus in the package safety_interfaces.
typedef struct safety_interfaces__msg__SafetyStatus
{
  bool front_clear;
  bool back_clear;
  bool left_clear;
  bool right_clear;
} safety_interfaces__msg__SafetyStatus;

// Struct for a sequence of safety_interfaces__msg__SafetyStatus.
typedef struct safety_interfaces__msg__SafetyStatus__Sequence
{
  safety_interfaces__msg__SafetyStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} safety_interfaces__msg__SafetyStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SAFETY_INTERFACES__MSG__DETAIL__SAFETY_STATUS__STRUCT_H_
