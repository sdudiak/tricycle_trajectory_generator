// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tri_gen_msgs:msg/Control.idl
// generated code does not contain a copyright notice

#ifndef TRI_GEN_MSGS__MSG__DETAIL__CONTROL__STRUCT_HPP_
#define TRI_GEN_MSGS__MSG__DETAIL__CONTROL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'duration'
#include "builtin_interfaces/msg/detail/duration__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__tri_gen_msgs__msg__Control __attribute__((deprecated))
#else
# define DEPRECATED__tri_gen_msgs__msg__Control __declspec(deprecated)
#endif

namespace tri_gen_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Control_
{
  using Type = Control_<ContainerAllocator>;

  explicit Control_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : duration(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->omega_phi = 0.0;
      this->a = 0.0;
    }
  }

  explicit Control_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : duration(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->omega_phi = 0.0;
      this->a = 0.0;
    }
  }

  // field types and members
  using _omega_phi_type =
    double;
  _omega_phi_type omega_phi;
  using _a_type =
    double;
  _a_type a;
  using _duration_type =
    builtin_interfaces::msg::Duration_<ContainerAllocator>;
  _duration_type duration;

  // setters for named parameter idiom
  Type & set__omega_phi(
    const double & _arg)
  {
    this->omega_phi = _arg;
    return *this;
  }
  Type & set__a(
    const double & _arg)
  {
    this->a = _arg;
    return *this;
  }
  Type & set__duration(
    const builtin_interfaces::msg::Duration_<ContainerAllocator> & _arg)
  {
    this->duration = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tri_gen_msgs::msg::Control_<ContainerAllocator> *;
  using ConstRawPtr =
    const tri_gen_msgs::msg::Control_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tri_gen_msgs::msg::Control_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tri_gen_msgs::msg::Control_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tri_gen_msgs::msg::Control_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tri_gen_msgs::msg::Control_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tri_gen_msgs::msg::Control_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tri_gen_msgs::msg::Control_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tri_gen_msgs::msg::Control_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tri_gen_msgs::msg::Control_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tri_gen_msgs__msg__Control
    std::shared_ptr<tri_gen_msgs::msg::Control_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tri_gen_msgs__msg__Control
    std::shared_ptr<tri_gen_msgs::msg::Control_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Control_ & other) const
  {
    if (this->omega_phi != other.omega_phi) {
      return false;
    }
    if (this->a != other.a) {
      return false;
    }
    if (this->duration != other.duration) {
      return false;
    }
    return true;
  }
  bool operator!=(const Control_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Control_

// alias to use template instance with default allocator
using Control =
  tri_gen_msgs::msg::Control_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace tri_gen_msgs

#endif  // TRI_GEN_MSGS__MSG__DETAIL__CONTROL__STRUCT_HPP_
