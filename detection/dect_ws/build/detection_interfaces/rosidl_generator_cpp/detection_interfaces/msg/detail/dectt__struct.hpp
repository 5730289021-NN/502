// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from detection_interfaces:msg/Dectt.idl
// generated code does not contain a copyright notice

#ifndef DETECTION_INTERFACES__MSG__DETAIL__DECTT__STRUCT_HPP_
#define DETECTION_INTERFACES__MSG__DETAIL__DECTT__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__detection_interfaces__msg__Dectt __attribute__((deprecated))
#else
# define DEPRECATED__detection_interfaces__msg__Dectt __declspec(deprecated)
#endif

namespace detection_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Dectt_
{
  using Type = Dectt_<ContainerAllocator>;

  explicit Dectt_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->obj_class = 0;
      this->bound_coor = 0.0;
    }
  }

  explicit Dectt_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    detection_interfaces::msg::Dectt_<ContainerAllocator> *;
  using ConstRawPtr =
    const detection_interfaces::msg::Dectt_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<detection_interfaces::msg::Dectt_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<detection_interfaces::msg::Dectt_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      detection_interfaces::msg::Dectt_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<detection_interfaces::msg::Dectt_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      detection_interfaces::msg::Dectt_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<detection_interfaces::msg::Dectt_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<detection_interfaces::msg::Dectt_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<detection_interfaces::msg::Dectt_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__detection_interfaces__msg__Dectt
    std::shared_ptr<detection_interfaces::msg::Dectt_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__detection_interfaces__msg__Dectt
    std::shared_ptr<detection_interfaces::msg::Dectt_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Dectt_ & other) const
  {
    if (this->obj_class != other.obj_class) {
      return false;
    }
    if (this->bound_coor != other.bound_coor) {
      return false;
    }
    return true;
  }
  bool operator!=(const Dectt_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Dectt_

// alias to use template instance with default allocator
using Dectt =
  detection_interfaces::msg::Dectt_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace detection_interfaces

#endif  // DETECTION_INTERFACES__MSG__DETAIL__DECTT__STRUCT_HPP_
