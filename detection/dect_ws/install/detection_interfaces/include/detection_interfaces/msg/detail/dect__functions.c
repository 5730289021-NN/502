// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from detection_interfaces:msg/Dect.idl
// generated code does not contain a copyright notice
#include "detection_interfaces/msg/detail/dect__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `obj_class`
#include "rosidl_runtime_c/string_functions.h"

bool
detection_interfaces__msg__Dect__init(detection_interfaces__msg__Dect * msg)
{
  if (!msg) {
    return false;
  }
  // obj_class
  if (!rosidl_runtime_c__String__init(&msg->obj_class)) {
    detection_interfaces__msg__Dect__fini(msg);
    return false;
  }
  // bounding_x
  // bounding_y
  // bounding_w
  // bounding_h
  // bounding_d
  return true;
}

void
detection_interfaces__msg__Dect__fini(detection_interfaces__msg__Dect * msg)
{
  if (!msg) {
    return;
  }
  // obj_class
  rosidl_runtime_c__String__fini(&msg->obj_class);
  // bounding_x
  // bounding_y
  // bounding_w
  // bounding_h
  // bounding_d
}

detection_interfaces__msg__Dect *
detection_interfaces__msg__Dect__create()
{
  detection_interfaces__msg__Dect * msg = (detection_interfaces__msg__Dect *)malloc(sizeof(detection_interfaces__msg__Dect));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(detection_interfaces__msg__Dect));
  bool success = detection_interfaces__msg__Dect__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
detection_interfaces__msg__Dect__destroy(detection_interfaces__msg__Dect * msg)
{
  if (msg) {
    detection_interfaces__msg__Dect__fini(msg);
  }
  free(msg);
}


bool
detection_interfaces__msg__Dect__Sequence__init(detection_interfaces__msg__Dect__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  detection_interfaces__msg__Dect * data = NULL;
  if (size) {
    data = (detection_interfaces__msg__Dect *)calloc(size, sizeof(detection_interfaces__msg__Dect));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = detection_interfaces__msg__Dect__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        detection_interfaces__msg__Dect__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
detection_interfaces__msg__Dect__Sequence__fini(detection_interfaces__msg__Dect__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      detection_interfaces__msg__Dect__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

detection_interfaces__msg__Dect__Sequence *
detection_interfaces__msg__Dect__Sequence__create(size_t size)
{
  detection_interfaces__msg__Dect__Sequence * array = (detection_interfaces__msg__Dect__Sequence *)malloc(sizeof(detection_interfaces__msg__Dect__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = detection_interfaces__msg__Dect__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
detection_interfaces__msg__Dect__Sequence__destroy(detection_interfaces__msg__Dect__Sequence * array)
{
  if (array) {
    detection_interfaces__msg__Dect__Sequence__fini(array);
  }
  free(array);
}
