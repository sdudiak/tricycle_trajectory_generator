// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tri_gen_msgs:srv/GenerateTrajectory.idl
// generated code does not contain a copyright notice

#ifndef TRI_GEN_MSGS__SRV__DETAIL__GENERATE_TRAJECTORY__STRUCT_HPP_
#define TRI_GEN_MSGS__SRV__DETAIL__GENERATE_TRAJECTORY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'start'
// Member 'goal'
#include "tri_gen_msgs/msg/detail/state__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__tri_gen_msgs__srv__GenerateTrajectory_Request __attribute__((deprecated))
#else
# define DEPRECATED__tri_gen_msgs__srv__GenerateTrajectory_Request __declspec(deprecated)
#endif

namespace tri_gen_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GenerateTrajectory_Request_
{
  using Type = GenerateTrajectory_Request_<ContainerAllocator>;

  explicit GenerateTrajectory_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : start(_init),
    goal(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->dt = 0.0;
      this->phi_min = 0.0;
      this->phi_max = 0.0;
      this->omega_phi_min = 0.0;
      this->omega_phi_max = 0.0;
      this->v_min = 0.0;
      this->v_max = 0.0;
      this->a_min = 0.0;
      this->a_max = 0.0;
    }
  }

  explicit GenerateTrajectory_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : start(_alloc, _init),
    goal(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->dt = 0.0;
      this->phi_min = 0.0;
      this->phi_max = 0.0;
      this->omega_phi_min = 0.0;
      this->omega_phi_max = 0.0;
      this->v_min = 0.0;
      this->v_max = 0.0;
      this->a_min = 0.0;
      this->a_max = 0.0;
    }
  }

  // field types and members
  using _start_type =
    tri_gen_msgs::msg::State_<ContainerAllocator>;
  _start_type start;
  using _goal_type =
    tri_gen_msgs::msg::State_<ContainerAllocator>;
  _goal_type goal;
  using _dt_type =
    double;
  _dt_type dt;
  using _phi_min_type =
    double;
  _phi_min_type phi_min;
  using _phi_max_type =
    double;
  _phi_max_type phi_max;
  using _omega_phi_min_type =
    double;
  _omega_phi_min_type omega_phi_min;
  using _omega_phi_max_type =
    double;
  _omega_phi_max_type omega_phi_max;
  using _v_min_type =
    double;
  _v_min_type v_min;
  using _v_max_type =
    double;
  _v_max_type v_max;
  using _a_min_type =
    double;
  _a_min_type a_min;
  using _a_max_type =
    double;
  _a_max_type a_max;

  // setters for named parameter idiom
  Type & set__start(
    const tri_gen_msgs::msg::State_<ContainerAllocator> & _arg)
  {
    this->start = _arg;
    return *this;
  }
  Type & set__goal(
    const tri_gen_msgs::msg::State_<ContainerAllocator> & _arg)
  {
    this->goal = _arg;
    return *this;
  }
  Type & set__dt(
    const double & _arg)
  {
    this->dt = _arg;
    return *this;
  }
  Type & set__phi_min(
    const double & _arg)
  {
    this->phi_min = _arg;
    return *this;
  }
  Type & set__phi_max(
    const double & _arg)
  {
    this->phi_max = _arg;
    return *this;
  }
  Type & set__omega_phi_min(
    const double & _arg)
  {
    this->omega_phi_min = _arg;
    return *this;
  }
  Type & set__omega_phi_max(
    const double & _arg)
  {
    this->omega_phi_max = _arg;
    return *this;
  }
  Type & set__v_min(
    const double & _arg)
  {
    this->v_min = _arg;
    return *this;
  }
  Type & set__v_max(
    const double & _arg)
  {
    this->v_max = _arg;
    return *this;
  }
  Type & set__a_min(
    const double & _arg)
  {
    this->a_min = _arg;
    return *this;
  }
  Type & set__a_max(
    const double & _arg)
  {
    this->a_max = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tri_gen_msgs::srv::GenerateTrajectory_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const tri_gen_msgs::srv::GenerateTrajectory_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tri_gen_msgs::srv::GenerateTrajectory_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tri_gen_msgs::srv::GenerateTrajectory_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tri_gen_msgs::srv::GenerateTrajectory_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tri_gen_msgs::srv::GenerateTrajectory_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tri_gen_msgs::srv::GenerateTrajectory_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tri_gen_msgs::srv::GenerateTrajectory_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tri_gen_msgs::srv::GenerateTrajectory_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tri_gen_msgs::srv::GenerateTrajectory_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tri_gen_msgs__srv__GenerateTrajectory_Request
    std::shared_ptr<tri_gen_msgs::srv::GenerateTrajectory_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tri_gen_msgs__srv__GenerateTrajectory_Request
    std::shared_ptr<tri_gen_msgs::srv::GenerateTrajectory_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GenerateTrajectory_Request_ & other) const
  {
    if (this->start != other.start) {
      return false;
    }
    if (this->goal != other.goal) {
      return false;
    }
    if (this->dt != other.dt) {
      return false;
    }
    if (this->phi_min != other.phi_min) {
      return false;
    }
    if (this->phi_max != other.phi_max) {
      return false;
    }
    if (this->omega_phi_min != other.omega_phi_min) {
      return false;
    }
    if (this->omega_phi_max != other.omega_phi_max) {
      return false;
    }
    if (this->v_min != other.v_min) {
      return false;
    }
    if (this->v_max != other.v_max) {
      return false;
    }
    if (this->a_min != other.a_min) {
      return false;
    }
    if (this->a_max != other.a_max) {
      return false;
    }
    return true;
  }
  bool operator!=(const GenerateTrajectory_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GenerateTrajectory_Request_

// alias to use template instance with default allocator
using GenerateTrajectory_Request =
  tri_gen_msgs::srv::GenerateTrajectory_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace tri_gen_msgs


// Include directives for member types
// Member 'trajectory'
#include "tri_gen_msgs/msg/detail/trajectory__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__tri_gen_msgs__srv__GenerateTrajectory_Response __attribute__((deprecated))
#else
# define DEPRECATED__tri_gen_msgs__srv__GenerateTrajectory_Response __declspec(deprecated)
#endif

namespace tri_gen_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GenerateTrajectory_Response_
{
  using Type = GenerateTrajectory_Response_<ContainerAllocator>;

  explicit GenerateTrajectory_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : trajectory(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->total_length = 0.0;
      this->max_velocity = 0.0;
      this->max_curvature = 0.0;
      this->generation_time_ms = 0.0;
      this->success = false;
      this->message = "";
    }
  }

  explicit GenerateTrajectory_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : trajectory(_alloc, _init),
    message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->total_length = 0.0;
      this->max_velocity = 0.0;
      this->max_curvature = 0.0;
      this->generation_time_ms = 0.0;
      this->success = false;
      this->message = "";
    }
  }

  // field types and members
  using _trajectory_type =
    tri_gen_msgs::msg::Trajectory_<ContainerAllocator>;
  _trajectory_type trajectory;
  using _total_length_type =
    double;
  _total_length_type total_length;
  using _max_velocity_type =
    double;
  _max_velocity_type max_velocity;
  using _max_curvature_type =
    double;
  _max_curvature_type max_curvature;
  using _generation_time_ms_type =
    double;
  _generation_time_ms_type generation_time_ms;
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__trajectory(
    const tri_gen_msgs::msg::Trajectory_<ContainerAllocator> & _arg)
  {
    this->trajectory = _arg;
    return *this;
  }
  Type & set__total_length(
    const double & _arg)
  {
    this->total_length = _arg;
    return *this;
  }
  Type & set__max_velocity(
    const double & _arg)
  {
    this->max_velocity = _arg;
    return *this;
  }
  Type & set__max_curvature(
    const double & _arg)
  {
    this->max_curvature = _arg;
    return *this;
  }
  Type & set__generation_time_ms(
    const double & _arg)
  {
    this->generation_time_ms = _arg;
    return *this;
  }
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tri_gen_msgs::srv::GenerateTrajectory_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const tri_gen_msgs::srv::GenerateTrajectory_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tri_gen_msgs::srv::GenerateTrajectory_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tri_gen_msgs::srv::GenerateTrajectory_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tri_gen_msgs::srv::GenerateTrajectory_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tri_gen_msgs::srv::GenerateTrajectory_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tri_gen_msgs::srv::GenerateTrajectory_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tri_gen_msgs::srv::GenerateTrajectory_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tri_gen_msgs::srv::GenerateTrajectory_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tri_gen_msgs::srv::GenerateTrajectory_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tri_gen_msgs__srv__GenerateTrajectory_Response
    std::shared_ptr<tri_gen_msgs::srv::GenerateTrajectory_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tri_gen_msgs__srv__GenerateTrajectory_Response
    std::shared_ptr<tri_gen_msgs::srv::GenerateTrajectory_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GenerateTrajectory_Response_ & other) const
  {
    if (this->trajectory != other.trajectory) {
      return false;
    }
    if (this->total_length != other.total_length) {
      return false;
    }
    if (this->max_velocity != other.max_velocity) {
      return false;
    }
    if (this->max_curvature != other.max_curvature) {
      return false;
    }
    if (this->generation_time_ms != other.generation_time_ms) {
      return false;
    }
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const GenerateTrajectory_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GenerateTrajectory_Response_

// alias to use template instance with default allocator
using GenerateTrajectory_Response =
  tri_gen_msgs::srv::GenerateTrajectory_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace tri_gen_msgs

namespace tri_gen_msgs
{

namespace srv
{

struct GenerateTrajectory
{
  using Request = tri_gen_msgs::srv::GenerateTrajectory_Request;
  using Response = tri_gen_msgs::srv::GenerateTrajectory_Response;
};

}  // namespace srv

}  // namespace tri_gen_msgs

#endif  // TRI_GEN_MSGS__SRV__DETAIL__GENERATE_TRAJECTORY__STRUCT_HPP_
