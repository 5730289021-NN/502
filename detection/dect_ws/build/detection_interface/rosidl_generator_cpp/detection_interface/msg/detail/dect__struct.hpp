// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from detection_interface:msg/Dect.idl
// generated code does not contain a copyright notice

#ifndef DETECTION_INTERFACE__MSG__DETAIL__DECT__STRUCT_HPP_
#define DETECTION_INTERFACE__MSG__DETAIL__DECT__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__detection_interface__msg__Dect __attribute__((deprecated))
#else
# define DEPRECATED__detection_interface__msg__Dect __declspec(deprecated)
#endif

namespace detection_interface
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
      this->obj_class = 0;
      this->bound_coor = 0.0;
    }
  }

  explicit Dect_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->obj_class = 0;
      this->bound_coor = 0.0;
    }
  }

  // field types and members
  using _obj_class_type =
    uint8_t;
  _obj_class_type obj_class;
  using _bound_coor_type =
    double;
  _bound_coor_type bound_coor;

  // setters for named parameter idiom
  Type & set__obj_class(
    const uint8_t & _arg)
  {
    this->obj_class = _arg;
    return *this;
  }
  Type & set__bound_coor(
    const double & _arg)
  {
    this->bound_coor = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    detection_interface::msg::Dect_<ContainerAllocator> *;
  using ConstRawPtr =
    const detection_interface::msg::Dect_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<detection_interface::msg::Dect_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<detection_interface::msg::Dect_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      detection_interface::msg::Dect_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<detection_interface::msg::Dect_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      detection_interface::msg::Dect_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<detection_interface::msg::Dect_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<detection_interface::msg::Dect_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<detection_interface::msg::Dect_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__detection_interface__msg__Dect
    std::shared_ptr<detection_interface::msg::Dect_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__detection_interface__msg__Dect
    std::shared_ptr<detection_interface::msg::Dect_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Dect_ & other) const
  {
    if (this->obj_class != other.obj_class) {
      return false;
    }
    if (this->bound_coor != other.bound_coor) {
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
  detection_interface::msg::Dect_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace detection_interface

#endif  // DETECTION_INTERFACE__MSG__DETAIL__DECT__STRUCT_HPP_
