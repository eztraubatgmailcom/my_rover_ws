// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from safety_interfaces:msg/SafetyStatus.idl
// generated code does not contain a copyright notice

#ifndef SAFETY_INTERFACES__MSG__DETAIL__SAFETY_STATUS__STRUCT_HPP_
#define SAFETY_INTERFACES__MSG__DETAIL__SAFETY_STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__safety_interfaces__msg__SafetyStatus __attribute__((deprecated))
#else
# define DEPRECATED__safety_interfaces__msg__SafetyStatus __declspec(deprecated)
#endif

namespace safety_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SafetyStatus_
{
  using Type = SafetyStatus_<ContainerAllocator>;

  explicit SafetyStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->front_clear = false;
      this->back_clear = false;
      this->left_clear = false;
      this->right_clear = false;
    }
  }

  explicit SafetyStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->front_clear = false;
      this->back_clear = false;
      this->left_clear = false;
      this->right_clear = false;
    }
  }

  // field types and members
  using _front_clear_type =
    bool;
  _front_clear_type front_clear;
  using _back_clear_type =
    bool;
  _back_clear_type back_clear;
  using _left_clear_type =
    bool;
  _left_clear_type left_clear;
  using _right_clear_type =
    bool;
  _right_clear_type right_clear;

  // setters for named parameter idiom
  Type & set__front_clear(
    const bool & _arg)
  {
    this->front_clear = _arg;
    return *this;
  }
  Type & set__back_clear(
    const bool & _arg)
  {
    this->back_clear = _arg;
    return *this;
  }
  Type & set__left_clear(
    const bool & _arg)
  {
    this->left_clear = _arg;
    return *this;
  }
  Type & set__right_clear(
    const bool & _arg)
  {
    this->right_clear = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    safety_interfaces::msg::SafetyStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const safety_interfaces::msg::SafetyStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<safety_interfaces::msg::SafetyStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<safety_interfaces::msg::SafetyStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      safety_interfaces::msg::SafetyStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<safety_interfaces::msg::SafetyStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      safety_interfaces::msg::SafetyStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<safety_interfaces::msg::SafetyStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<safety_interfaces::msg::SafetyStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<safety_interfaces::msg::SafetyStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__safety_interfaces__msg__SafetyStatus
    std::shared_ptr<safety_interfaces::msg::SafetyStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__safety_interfaces__msg__SafetyStatus
    std::shared_ptr<safety_interfaces::msg::SafetyStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SafetyStatus_ & other) const
  {
    if (this->front_clear != other.front_clear) {
      return false;
    }
    if (this->back_clear != other.back_clear) {
      return false;
    }
    if (this->left_clear != other.left_clear) {
      return false;
    }
    if (this->right_clear != other.right_clear) {
      return false;
    }
    return true;
  }
  bool operator!=(const SafetyStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SafetyStatus_

// alias to use template instance with default allocator
using SafetyStatus =
  safety_interfaces::msg::SafetyStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace safety_interfaces

#endif  // SAFETY_INTERFACES__MSG__DETAIL__SAFETY_STATUS__STRUCT_HPP_
