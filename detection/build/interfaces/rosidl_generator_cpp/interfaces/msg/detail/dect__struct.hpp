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


// Include directives for member types
// Member 'obj_class'
#include "std_msgs/msg/detail/string__struct.hpp"
// Member 'obj_point'
// Member 'goal_point'
// Member 'rotation'
#include "std_msgs/msg/detail/float32_multi_array__struct.hpp"

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
  : obj_class(_init),
    obj_point(_init),
    goal_point(_init),
    rotation(_init)
  {
    (void)_init;
  }

  explicit Dect_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : obj_class(_alloc, _init),
    obj_point(_alloc, _init),
    goal_point(_alloc, _init),
    rotation(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _obj_class_type =
    std_msgs::msg::String_<ContainerAllocator>;
  _obj_class_type obj_class;
  using _obj_point_type =
    std_msgs::msg::Float32MultiArray_<ContainerAllocator>;
  _obj_point_type obj_point;
  using _goal_point_type =
    std_msgs::msg::Float32MultiArray_<ContainerAllocator>;
  _goal_point_type goal_point;
  using _rotation_type =
    std_msgs::msg::Float32MultiArray_<ContainerAllocator>;
  _rotation_type rotation;

  // setters for named parameter idiom
  Type & set__obj_class(
    const std_msgs::msg::String_<ContainerAllocator> & _arg)
  {
    this->obj_class = _arg;
    return *this;
  }
  Type & set__obj_point(
    const std_msgs::msg::Float32MultiArray_<ContainerAllocator> & _arg)
  {
    this->obj_point = _arg;
    return *this;
  }
  Type & set__goal_point(
    const std_msgs::msg::Float32MultiArray_<ContainerAllocator> & _arg)
  {
    this->goal_point = _arg;
    return *this;
  }
  Type & set__rotation(
    const std_msgs::msg::Float32MultiArray_<ContainerAllocator> & _arg)
  {
    this->rotation = _arg;
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
    if (this->obj_point != other.obj_point) {
      return false;
    }
    if (this->goal_point != other.goal_point) {
      return false;
    }
    if (this->rotation != other.rotation) {
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
