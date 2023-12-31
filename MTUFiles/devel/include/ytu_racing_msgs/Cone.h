// Generated by gencpp from file ytu_racing_msgs/Cone.msg
// DO NOT EDIT!


#ifndef YTU_RACING_MSGS_MESSAGE_CONE_H
#define YTU_RACING_MSGS_MESSAGE_CONE_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <geometry_msgs/Pose.h>

namespace ytu_racing_msgs
{
template <class ContainerAllocator>
struct Cone_
{
  typedef Cone_<ContainerAllocator> Type;

  Cone_()
    : pose()  {
    }
  Cone_(const ContainerAllocator& _alloc)
    : pose(_alloc)  {
  (void)_alloc;
    }



   typedef  ::geometry_msgs::Pose_<ContainerAllocator>  _pose_type;
  _pose_type pose;



// reducing the odds to have name collisions with Windows.h 
#if defined(_WIN32) && defined(YELLOW)
  #undef YELLOW
#endif
#if defined(_WIN32) && defined(BLUE)
  #undef BLUE
#endif
#if defined(_WIN32) && defined(ORANGE)
  #undef ORANGE
#endif
#if defined(_WIN32) && defined(UNKNOWN)
  #undef UNKNOWN
#endif

  enum {
    YELLOW = 0u,
    BLUE = 1u,
    ORANGE = 2u,
    UNKNOWN = 3u,
  };


  typedef boost::shared_ptr< ::ytu_racing_msgs::Cone_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ytu_racing_msgs::Cone_<ContainerAllocator> const> ConstPtr;

}; // struct Cone_

typedef ::ytu_racing_msgs::Cone_<std::allocator<void> > Cone;

typedef boost::shared_ptr< ::ytu_racing_msgs::Cone > ConePtr;
typedef boost::shared_ptr< ::ytu_racing_msgs::Cone const> ConeConstPtr;

// constants requiring out of line definition

   

   

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ytu_racing_msgs::Cone_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ytu_racing_msgs::Cone_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::ytu_racing_msgs::Cone_<ContainerAllocator1> & lhs, const ::ytu_racing_msgs::Cone_<ContainerAllocator2> & rhs)
{
  return lhs.pose == rhs.pose;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::ytu_racing_msgs::Cone_<ContainerAllocator1> & lhs, const ::ytu_racing_msgs::Cone_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace ytu_racing_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::ytu_racing_msgs::Cone_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ytu_racing_msgs::Cone_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ytu_racing_msgs::Cone_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ytu_racing_msgs::Cone_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ytu_racing_msgs::Cone_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ytu_racing_msgs::Cone_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ytu_racing_msgs::Cone_<ContainerAllocator> >
{
  static const char* value()
  {
    return "1206c6df74d2e8766edc7b47aed8e97d";
  }

  static const char* value(const ::ytu_racing_msgs::Cone_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x1206c6df74d2e876ULL;
  static const uint64_t static_value2 = 0x6edc7b47aed8e97dULL;
};

template<class ContainerAllocator>
struct DataType< ::ytu_racing_msgs::Cone_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ytu_racing_msgs/Cone";
  }

  static const char* value(const ::ytu_racing_msgs::Cone_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ytu_racing_msgs::Cone_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint8 YELLOW=0\n"
"uint8 BLUE=1\n"
"uint8 ORANGE=2\n"
"uint8 UNKNOWN=3\n"
"\n"
"geometry_msgs/Pose pose\n"
"================================================================================\n"
"MSG: geometry_msgs/Pose\n"
"# A representation of pose in free space, composed of position and orientation. \n"
"Point position\n"
"Quaternion orientation\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Point\n"
"# This contains the position of a point in free space\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Quaternion\n"
"# This represents an orientation in free space in quaternion form.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"float64 w\n"
;
  }

  static const char* value(const ::ytu_racing_msgs::Cone_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ytu_racing_msgs::Cone_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.pose);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Cone_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ytu_racing_msgs::Cone_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ytu_racing_msgs::Cone_<ContainerAllocator>& v)
  {
    s << indent << "pose: ";
    s << std::endl;
    Printer< ::geometry_msgs::Pose_<ContainerAllocator> >::stream(s, indent + "  ", v.pose);
  }
};

} // namespace message_operations
} // namespace ros

#endif // YTU_RACING_MSGS_MESSAGE_CONE_H
