// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interfaces:msg/Dect2.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__DECT2__STRUCT_HPP_
#define INTERFACES__MSG__DETAIL__DECT2__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__interfaces__msg__Dect2 __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__msg__Dect2 __declspec(deprecated)
#endif

namespace interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Dect2_
{
  using Type = Dect2_<ContainerAllocator>;

  explicit Dect2_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cam_x = 0.0;
      this->cam_y = 0.0;
      this->cam_z = 0.0;
    }
  }

  explicit Dect2_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cam_x = 0.0;
      this->cam_y = 0.0;
      this->cam_z = 0.0;
    }
  }

  // field types and members
  using _cam_x_type =
    double;
  _cam_x_type cam_x;
  using _cam_y_type =
    double;
  _cam_y_type cam_y;
  using _cam_z_type =
    double;
  _cam_z_type cam_z;

  // setters for named parameter idiom
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
  Type & set__cam_z(
    const double & _arg)
  {
    this->cam_z = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interfaces::msg::Dect2_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::msg::Dect2_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::msg::Dect2_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::msg::Dect2_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::Dect2_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::Dect2_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::Dect2_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::Dect2_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::msg::Dect2_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::msg::Dect2_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__msg__Dect2
    std::shared_ptr<interfaces::msg::Dect2_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__msg__Dect2
    std::shared_ptr<interfaces::msg::Dect2_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Dect2_ & other) const
  {
    if (this->cam_x != other.cam_x) {
      return false;
    }
    if (this->cam_y != other.cam_y) {
      return false;
    }
    if (this->cam_z != other.cam_z) {
      return false;
    }
    return true;
  }
  bool operator!=(const Dect2_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Dect2_

// alias to use template instance with default allocator
using Dect2 =
  interfaces::msg::Dect2_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__DECT2__STRUCT_HPP_
