// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tri_gen_msgs:msg/Trajectory.idl
// generated code does not contain a copyright notice

#ifndef TRI_GEN_MSGS__MSG__DETAIL__TRAJECTORY__STRUCT_HPP_
#define TRI_GEN_MSGS__MSG__DETAIL__TRAJECTORY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'states'
#include "tri_gen_msgs/msg/detail/state__struct.hpp"
// Member 'controls'
#include "tri_gen_msgs/msg/detail/control__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__tri_gen_msgs__msg__Trajectory __attribute__((deprecated))
#else
# define DEPRECATED__tri_gen_msgs__msg__Trajectory __declspec(deprecated)
#endif

namespace tri_gen_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Trajectory_
{
  using Type = Trajectory_<ContainerAllocator>;

  explicit Trajectory_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit Trajectory_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _states_type =
    std::vector<tri_gen_msgs::msg::State_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tri_gen_msgs::msg::State_<ContainerAllocator>>>;
  _states_type states;
  using _controls_type =
    std::vector<tri_gen_msgs::msg::Control_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tri_gen_msgs::msg::Control_<ContainerAllocator>>>;
  _controls_type controls;

  // setters for named parameter idiom
  Type & set__states(
    const std::vector<tri_gen_msgs::msg::State_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tri_gen_msgs::msg::State_<ContainerAllocator>>> & _arg)
  {
    this->states = _arg;
    return *this;
  }
  Type & set__controls(
    const std::vector<tri_gen_msgs::msg::Control_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tri_gen_msgs::msg::Control_<ContainerAllocator>>> & _arg)
  {
    this->controls = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tri_gen_msgs::msg::Trajectory_<ContainerAllocator> *;
  using ConstRawPtr =
    const tri_gen_msgs::msg::Trajectory_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tri_gen_msgs::msg::Trajectory_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tri_gen_msgs::msg::Trajectory_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tri_gen_msgs::msg::Trajectory_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tri_gen_msgs::msg::Trajectory_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tri_gen_msgs::msg::Trajectory_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tri_gen_msgs::msg::Trajectory_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tri_gen_msgs::msg::Trajectory_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tri_gen_msgs::msg::Trajectory_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tri_gen_msgs__msg__Trajectory
    std::shared_ptr<tri_gen_msgs::msg::Trajectory_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tri_gen_msgs__msg__Trajectory
    std::shared_ptr<tri_gen_msgs::msg::Trajectory_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Trajectory_ & other) const
  {
    if (this->states != other.states) {
      return false;
    }
    if (this->controls != other.controls) {
      return false;
    }
    return true;
  }
  bool operator!=(const Trajectory_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Trajectory_

// alias to use template instance with default allocator
using Trajectory =
  tri_gen_msgs::msg::Trajectory_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace tri_gen_msgs

#endif  // TRI_GEN_MSGS__MSG__DETAIL__TRAJECTORY__STRUCT_HPP_
