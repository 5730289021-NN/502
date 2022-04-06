// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from detection_interfaces:msg/Dectt.idl
// generated code does not contain a copyright notice
#include "detection_interfaces/msg/detail/dectt__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
detection_interfaces__msg__Dectt__init(detection_interfaces__msg__Dectt * msg)
{
  if (!msg) {
    return false;
  }
  // obj_class
  // bound_coor
  return true;
}

void
detection_interfaces__msg__Dectt__fini(detection_interfaces__msg__Dectt * msg)
{
  if (!msg) {
    return;
  }
  // obj_class
  // bound_coor
}

detection_interfaces__msg__Dectt *
detection_interfaces__msg__Dectt__create()
{
  detection_interfaces__msg__Dectt * msg = (detection_interfaces__msg__Dectt *)malloc(sizeof(detection_interfaces__msg__Dectt));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(detection_interfaces__msg__Dectt));
  bool success = detection_interfaces__msg__Dectt__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
detection_interfaces__msg__Dectt__destroy(detection_interfaces__msg__Dectt * msg)
{
  if (msg) {
    detection_interfaces__msg__Dectt__fini(msg);
  }
  free(msg);
}


bool
detection_interfaces__msg__Dectt__Sequence__init(detection_interfaces__msg__Dectt__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  detection_interfaces__msg__Dectt * data = NULL;
  if (size) {
    data = (detection_interfaces__msg__Dectt *)calloc(size, sizeof(detection_interfaces__msg__Dectt));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = detection_interfaces__msg__Dectt__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        detection_interfaces__msg__Dectt__fini(&data[i - 1]);
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
detection_interfaces__msg__Dectt__Sequence__fini(detection_interfaces__msg__Dectt__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      detection_interfaces__msg__Dectt__fini(&array->data[i]);
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

detection_interfaces__msg__Dectt__Sequence *
detection_interfaces__msg__Dectt__Sequence__create(size_t size)
{
  detection_interfaces__msg__Dectt__Sequence * array = (detection_interfaces__msg__Dectt__Sequence *)malloc(sizeof(detection_interfaces__msg__Dectt__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = detection_interfaces__msg__Dectt__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
detection_interfaces__msg__Dectt__Sequence__destroy(detection_interfaces__msg__Dectt__Sequence * array)
{
  if (array) {
    detection_interfaces__msg__Dectt__Sequence__fini(array);
  }
  free(array);
}
