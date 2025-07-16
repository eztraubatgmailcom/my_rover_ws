// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from safety_interfaces:msg/SafetyStatus.idl
// generated code does not contain a copyright notice
#include "safety_interfaces/msg/detail/safety_status__rosidl_typesupport_fastrtps_cpp.hpp"
#include "safety_interfaces/msg/detail/safety_status__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace safety_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_safety_interfaces
cdr_serialize(
  const safety_interfaces::msg::SafetyStatus & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: front_clear
  cdr << (ros_message.front_clear ? true : false);
  // Member: back_clear
  cdr << (ros_message.back_clear ? true : false);
  // Member: left_clear
  cdr << (ros_message.left_clear ? true : false);
  // Member: right_clear
  cdr << (ros_message.right_clear ? true : false);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_safety_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  safety_interfaces::msg::SafetyStatus & ros_message)
{
  // Member: front_clear
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.front_clear = tmp ? true : false;
  }

  // Member: back_clear
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.back_clear = tmp ? true : false;
  }

  // Member: left_clear
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.left_clear = tmp ? true : false;
  }

  // Member: right_clear
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.right_clear = tmp ? true : false;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_safety_interfaces
get_serialized_size(
  const safety_interfaces::msg::SafetyStatus & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: front_clear
  {
    size_t item_size = sizeof(ros_message.front_clear);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: back_clear
  {
    size_t item_size = sizeof(ros_message.back_clear);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: left_clear
  {
    size_t item_size = sizeof(ros_message.left_clear);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: right_clear
  {
    size_t item_size = sizeof(ros_message.right_clear);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_safety_interfaces
max_serialized_size_SafetyStatus(
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


  // Member: front_clear
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: back_clear
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: left_clear
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: right_clear
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
    using DataType = safety_interfaces::msg::SafetyStatus;
    is_plain =
      (
      offsetof(DataType, right_clear) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _SafetyStatus__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const safety_interfaces::msg::SafetyStatus *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _SafetyStatus__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<safety_interfaces::msg::SafetyStatus *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _SafetyStatus__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const safety_interfaces::msg::SafetyStatus *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _SafetyStatus__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_SafetyStatus(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _SafetyStatus__callbacks = {
  "safety_interfaces::msg",
  "SafetyStatus",
  _SafetyStatus__cdr_serialize,
  _SafetyStatus__cdr_deserialize,
  _SafetyStatus__get_serialized_size,
  _SafetyStatus__max_serialized_size
};

static rosidl_message_type_support_t _SafetyStatus__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_SafetyStatus__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace safety_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_safety_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<safety_interfaces::msg::SafetyStatus>()
{
  return &safety_interfaces::msg::typesupport_fastrtps_cpp::_SafetyStatus__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, safety_interfaces, msg, SafetyStatus)() {
  return &safety_interfaces::msg::typesupport_fastrtps_cpp::_SafetyStatus__handle;
}

#ifdef __cplusplus
}
#endif
