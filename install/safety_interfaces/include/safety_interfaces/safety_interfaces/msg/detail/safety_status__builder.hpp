// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from safety_interfaces:msg/SafetyStatus.idl
// generated code does not contain a copyright notice

#ifndef SAFETY_INTERFACES__MSG__DETAIL__SAFETY_STATUS__BUILDER_HPP_
#define SAFETY_INTERFACES__MSG__DETAIL__SAFETY_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "safety_interfaces/msg/detail/safety_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace safety_interfaces
{

namespace msg
{

namespace builder
{

class Init_SafetyStatus_right_clear
{
public:
  explicit Init_SafetyStatus_right_clear(::safety_interfaces::msg::SafetyStatus & msg)
  : msg_(msg)
  {}
  ::safety_interfaces::msg::SafetyStatus right_clear(::safety_interfaces::msg::SafetyStatus::_right_clear_type arg)
  {
    msg_.right_clear = std::move(arg);
    return std::move(msg_);
  }

private:
  ::safety_interfaces::msg::SafetyStatus msg_;
};

class Init_SafetyStatus_left_clear
{
public:
  explicit Init_SafetyStatus_left_clear(::safety_interfaces::msg::SafetyStatus & msg)
  : msg_(msg)
  {}
  Init_SafetyStatus_right_clear left_clear(::safety_interfaces::msg::SafetyStatus::_left_clear_type arg)
  {
    msg_.left_clear = std::move(arg);
    return Init_SafetyStatus_right_clear(msg_);
  }

private:
  ::safety_interfaces::msg::SafetyStatus msg_;
};

class Init_SafetyStatus_back_clear
{
public:
  explicit Init_SafetyStatus_back_clear(::safety_interfaces::msg::SafetyStatus & msg)
  : msg_(msg)
  {}
  Init_SafetyStatus_left_clear back_clear(::safety_interfaces::msg::SafetyStatus::_back_clear_type arg)
  {
    msg_.back_clear = std::move(arg);
    return Init_SafetyStatus_left_clear(msg_);
  }

private:
  ::safety_interfaces::msg::SafetyStatus msg_;
};

class Init_SafetyStatus_front_clear
{
public:
  Init_SafetyStatus_front_clear()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SafetyStatus_back_clear front_clear(::safety_interfaces::msg::SafetyStatus::_front_clear_type arg)
  {
    msg_.front_clear = std::move(arg);
    return Init_SafetyStatus_back_clear(msg_);
  }

private:
  ::safety_interfaces::msg::SafetyStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::safety_interfaces::msg::SafetyStatus>()
{
  return safety_interfaces::msg::builder::Init_SafetyStatus_front_clear();
}

}  // namespace safety_interfaces

#endif  // SAFETY_INTERFACES__MSG__DETAIL__SAFETY_STATUS__BUILDER_HPP_
