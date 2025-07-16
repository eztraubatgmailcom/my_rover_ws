// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from safety_interfaces:msg/SafetyStatus.idl
// generated code does not contain a copyright notice
#include "safety_interfaces/msg/detail/safety_status__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "safety_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "safety_interfaces/msg/detail/safety_status__struct.h"
#include "safety_interfaces/msg/detail/safety_status__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _SafetyStatus__ros_msg_type = safety_interfaces__msg__SafetyStatus;

static bool _SafetyStatus__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _SafetyStatus__ros_msg_type * ros_message = static_cast<const _SafetyStatus__ros_msg_type *>(untyped_ros_message);
  // Field name: front_clear
  {
    cdr << (ros_message->front_clear ? true : false);
  }

  // Field name: back_clear
  {
    cdr << (ros_message->back_clear ? true : false);
  }

  // Field name: left_clear
  {
    cdr << (ros_message->left_clear ? true : false);
  }

  // Field name: right_clear
  {
    cdr << (ros_message->right_clear ? true : false);
  }

  return true;
}

static bool _SafetyStatus__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _SafetyStatus__ros_msg_type * ros_message = static_cast<_SafetyStatus__ros_msg_type *>(untyped_ros_message);
  // Field name: front_clear
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->front_clear = tmp ? true : false;
  }

  // Field name: back_clear
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->back_clear = tmp ? true : false;
  }

  // Field name: left_clear
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->left_clear = tmp ? true : false;
  }

  // Field name: right_clear
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->right_clear = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_safety_interfaces
size_t get_serialized_size_safety_interfaces__msg__SafetyStatus(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _SafetyStatus__ros_msg_type * ros_message = static_cast<const _SafetyStatus__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name front_clear
  {
    size_t item_size = sizeof(ros_message->front_clear);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name back_clear
  {
    size_t item_size = sizeof(ros_message->back_clear);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name left_clear
  {
    size_t item_size = sizeof(ros_message->left_clear);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name right_clear
  {
    size_t item_size = sizeof(ros_message->right_clear);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _SafetyStatus__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_safety_interfaces__msg__SafetyStatus(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_safety_interfaces
size_t max_serialized_size_safety_interfaces__msg__SafetyStatus(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: front_clear
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: back_clear
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: left_clear
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: right_clear
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = safety_interfaces__msg__SafetyStatus;
    is_plain =
      (
      offsetof(DataType, right_clear) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _SafetyStatus__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_safety_interfaces__msg__SafetyStatus(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_SafetyStatus = {
  "safety_interfaces::msg",
  "SafetyStatus",
  _SafetyStatus__cdr_serialize,
  _SafetyStatus__cdr_deserialize,
  _SafetyStatus__get_serialized_size,
  _SafetyStatus__max_serialized_size
};

static rosidl_message_type_support_t _SafetyStatus__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_SafetyStatus,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, safety_interfaces, msg, SafetyStatus)() {
  return &_SafetyStatus__type_support;
}

#if defined(__cplusplus)
}
#endif
