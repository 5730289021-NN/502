// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interfaces:msg/Dect.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__DECT__STRUCT_HPP_
#define INTERFACES__MSG__DETAIL__DECT__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__interfaces__msg__Dect __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__msg__Dect __declspec(deprecated)
#endif

namespace interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Dect_
{
  using Type = Dect_<ContainerAllocator>;

  explicit Dect_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->obj_class = "";
      this->cam_x = 0.0;
      this->cam_y = 0.0;
      this->robot_x = 0.0;
      this->robot_y = 0.0;
      this->robot_yaw = 0.0;
    }
  }

  explicit Dect_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : obj_class(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->obj_class = "";
      this->cam_x = 0.0;
      this->cam_y = 0.0;
      this->robot_x = 0.0;
      this->robot_y = 0.0;
      this->robot_yaw = 0.0;
    }
  }

  // field types and members
  using _obj_class_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _obj_class_type obj_class;
  using _cam_x_type =
    double;
  _cam_x_type cam_x;
  using _cam_y_type =
    double;
  _cam_y_type cam_y;
  using _robot_x_type =
    double;
  _robot_x_type robot_x;
  using _robot_y_type =
    double;
  _robot_y_type robot_y;
  using _robot_yaw_type =
    double;
  _robot_yaw_type robot_yaw;

  // setters for named parameter idiom
  Type & set__obj_class(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->obj_class = _arg;
    return *this;
  }
  Type & set__cam_x(
    const double & _arg)
  {
    this->cam_x = _arg;
    return *this;
  }
  Type & set__cam_y(
    const double & _arg)
  {
    this->cam_y = _arg;
    return *this;
  }
  Type & set__robot_x(
    const double & _arg)
  {
    this->robot_x = _arg;
    return *this;
  }
  Type & set__robot_y(
    const double & _arg)
  {
    this->robot_y = _arg;
    return *this;
  }
  Type & set__robot_yaw(
    const double & _arg)
  {
    this->robot_yaw = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interfaces::msg::Dect_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::msg::Dect_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::msg::Dect_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::msg::Dect_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::Dect_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::Dect_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::Dect_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::Dect_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::msg::Dect_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::msg::Dect_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__msg__Dect
    std::shared_ptr<interfaces::msg::Dect_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__msg__Dect
    std::shared_ptr<interfaces::msg::Dect_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Dect_ & other) const
  {
    if (this->obj_class != other.obj_class) {
      return false;
    }
    if (this->cam_x != other.cam_x) {
      return false;
    }
    if (this->cam_y != other.cam_y) {
      return false;
    }
    if (this->robot_x != other.robot_x) {
      return false;
    }
    if (this->robot_y != other.robot_y) {
      return false;
    }
    if (this->robot_yaw != other.robot_yaw) {
      return false;
    }
    return true;
  }
  bool operator!=(const Dect_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Dect_

// alias to use template instance with default allocator
using Dect =
  interfaces::msg::Dect_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__DECT__STRUCT_HPP_
