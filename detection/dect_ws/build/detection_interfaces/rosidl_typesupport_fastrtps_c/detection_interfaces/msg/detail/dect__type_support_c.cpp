// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from detection_interfaces:msg/Dect.idl
// generated code does not contain a copyright notice
#include "detection_interfaces/msg/detail/dect__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "detection_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "detection_interfaces/msg/detail/dect__struct.h"
#include "detection_interfaces/msg/detail/dect__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // obj_class
#include "rosidl_runtime_c/string_functions.h"  // obj_class

// forward declare type support functions


using _Dect__ros_msg_type = detection_interfaces__msg__Dect;

static bool _Dect__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Dect__ros_msg_type * ros_message = static_cast<const _Dect__ros_msg_type *>(untyped_ros_message);
  // Field name: obj_class
  {
    const rosidl_runtime_c__String * str = &ros_message->obj_class;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: bounding_x
  {
    cdr << ros_message->bounding_x;
  }

  // Field name: bounding_y
  {
    cdr << ros_message->bounding_y;
  }

  // Field name: bounding_w
  {
    cdr << ros_message->bounding_w;
  }

  // Field name: bounding_h
  {
    cdr << ros_message->bounding_h;
  }

  // Field name: bounding_d
  {
    cdr << ros_message->bounding_d;
  }

  return true;
}

static bool _Dect__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Dect__ros_msg_type * ros_message = static_cast<_Dect__ros_msg_type *>(untyped_ros_message);
  // Field name: obj_class
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->obj_class.data) {
      rosidl_runtime_c__String__init(&ros_message->obj_class);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->obj_class,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'obj_class'\n");
      return false;
    }
  }

  // Field name: bounding_x
  {
    cdr >> ros_message->bounding_x;
  }

  // Field name: bounding_y
  {
    cdr >> ros_message->bounding_y;
  }

  // Field name: bounding_w
  {
    cdr >> ros_message->bounding_w;
  }

  // Field name: bounding_h
  {
    cdr >> ros_message->bounding_h;
  }

  // Field name: bounding_d
  {
    cdr >> ros_message->bounding_d;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_detection_interfaces
size_t get_serialized_size_detection_interfaces__msg__Dect(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Dect__ros_msg_type * ros_message = static_cast<const _Dect__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name obj_class
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->obj_class.size + 1);
  // field.name bounding_x
  {
    size_t item_size = sizeof(ros_message->bounding_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name bounding_y
  {
    size_t item_size = sizeof(ros_message->bounding_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name bounding_w
  {
    size_t item_size = sizeof(ros_message->bounding_w);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name bounding_h
  {
    size_t item_size = sizeof(ros_message->bounding_h);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name bounding_d
  {
    size_t item_size = sizeof(ros_message->bounding_d);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Dect__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_detection_interfaces__msg__Dect(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_detection_interfaces
size_t max_serialized_size_detection_interfaces__msg__Dect(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: obj_class
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: bounding_x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: bounding_y
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: bounding_w
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: bounding_h
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: bounding_d
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _Dect__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_detection_interfaces__msg__Dect(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_Dect = {
  "detection_interfaces::msg",
  "Dect",
  _Dect__cdr_serialize,
  _Dect__cdr_deserialize,
  _Dect__get_serialized_size,
  _Dect__max_serialized_size
};

static rosidl_message_type_support_t _Dect__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Dect,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, detection_interfaces, msg, Dect)() {
  return &_Dect__type_support;
}

#if defined(__cplusplus)
}
#endif
