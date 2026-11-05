// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tri_gen_msgs:msg/State.idl
// generated code does not contain a copyright notice

#ifndef TRI_GEN_MSGS__MSG__DETAIL__STATE__STRUCT_HPP_
#define TRI_GEN_MSGS__MSG__DETAIL__STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'stamp_from_start'
#include "builtin_interfaces/msg/detail/duration__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__tri_gen_msgs__msg__State __attribute__((deprecated))
#else
# define DEPRECATED__tri_gen_msgs__msg__State __declspec(deprecated)
#endif

namespace tri_gen_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct State_
{
  using Type = State_<ContainerAllocator>;

  explicit State_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp_from_start(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
      this->theta = 0.0;
      this->phi = 0.0;
      this->omega_phi = 0.0;
      this->v = 0.0;
    }
  }

  explicit State_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp_from_start(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
      this->theta = 0.0;
      this->phi = 0.0;
      this->omega_phi = 0.0;
      this->v = 0.0;
    }
  }

  // field types and members
  using _x_type =
    double;
  _x_type x;
  using _y_type =
    double;
  _y_type y;
  using _theta_type =
    double;
  _theta_type theta;
  using _phi_type =
    double;
  _phi_type phi;
  using _omega_phi_type =
    double;
  _omega_phi_type omega_phi;
  using _v_type =
    double;
  _v_type v;
  using _stamp_from_start_type =
    builtin_interfaces::msg::Duration_<ContainerAllocator>;
  _stamp_from_start_type stamp_from_start;

  // setters for named parameter idiom
  Type & set__x(
    const double & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const double & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__theta(
    const double & _arg)
  {
    this->theta = _arg;
    return *this;
  }
  Type & set__phi(
    const double & _arg)
  {
    this->phi = _arg;
    return *this;
  }
  Type & set__omega_phi(
    const double & _arg)
  {
    this->omega_phi = _arg;
    return *this;
  }
  Type & set__v(
    const double & _arg)
  {
    this->v = _arg;
    return *this;
  }
  Type & set__stamp_from_start(
    const builtin_interfaces::msg::Duration_<ContainerAllocator> & _arg)
  {
    this->stamp_from_start = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tri_gen_msgs::msg::State_<ContainerAllocator> *;
  using ConstRawPtr =
    const tri_gen_msgs::msg::State_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tri_gen_msgs::msg::State_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tri_gen_msgs::msg::State_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tri_gen_msgs::msg::State_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tri_gen_msgs::msg::State_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tri_gen_msgs::msg::State_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tri_gen_msgs::msg::State_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tri_gen_msgs::msg::State_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tri_gen_msgs::msg::State_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tri_gen_msgs__msg__State
    std::shared_ptr<tri_gen_msgs::msg::State_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tri_gen_msgs__msg__State
    std::shared_ptr<tri_gen_msgs::msg::State_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const State_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->theta != other.theta) {
      return false;
    }
    if (this->phi != other.phi) {
      return false;
    }
    if (this->omega_phi != other.omega_phi) {
      return false;
    }
    if (this->v != other.v) {
      return false;
    }
    if (this->stamp_from_start != other.stamp_from_start) {
      return false;
    }
    return true;
  }
  bool operator!=(const State_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct State_

// alias to use template instance with default allocator
using State =
  tri_gen_msgs::msg::State_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace tri_gen_msgs

#endif  // TRI_GEN_MSGS__MSG__DETAIL__STATE__STRUCT_HPP_
