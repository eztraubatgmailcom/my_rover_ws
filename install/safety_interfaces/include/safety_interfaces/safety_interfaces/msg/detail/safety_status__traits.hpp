// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from safety_interfaces:msg/SafetyStatus.idl
// generated code does not contain a copyright notice

#ifndef SAFETY_INTERFACES__MSG__DETAIL__SAFETY_STATUS__TRAITS_HPP_
#define SAFETY_INTERFACES__MSG__DETAIL__SAFETY_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "safety_interfaces/msg/detail/safety_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace safety_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const SafetyStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: front_clear
  {
    out << "front_clear: ";
    rosidl_generator_traits::value_to_yaml(msg.front_clear, out);
    out << ", ";
  }

  // member: back_clear
  {
    out << "back_clear: ";
    rosidl_generator_traits::value_to_yaml(msg.back_clear, out);
    out << ", ";
  }

  // member: left_clear
  {
    out << "left_clear: ";
    rosidl_generator_traits::value_to_yaml(msg.left_clear, out);
    out << ", ";
  }

  // member: right_clear
  {
    out << "right_clear: ";
    rosidl_generator_traits::value_to_yaml(msg.right_clear, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SafetyStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: front_clear
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "front_clear: ";
    rosidl_generator_traits::value_to_yaml(msg.front_clear, out);
    out << "\n";
  }

  // member: back_clear
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "back_clear: ";
    rosidl_generator_traits::value_to_yaml(msg.back_clear, out);
    out << "\n";
  }

  // member: left_clear
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left_clear: ";
    rosidl_generator_traits::value_to_yaml(msg.left_clear, out);
    out << "\n";
  }

  // member: right_clear
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right_clear: ";
    rosidl_generator_traits::value_to_yaml(msg.right_clear, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SafetyStatus & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace safety_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use safety_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const safety_interfaces::msg::SafetyStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  safety_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use safety_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const safety_interfaces::msg::SafetyStatus & msg)
{
  return safety_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<safety_interfaces::msg::SafetyStatus>()
{
  return "safety_interfaces::msg::SafetyStatus";
}

template<>
inline const char * name<safety_interfaces::msg::SafetyStatus>()
{
  return "safety_interfaces/msg/SafetyStatus";
}

template<>
struct has_fixed_size<safety_interfaces::msg::SafetyStatus>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<safety_interfaces::msg::SafetyStatus>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<safety_interfaces::msg::SafetyStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SAFETY_INTERFACES__MSG__DETAIL__SAFETY_STATUS__TRAITS_HPP_
