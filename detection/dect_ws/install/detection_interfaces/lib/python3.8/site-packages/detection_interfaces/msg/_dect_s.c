// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from detection_interfaces:msg/Dect.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "detection_interfaces/msg/detail/dect__struct.h"
#include "detection_interfaces/msg/detail/dect__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool detection_interfaces__msg__dect__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[36];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("detection_interfaces.msg._dect.Dect", full_classname_dest, 35) == 0);
  }
  detection_interfaces__msg__Dect * ros_message = _ros_message;
  {  // obj_class
    PyObject * field = PyObject_GetAttrString(_pymsg, "obj_class");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->obj_class, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // bounding_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "bounding_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->bounding_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // bounding_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "bounding_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->bounding_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // bounding_w
    PyObject * field = PyObject_GetAttrString(_pymsg, "bounding_w");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->bounding_w = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // bounding_h
    PyObject * field = PyObject_GetAttrString(_pymsg, "bounding_h");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->bounding_h = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // bounding_d
    PyObject * field = PyObject_GetAttrString(_pymsg, "bounding_d");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->bounding_d = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * detection_interfaces__msg__dect__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Dect */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("detection_interfaces.msg._dect");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Dect");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  detection_interfaces__msg__Dect * ros_message = (detection_interfaces__msg__Dect *)raw_ros_message;
  {  // obj_class
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->obj_class.data,
      strlen(ros_message->obj_class.data),
      "strict");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "obj_class", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // bounding_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->bounding_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "bounding_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // bounding_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->bounding_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "bounding_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // bounding_w
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->bounding_w);
    {
      int rc = PyObject_SetAttrString(_pymessage, "bounding_w", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // bounding_h
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->bounding_h);
    {
      int rc = PyObject_SetAttrString(_pymessage, "bounding_h", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // bounding_d
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->bounding_d);
    {
      int rc = PyObject_SetAttrString(_pymessage, "bounding_d", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
