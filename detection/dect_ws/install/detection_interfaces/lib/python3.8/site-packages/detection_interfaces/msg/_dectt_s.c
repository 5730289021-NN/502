// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from detection_interfaces:msg/Dectt.idl
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
#include "detection_interfaces/msg/detail/dectt__struct.h"
#include "detection_interfaces/msg/detail/dectt__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool detection_interfaces__msg__dectt__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[38];
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
    assert(strncmp("detection_interfaces.msg._dectt.Dectt", full_classname_dest, 37) == 0);
  }
  detection_interfaces__msg__Dectt * ros_message = _ros_message;
  {  // obj_class
    PyObject * field = PyObject_GetAttrString(_pymsg, "obj_class");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->obj_class = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // bound_coor
    PyObject * field = PyObject_GetAttrString(_pymsg, "bound_coor");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->bound_coor = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * detection_interfaces__msg__dectt__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Dectt */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("detection_interfaces.msg._dectt");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Dectt");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  detection_interfaces__msg__Dectt * ros_message = (detection_interfaces__msg__Dectt *)raw_ros_message;
  {  // obj_class
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->obj_class);
    {
      int rc = PyObject_SetAttrString(_pymessage, "obj_class", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // bound_coor
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->bound_coor);
    {
      int rc = PyObject_SetAttrString(_pymessage, "bound_coor", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
