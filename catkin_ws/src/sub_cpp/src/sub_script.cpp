#include "ros/init.h"
#include "ros/node_handle.h"
#include "ros/spinner.h"
#include "ros/subscriber.h"
#include <ros/ros.h>
#include <std_msgs/String.h>

void handle(const std_msgs::String::ConstPtr &message) {
  ROS_INFO("message -> %s\n", message->data.c_str());
}

int main(int ac, char **av) {
  ros::init(ac, av, "sub_script", 0);
  ros::Subscriber aboneyim_abone;
  ros::NodeHandle nodeHandle;

  aboneyim_abone = nodeHandle.subscribe("Anything", 1000, handle);

  ros::spin();
}