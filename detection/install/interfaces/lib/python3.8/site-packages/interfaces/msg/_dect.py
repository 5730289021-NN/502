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

            from std_msgs.msg import Float32MultiArray
            if Float32MultiArray.__class__._TYPE_SUPPORT is None:
                Float32MultiArray.__class__.__import_type_support__()

            from std_msgs.msg import String
            if String.__class__._TYPE_SUPPORT is None:
                String.__class__.__import_type_support__()

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
        '_obj_point',
        '_goal_point',
        '_rotation',
    ]

    _fields_and_field_types = {
        'obj_class': 'std_msgs/String',
        'obj_point': 'std_msgs/Float32MultiArray',
        'goal_point': 'std_msgs/Float32MultiArray',
        'rotation': 'std_msgs/Float32MultiArray',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'String'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Float32MultiArray'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Float32MultiArray'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Float32MultiArray'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import String
        self.obj_class = kwargs.get('obj_class', String())
        from std_msgs.msg import Float32MultiArray
        self.obj_point = kwargs.get('obj_point', Float32MultiArray())
        from std_msgs.msg import Float32MultiArray
        self.goal_point = kwargs.get('goal_point', Float32MultiArray())
        from std_msgs.msg import Float32MultiArray
        self.rotation = kwargs.get('rotation', Float32MultiArray())

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
        if self.obj_point != other.obj_point:
            return False
        if self.goal_point != other.goal_point:
            return False
        if self.rotation != other.rotation:
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
            from std_msgs.msg import String
            assert \
                isinstance(value, String), \
                "The 'obj_class' field must be a sub message of type 'String'"
        self._obj_class = value

    @property
    def obj_point(self):
        """Message field 'obj_point'."""
        return self._obj_point

    @obj_point.setter
    def obj_point(self, value):
        if __debug__:
            from std_msgs.msg import Float32MultiArray
            assert \
                isinstance(value, Float32MultiArray), \
                "The 'obj_point' field must be a sub message of type 'Float32MultiArray'"
        self._obj_point = value

    @property
    def goal_point(self):
        """Message field 'goal_point'."""
        return self._goal_point

    @goal_point.setter
    def goal_point(self, value):
        if __debug__:
            from std_msgs.msg import Float32MultiArray
            assert \
                isinstance(value, Float32MultiArray), \
                "The 'goal_point' field must be a sub message of type 'Float32MultiArray'"
        self._goal_point = value

    @property
    def rotation(self):
        """Message field 'rotation'."""
        return self._rotation

    @rotation.setter
    def rotation(self, value):
        if __debug__:
            from std_msgs.msg import Float32MultiArray
            assert \
                isinstance(value, Float32MultiArray), \
                "The 'rotation' field must be a sub message of type 'Float32MultiArray'"
        self._rotation = value
