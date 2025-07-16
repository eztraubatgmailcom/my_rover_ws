// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from safety_interfaces:msg/SafetyStatus.idl
// generated code does not contain a copyright notice

#ifndef SAFETY_INTERFACES__MSG__DETAIL__SAFETY_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define SAFETY_INTERFACES__MSG__DETAIL__SAFETY_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "safety_interfaces/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "safety_interfaces/msg/detail/safety_status__struct.hpp"

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

#include "fastcdr/Cdr.h"

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
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_safety_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  safety_interfaces::msg::SafetyStatus & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_safety_interfaces
get_serialized_size(
  const safety_interfaces::msg::SafetyStatus & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_safety_interfaces
max_serialized_size_SafetyStatus(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace safety_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_safety_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, safety_interfaces, msg, SafetyStatus)();

#ifdef __cplusplus
}
#endif

#endif  // SAFETY_INTERFACES__MSG__DETAIL__SAFETY_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
