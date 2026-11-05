# generated from rosidl_generator_py/resource/_idl.py.em
# with input from tri_gen_msgs:srv/GenerateTrajectory.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GenerateTrajectory_Request(type):
    """Metaclass of message 'GenerateTrajectory_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('tri_gen_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'tri_gen_msgs.srv.GenerateTrajectory_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__generate_trajectory__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__generate_trajectory__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__generate_trajectory__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__generate_trajectory__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__generate_trajectory__request

            from tri_gen_msgs.msg import State
            if State.__class__._TYPE_SUPPORT is None:
                State.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GenerateTrajectory_Request(metaclass=Metaclass_GenerateTrajectory_Request):
    """Message class 'GenerateTrajectory_Request'."""

    __slots__ = [
        '_start',
        '_goal',
        '_dt',
        '_phi_min',
        '_phi_max',
        '_omega_phi_min',
        '_omega_phi_max',
        '_v_min',
        '_v_max',
        '_a_min',
        '_a_max',
    ]

    _fields_and_field_types = {
        'start': 'tri_gen_msgs/State',
        'goal': 'tri_gen_msgs/State',
        'dt': 'double',
        'phi_min': 'double',
        'phi_max': 'double',
        'omega_phi_min': 'double',
        'omega_phi_max': 'double',
        'v_min': 'double',
        'v_max': 'double',
        'a_min': 'double',
        'a_max': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['tri_gen_msgs', 'msg'], 'State'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['tri_gen_msgs', 'msg'], 'State'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from tri_gen_msgs.msg import State
        self.start = kwargs.get('start', State())
        from tri_gen_msgs.msg import State
        self.goal = kwargs.get('goal', State())
        self.dt = kwargs.get('dt', float())
        self.phi_min = kwargs.get('phi_min', float())
        self.phi_max = kwargs.get('phi_max', float())
        self.omega_phi_min = kwargs.get('omega_phi_min', float())
        self.omega_phi_max = kwargs.get('omega_phi_max', float())
        self.v_min = kwargs.get('v_min', float())
        self.v_max = kwargs.get('v_max', float())
        self.a_min = kwargs.get('a_min', float())
        self.a_max = kwargs.get('a_max', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.start != other.start:
            return False
        if self.goal != other.goal:
            return False
        if self.dt != other.dt:
            return False
        if self.phi_min != other.phi_min:
            return False
        if self.phi_max != other.phi_max:
            return False
        if self.omega_phi_min != other.omega_phi_min:
            return False
        if self.omega_phi_max != other.omega_phi_max:
            return False
        if self.v_min != other.v_min:
            return False
        if self.v_max != other.v_max:
            return False
        if self.a_min != other.a_min:
            return False
        if self.a_max != other.a_max:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def start(self):
        """Message field 'start'."""
        return self._start

    @start.setter
    def start(self, value):
        if __debug__:
            from tri_gen_msgs.msg import State
            assert \
                isinstance(value, State), \
                "The 'start' field must be a sub message of type 'State'"
        self._start = value

    @builtins.property
    def goal(self):
        """Message field 'goal'."""
        return self._goal

    @goal.setter
    def goal(self, value):
        if __debug__:
            from tri_gen_msgs.msg import State
            assert \
                isinstance(value, State), \
                "The 'goal' field must be a sub message of type 'State'"
        self._goal = value

    @builtins.property
    def dt(self):
        """Message field 'dt'."""
        return self._dt

    @dt.setter
    def dt(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'dt' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'dt' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._dt = value

    @builtins.property
    def phi_min(self):
        """Message field 'phi_min'."""
        return self._phi_min

    @phi_min.setter
    def phi_min(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'phi_min' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'phi_min' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._phi_min = value

    @builtins.property
    def phi_max(self):
        """Message field 'phi_max'."""
        return self._phi_max

    @phi_max.setter
    def phi_max(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'phi_max' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'phi_max' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._phi_max = value

    @builtins.property
    def omega_phi_min(self):
        """Message field 'omega_phi_min'."""
        return self._omega_phi_min

    @omega_phi_min.setter
    def omega_phi_min(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'omega_phi_min' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'omega_phi_min' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._omega_phi_min = value

    @builtins.property
    def omega_phi_max(self):
        """Message field 'omega_phi_max'."""
        return self._omega_phi_max

    @omega_phi_max.setter
    def omega_phi_max(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'omega_phi_max' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'omega_phi_max' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._omega_phi_max = value

    @builtins.property
    def v_min(self):
        """Message field 'v_min'."""
        return self._v_min

    @v_min.setter
    def v_min(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'v_min' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'v_min' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._v_min = value

    @builtins.property
    def v_max(self):
        """Message field 'v_max'."""
        return self._v_max

    @v_max.setter
    def v_max(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'v_max' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'v_max' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._v_max = value

    @builtins.property
    def a_min(self):
        """Message field 'a_min'."""
        return self._a_min

    @a_min.setter
    def a_min(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'a_min' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'a_min' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._a_min = value

    @builtins.property
    def a_max(self):
        """Message field 'a_max'."""
        return self._a_max

    @a_max.setter
    def a_max(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'a_max' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'a_max' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._a_max = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import math

# already imported above
# import rosidl_parser.definition


class Metaclass_GenerateTrajectory_Response(type):
    """Metaclass of message 'GenerateTrajectory_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('tri_gen_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'tri_gen_msgs.srv.GenerateTrajectory_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__generate_trajectory__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__generate_trajectory__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__generate_trajectory__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__generate_trajectory__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__generate_trajectory__response

            from tri_gen_msgs.msg import Trajectory
            if Trajectory.__class__._TYPE_SUPPORT is None:
                Trajectory.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GenerateTrajectory_Response(metaclass=Metaclass_GenerateTrajectory_Response):
    """Message class 'GenerateTrajectory_Response'."""

    __slots__ = [
        '_trajectory',
        '_total_length',
        '_max_velocity',
        '_max_curvature',
        '_generation_time_ms',
        '_success',
        '_message',
    ]

    _fields_and_field_types = {
        'trajectory': 'tri_gen_msgs/Trajectory',
        'total_length': 'double',
        'max_velocity': 'double',
        'max_curvature': 'double',
        'generation_time_ms': 'double',
        'success': 'boolean',
        'message': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['tri_gen_msgs', 'msg'], 'Trajectory'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from tri_gen_msgs.msg import Trajectory
        self.trajectory = kwargs.get('trajectory', Trajectory())
        self.total_length = kwargs.get('total_length', float())
        self.max_velocity = kwargs.get('max_velocity', float())
        self.max_curvature = kwargs.get('max_curvature', float())
        self.generation_time_ms = kwargs.get('generation_time_ms', float())
        self.success = kwargs.get('success', bool())
        self.message = kwargs.get('message', str())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.trajectory != other.trajectory:
            return False
        if self.total_length != other.total_length:
            return False
        if self.max_velocity != other.max_velocity:
            return False
        if self.max_curvature != other.max_curvature:
            return False
        if self.generation_time_ms != other.generation_time_ms:
            return False
        if self.success != other.success:
            return False
        if self.message != other.message:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def trajectory(self):
        """Message field 'trajectory'."""
        return self._trajectory

    @trajectory.setter
    def trajectory(self, value):
        if __debug__:
            from tri_gen_msgs.msg import Trajectory
            assert \
                isinstance(value, Trajectory), \
                "The 'trajectory' field must be a sub message of type 'Trajectory'"
        self._trajectory = value

    @builtins.property
    def total_length(self):
        """Message field 'total_length'."""
        return self._total_length

    @total_length.setter
    def total_length(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'total_length' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'total_length' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._total_length = value

    @builtins.property
    def max_velocity(self):
        """Message field 'max_velocity'."""
        return self._max_velocity

    @max_velocity.setter
    def max_velocity(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'max_velocity' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'max_velocity' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._max_velocity = value

    @builtins.property
    def max_curvature(self):
        """Message field 'max_curvature'."""
        return self._max_curvature

    @max_curvature.setter
    def max_curvature(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'max_curvature' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'max_curvature' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._max_curvature = value

    @builtins.property
    def generation_time_ms(self):
        """Message field 'generation_time_ms'."""
        return self._generation_time_ms

    @generation_time_ms.setter
    def generation_time_ms(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'generation_time_ms' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'generation_time_ms' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._generation_time_ms = value

    @builtins.property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value

    @builtins.property
    def message(self):
        """Message field 'message'."""
        return self._message

    @message.setter
    def message(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'message' field must be of type 'str'"
        self._message = value


class Metaclass_GenerateTrajectory(type):
    """Metaclass of service 'GenerateTrajectory'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('tri_gen_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'tri_gen_msgs.srv.GenerateTrajectory')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__generate_trajectory

            from tri_gen_msgs.srv import _generate_trajectory
            if _generate_trajectory.Metaclass_GenerateTrajectory_Request._TYPE_SUPPORT is None:
                _generate_trajectory.Metaclass_GenerateTrajectory_Request.__import_type_support__()
            if _generate_trajectory.Metaclass_GenerateTrajectory_Response._TYPE_SUPPORT is None:
                _generate_trajectory.Metaclass_GenerateTrajectory_Response.__import_type_support__()


class GenerateTrajectory(metaclass=Metaclass_GenerateTrajectory):
    from tri_gen_msgs.srv._generate_trajectory import GenerateTrajectory_Request as Request
    from tri_gen_msgs.srv._generate_trajectory import GenerateTrajectory_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
