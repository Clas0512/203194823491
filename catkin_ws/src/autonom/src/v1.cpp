#include "ros/init.h"
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <fs_msgs/ControlCommand.h>
#include <sensor_msgs/LaserScan.h>

void my_func (const sensor_msgs::LaserScan::ConstPtr& msg){
    std::vector<float> data = msg->ranges;
    int len = data.size();
    for (int i = 0; i < len; i++)
    {
        if (data[i] == std::numeric_limits<float>::infinity())
            data[i] = 8;
        else
            ROS_INFO("ZOOOOOORT!------> %f", data[i]);
            
    }
    
    
}

int main(int ac, char **av) {

  ros::init(ac, av, "v1", 0);

  ros::NodeHandle nodeHandle;

  ros::Subscriber subscriber;

  subscriber = nodeHandle.subscribe("scan", 1000, my_func);

  //ros::Rate rateHz(10);

  //publisher = nodeHandle.advertise<std_msgs::String>("Anything", 1000);
  //publisher = nodeHandle.advertise<fs_msgs::ControlCommand>("/fsds/control_command", 1);
  ros::spin();

}