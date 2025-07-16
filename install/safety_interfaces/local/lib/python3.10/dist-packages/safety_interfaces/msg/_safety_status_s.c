// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from safety_interfaces:msg/SafetyStatus.idl
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
#include "safety_interfaces/msg/detail/safety_status__struct.h"
#include "safety_interfaces/msg/detail/safety_status__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool safety_interfaces__msg__safety_status__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[50];
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
    assert(strncmp("safety_interfaces.msg._safety_status.SafetyStatus", full_classname_dest, 49) == 0);
  }
  safety_interfaces__msg__SafetyStatus * ros_message = _ros_message;
  {  // front_clear
    PyObject * field = PyObject_GetAttrString(_pymsg, "front_clear");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->front_clear = (Py_True == field);
    Py_DECREF(field);
  }
  {  // back_clear
    PyObject * field = PyObject_GetAttrString(_pymsg, "back_clear");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->back_clear = (Py_True == field);
    Py_DECREF(field);
  }
  {  // left_clear
    PyObject * field = PyObject_GetAttrString(_pymsg, "left_clear");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->left_clear = (Py_True == field);
    Py_DECREF(field);
  }
  {  // right_clear
    PyObject * field = PyObject_GetAttrString(_pymsg, "right_clear");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->right_clear = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * safety_interfaces__msg__safety_status__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of SafetyStatus */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("safety_interfaces.msg._safety_status");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "SafetyStatus");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  safety_interfaces__msg__SafetyStatus * ros_message = (safety_interfaces__msg__SafetyStatus *)raw_ros_message;
  {  // front_clear
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->front_clear ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "front_clear", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // back_clear
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->back_clear ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "back_clear", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // left_clear
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->left_clear ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "left_clear", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // right_clear
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->right_clear ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "right_clear", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
