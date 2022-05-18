# generated from rosidl_generator_py/resource/_idl.py.em
# with input from interfaces:msg/Dect.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Dect(type):
    """Metaclass of message 'Dect'."""

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
            module = import_type_support('interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'interfaces.msg.Dect')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__dect
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__dect
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__dect
            cls._TYPE_SUPPORT = module.type_support_msg__msg__dect
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__dect

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Dect(metaclass=Metaclass_Dect):
    """Message class 'Dect'."""

    __slots__ = [
        '_obj_class',
        '_cam_x',
        '_cam_y',
        '_robot_x',
        '_robot_y',
        '_robot_yaw',
    ]

    _fields_and_field_types = {
        'obj_class': 'string',
        'cam_x': 'double',
        'cam_y': 'double',
        'robot_x': 'double',
        'robot_y': 'double',
        'robot_yaw': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
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
        self.obj_class = kwargs.get('obj_class', str())
        self.cam_x = kwargs.get('cam_x', float())
        self.cam_y = kwargs.get('cam_y', float())
        self.robot_x = kwargs.get('robot_x', float())
        self.robot_y = kwargs.get('robot_y', float())
        self.robot_yaw = kwargs.get('robot_yaw', float())

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
        if self.obj_class != other.obj_class:
            return False
        if self.cam_x != other.cam_x:
            return False
        if self.cam_y != other.cam_y:
            return False
        if self.robot_x != other.robot_x:
            return False
        if self.robot_y != other.robot_y:
            return False
        if self.robot_yaw != other.robot_yaw:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def obj_class(self):
        """Message field 'obj_class'."""
        return self._obj_class

    @obj_class.setter
    def obj_class(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'obj_class' field must be of type 'str'"
        self._obj_class = value

    @property
    def cam_x(self):
        """Message field 'cam_x'."""
        return self._cam_x

    @cam_x.setter
    def cam_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'cam_x' field must be of type 'float'"
        self._cam_x = value

    @property
    def cam_y(self):
        """Message field 'cam_y'."""
        return self._cam_y

    @cam_y.setter
    def cam_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'cam_y' field must be of type 'float'"
        self._cam_y = value

    @property
    def robot_x(self):
        """Message field 'robot_x'."""
        return self._robot_x

    @robot_x.setter
    def robot_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'robot_x' field must be of type 'float'"
        self._robot_x = value

    @property
    def robot_y(self):
        """Message field 'robot_y'."""
        return self._robot_y

    @robot_y.setter
    def robot_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'robot_y' field must be of type 'float'"
        self._robot_y = value

    @property
    def robot_yaw(self):
        """Message field 'robot_yaw'."""
        return self._robot_yaw

    @robot_yaw.setter
    def robot_yaw(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'robot_yaw' field must be of type 'float'"
        self._robot_yaw = value
