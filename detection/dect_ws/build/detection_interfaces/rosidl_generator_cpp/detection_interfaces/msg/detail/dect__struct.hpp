// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from detection_interfaces:msg/Dect.idl
// generated code does not contain a copyright notice

#ifndef DETECTION_INTERFACES__MSG__DETAIL__DECT__STRUCT_HPP_
#define DETECTION_INTERFACES__MSG__DETAIL__DECT__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__detection_interfaces__msg__Dect __attribute__((deprecated))
#else
# define DEPRECATED__detection_interfaces__msg__Dect __declspec(deprecated)
#endif

namespace detection_interfaces
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
      this->bounding_x = 0.0;
      this->bounding_y = 0.0;
      this->bounding_w = 0.0;
      this->bounding_h = 0.0;
      this->bounding_d = 0.0;
    }
  }

  explicit Dect_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : obj_class(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->obj_class = "";
      this->bounding_x = 0.0;
      this->bounding_y = 0.0;
      this->bounding_w = 0.0;
      this->bounding_h = 0.0;
      this->bounding_d = 0.0;
    }
  }

  // field types and members
  using _obj_class_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _obj_class_type obj_class;
  using _bounding_x_type =
    double;
  _bounding_x_type bounding_x;
  using _bounding_y_type =
    double;
  _bounding_y_type bounding_y;
  using _bounding_w_type =
    double;
  _bounding_w_type bounding_w;
  using _bounding_h_type =
    double;
  _bounding_h_type bounding_h;
  using _bounding_d_type =
    double;
  _bounding_d_type bounding_d;

  // setters for named parameter idiom
  Type & set__obj_class(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->obj_class = _arg;
    return *this;
  }
  Type & set__bounding_x(
    const double & _arg)
  {
    this->bounding_x = _arg;
    return *this;
  }
  Type & set__bounding_y(
    const double & _arg)
  {
    this->bounding_y = _arg;
    return *this;
  }
  Type & set__bounding_w(
    const double & _arg)
  {
    this->bounding_w = _arg;
    return *this;
  }
  Type & set__bounding_h(
    const double & _arg)
  {
    this->bounding_h = _arg;
    return *this;
  }
  Type & set__bounding_d(
    const double & _arg)
  {
    this->bounding_d = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    detection_interfaces::msg::Dect_<ContainerAllocator> *;
  using ConstRawPtr =
    const detection_interfaces::msg::Dect_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<detection_interfaces::msg::Dect_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<detection_interfaces::msg::Dect_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      detection_interfaces::msg::Dect_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<detection_interfaces::msg::Dect_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      detection_interfaces::msg::Dect_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<detection_interfaces::msg::Dect_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<detection_interfaces::msg::Dect_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<detection_interfaces::msg::Dect_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__detection_interfaces__msg__Dect
    std::shared_ptr<detection_interfaces::msg::Dect_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__detection_interfaces__msg__Dect
    std::shared_ptr<detection_interfaces::msg::Dect_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Dect_ & other) const
  {
    if (this->obj_class != other.obj_class) {
      return false;
    }
    if (this->bounding_x != other.bounding_x) {
      return false;
    }
    if (this->bounding_y != other.bounding_y) {
      return false;
    }
    if (this->bounding_w != other.bounding_w) {
      return false;
    }
    if (this->bounding_h != other.bounding_h) {
      return false;
    }
    if (this->bounding_d != other.bounding_d) {
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
  detection_interfaces::msg::Dect_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace detection_interfaces

#endif  // DETECTION_INTERFACES__MSG__DETAIL__DECT__STRUCT_HPP_
