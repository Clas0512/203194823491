// Generated by gencpp from file calculate_factorial/serverResponse.msg
// DO NOT EDIT!


#ifndef CALCULATE_FACTORIAL_MESSAGE_SERVERRESPONSE_H
#define CALCULATE_FACTORIAL_MESSAGE_SERVERRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace calculate_factorial
{
template <class ContainerAllocator>
struct serverResponse_
{
  typedef serverResponse_<ContainerAllocator> Type;

  serverResponse_()
    : result(0)  {
    }
  serverResponse_(const ContainerAllocator& _alloc)
    : result(0)  {
  (void)_alloc;
    }



   typedef int64_t _result_type;
  _result_type result;





  typedef boost::shared_ptr< ::calculate_factorial::serverResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::calculate_factorial::serverResponse_<ContainerAllocator> const> ConstPtr;

}; // struct serverResponse_

typedef ::calculate_factorial::serverResponse_<std::allocator<void> > serverResponse;

typedef boost::shared_ptr< ::calculate_factorial::serverResponse > serverResponsePtr;
typedef boost::shared_ptr< ::calculate_factorial::serverResponse const> serverResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::calculate_factorial::serverResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::calculate_factorial::serverResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace calculate_factorial

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::calculate_factorial::serverResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::calculate_factorial::serverResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::calculate_factorial::serverResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::calculate_factorial::serverResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::calculate_factorial::serverResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::calculate_factorial::serverResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::calculate_factorial::serverResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "9b05623554ab950ed237d43d45f0b4dd";
  }

  static const char* value(const ::calculate_factorial::serverResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x9b05623554ab950eULL;
  static const uint64_t static_value2 = 0xd237d43d45f0b4ddULL;
};

template<class ContainerAllocator>
struct DataType< ::calculate_factorial::serverResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "calculate_factorial/serverResponse";
  }

  static const char* value(const ::calculate_factorial::serverResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::calculate_factorial::serverResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int64 result\n\
\n\
";
  }

  static const char* value(const ::calculate_factorial::serverResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::calculate_factorial::serverResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.result);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct serverResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::calculate_factorial::serverResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::calculate_factorial::serverResponse_<ContainerAllocator>& v)
  {
    s << indent << "result: ";
    Printer<int64_t>::stream(s, indent + "  ", v.result);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CALCULATE_FACTORIAL_MESSAGE_SERVERRESPONSE_H
