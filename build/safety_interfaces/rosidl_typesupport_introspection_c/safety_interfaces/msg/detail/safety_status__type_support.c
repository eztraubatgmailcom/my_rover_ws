// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from safety_interfaces:msg/SafetyStatus.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "safety_interfaces/msg/detail/safety_status__rosidl_typesupport_introspection_c.h"
#include "safety_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "safety_interfaces/msg/detail/safety_status__functions.h"
#include "safety_interfaces/msg/detail/safety_status__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void safety_interfaces__msg__SafetyStatus__rosidl_typesupport_introspection_c__SafetyStatus_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  safety_interfaces__msg__SafetyStatus__init(message_memory);
}

void safety_interfaces__msg__SafetyStatus__rosidl_typesupport_introspection_c__SafetyStatus_fini_function(void * message_memory)
{
  safety_interfaces__msg__SafetyStatus__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember safety_interfaces__msg__SafetyStatus__rosidl_typesupport_introspection_c__SafetyStatus_message_member_array[4] = {
  {
    "front_clear",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(safety_interfaces__msg__SafetyStatus, front_clear),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "back_clear",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(safety_interfaces__msg__SafetyStatus, back_clear),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "left_clear",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(safety_interfaces__msg__SafetyStatus, left_clear),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "right_clear",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(safety_interfaces__msg__SafetyStatus, right_clear),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers safety_interfaces__msg__SafetyStatus__rosidl_typesupport_introspection_c__SafetyStatus_message_members = {
  "safety_interfaces__msg",  // message namespace
  "SafetyStatus",  // message name
  4,  // number of fields
  sizeof(safety_interfaces__msg__SafetyStatus),
  safety_interfaces__msg__SafetyStatus__rosidl_typesupport_introspection_c__SafetyStatus_message_member_array,  // message members
  safety_interfaces__msg__SafetyStatus__rosidl_typesupport_introspection_c__SafetyStatus_init_function,  // function to initialize message memory (memory has to be allocated)
  safety_interfaces__msg__SafetyStatus__rosidl_typesupport_introspection_c__SafetyStatus_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t safety_interfaces__msg__SafetyStatus__rosidl_typesupport_introspection_c__SafetyStatus_message_type_support_handle = {
  0,
  &safety_interfaces__msg__SafetyStatus__rosidl_typesupport_introspection_c__SafetyStatus_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_safety_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, safety_interfaces, msg, SafetyStatus)() {
  if (!safety_interfaces__msg__SafetyStatus__rosidl_typesupport_introspection_c__SafetyStatus_message_type_support_handle.typesupport_identifier) {
    safety_interfaces__msg__SafetyStatus__rosidl_typesupport_introspection_c__SafetyStatus_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &safety_interfaces__msg__SafetyStatus__rosidl_typesupport_introspection_c__SafetyStatus_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
