# generated from rosidl_generator_py/resource/_idl.py.em
# with input from interfaces:msg/Dect2.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Dect2(type):
    """Metaclass of message 'Dect2'."""

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
                'interfaces.msg.Dect2')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__dect2
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__dect2
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__dect2
            cls._TYPE_SUPPORT = module.type_support_msg__msg__dect2
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__dect2

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Dect2(metaclass=Metaclass_Dect2):
    """Message class 'Dect2'."""

    __slots__ = [
        '_cam_x',
        '_cam_y',
        '_cam_z',
    ]

    _fields_and_field_types = {
        'cam_x': 'double',
        'cam_y': 'double',
        'cam_z': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.cam_x = kwargs.get('cam_x', float())
        self.cam_y = kwargs.get('cam_y', float())
        self.cam_z = kwargs.get('cam_z', float())

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
        if self.cam_x != other.cam_x:
            return False
        if self.cam_y != other.cam_y:
            return False
        if self.cam_z != other.cam_z:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

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
    def cam_z(self):
        """Message field 'cam_z'."""
        return self._cam_z

    @cam_z.setter
    def cam_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'cam_z' field must be of type 'float'"
        self._cam_z = value
