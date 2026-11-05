// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from tri_gen_msgs:srv/GenerateTrajectory.idl
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
#include "tri_gen_msgs/srv/detail/generate_trajectory__struct.h"
#include "tri_gen_msgs/srv/detail/generate_trajectory__functions.h"

bool tri_gen_msgs__msg__state__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * tri_gen_msgs__msg__state__convert_to_py(void * raw_ros_message);
bool tri_gen_msgs__msg__state__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * tri_gen_msgs__msg__state__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool tri_gen_msgs__srv__generate_trajectory__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[65];
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
    assert(strncmp("tri_gen_msgs.srv._generate_trajectory.GenerateTrajectory_Request", full_classname_dest, 64) == 0);
  }
  tri_gen_msgs__srv__GenerateTrajectory_Request * ros_message = _ros_message;
  {  // start
    PyObject * field = PyObject_GetAttrString(_pymsg, "start");
    if (!field) {
      return false;
    }
    if (!tri_gen_msgs__msg__state__convert_from_py(field, &ros_message->start)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // goal
    PyObject * field = PyObject_GetAttrString(_pymsg, "goal");
    if (!field) {
      return false;
    }
    if (!tri_gen_msgs__msg__state__convert_from_py(field, &ros_message->goal)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // dt
    PyObject * field = PyObject_GetAttrString(_pymsg, "dt");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->dt = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // phi_min
    PyObject * field = PyObject_GetAttrString(_pymsg, "phi_min");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->phi_min = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // phi_max
    PyObject * field = PyObject_GetAttrString(_pymsg, "phi_max");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->phi_max = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // omega_phi_min
    PyObject * field = PyObject_GetAttrString(_pymsg, "omega_phi_min");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->omega_phi_min = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // omega_phi_max
    PyObject * field = PyObject_GetAttrString(_pymsg, "omega_phi_max");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->omega_phi_max = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // v_min
    PyObject * field = PyObject_GetAttrString(_pymsg, "v_min");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->v_min = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // v_max
    PyObject * field = PyObject_GetAttrString(_pymsg, "v_max");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->v_max = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // a_min
    PyObject * field = PyObject_GetAttrString(_pymsg, "a_min");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->a_min = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // a_max
    PyObject * field = PyObject_GetAttrString(_pymsg, "a_max");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->a_max = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * tri_gen_msgs__srv__generate_trajectory__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of GenerateTrajectory_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("tri_gen_msgs.srv._generate_trajectory");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "GenerateTrajectory_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  tri_gen_msgs__srv__GenerateTrajectory_Request * ros_message = (tri_gen_msgs__srv__GenerateTrajectory_Request *)raw_ros_message;
  {  // start
    PyObject * field = NULL;
    field = tri_gen_msgs__msg__state__convert_to_py(&ros_message->start);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "start", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // goal
    PyObject * field = NULL;
    field = tri_gen_msgs__msg__state__convert_to_py(&ros_message->goal);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "goal", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // dt
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->dt);
    {
      int rc = PyObject_SetAttrString(_pymessage, "dt", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // phi_min
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->phi_min);
    {
      int rc = PyObject_SetAttrString(_pymessage, "phi_min", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // phi_max
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->phi_max);
    {
      int rc = PyObject_SetAttrString(_pymessage, "phi_max", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // omega_phi_min
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->omega_phi_min);
    {
      int rc = PyObject_SetAttrString(_pymessage, "omega_phi_min", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // omega_phi_max
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->omega_phi_max);
    {
      int rc = PyObject_SetAttrString(_pymessage, "omega_phi_max", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // v_min
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->v_min);
    {
      int rc = PyObject_SetAttrString(_pymessage, "v_min", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // v_max
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->v_max);
    {
      int rc = PyObject_SetAttrString(_pymessage, "v_max", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // a_min
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->a_min);
    {
      int rc = PyObject_SetAttrString(_pymessage, "a_min", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // a_max
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->a_max);
    {
      int rc = PyObject_SetAttrString(_pymessage, "a_max", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
// already included above
// #include <Python.h>
// already included above
// #include <stdbool.h>
// already included above
// #include "numpy/ndarrayobject.h"
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "tri_gen_msgs/srv/detail/generate_trajectory__struct.h"
// already included above
// #include "tri_gen_msgs/srv/detail/generate_trajectory__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

bool tri_gen_msgs__msg__trajectory__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * tri_gen_msgs__msg__trajectory__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool tri_gen_msgs__srv__generate_trajectory__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[66];
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
    assert(strncmp("tri_gen_msgs.srv._generate_trajectory.GenerateTrajectory_Response", full_classname_dest, 65) == 0);
  }
  tri_gen_msgs__srv__GenerateTrajectory_Response * ros_message = _ros_message;
  {  // trajectory
    PyObject * field = PyObject_GetAttrString(_pymsg, "trajectory");
    if (!field) {
      return false;
    }
    if (!tri_gen_msgs__msg__trajectory__convert_from_py(field, &ros_message->trajectory)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // total_length
    PyObject * field = PyObject_GetAttrString(_pymsg, "total_length");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->total_length = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // max_velocity
    PyObject * field = PyObject_GetAttrString(_pymsg, "max_velocity");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->max_velocity = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // max_curvature
    PyObject * field = PyObject_GetAttrString(_pymsg, "max_curvature");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->max_curvature = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // generation_time_ms
    PyObject * field = PyObject_GetAttrString(_pymsg, "generation_time_ms");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->generation_time_ms = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // success
    PyObject * field = PyObject_GetAttrString(_pymsg, "success");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->success = (Py_True == field);
    Py_DECREF(field);
  }
  {  // message
    PyObject * field = PyObject_GetAttrString(_pymsg, "message");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->message, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * tri_gen_msgs__srv__generate_trajectory__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of GenerateTrajectory_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("tri_gen_msgs.srv._generate_trajectory");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "GenerateTrajectory_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  tri_gen_msgs__srv__GenerateTrajectory_Response * ros_message = (tri_gen_msgs__srv__GenerateTrajectory_Response *)raw_ros_message;
  {  // trajectory
    PyObject * field = NULL;
    field = tri_gen_msgs__msg__trajectory__convert_to_py(&ros_message->trajectory);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "trajectory", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // total_length
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->total_length);
    {
      int rc = PyObject_SetAttrString(_pymessage, "total_length", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // max_velocity
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->max_velocity);
    {
      int rc = PyObject_SetAttrString(_pymessage, "max_velocity", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // max_curvature
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->max_curvature);
    {
      int rc = PyObject_SetAttrString(_pymessage, "max_curvature", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // generation_time_ms
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->generation_time_ms);
    {
      int rc = PyObject_SetAttrString(_pymessage, "generation_time_ms", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // success
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->success ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "success", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // message
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->message.data,
      strlen(ros_message->message.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "message", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
