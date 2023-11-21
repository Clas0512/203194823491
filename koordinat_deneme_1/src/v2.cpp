#include "ros/init.h"
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <fs_msgs/ControlCommand.h>
#include <sensor_msgs/LaserScan.h>
#include <iostream>

float PI = 3,1415926535;
float   leftConeDist;
float   rightConeDist;

float minDist(std::vector<float> dists)
{
    std::vector<float>::iterator minimum = std::min_element(dists.begin(), dists.end());
    return (*minimum);
}

float   degreeToRadian(int degree)
{
    float radian = (degree * PI) / 180;
    return (radian);
}

float getCosAlpha(int alpha, float hipo)
{
    float cosAlphaDist = cos(alpha) * hipo;
    return (cosAlphaDist);
}

float getSinAlpha(int alpha, float hipo)
{
    float sinAlphaDist = sin(alpha) * hipo;
    return (sinAlphaDist);
}

void lidarScan(const sensor_msgs::LaserScan::ConstPtr& msg)
{
    std::vector<float> data = msg->ranges;
    int dataSize = data.size();

    for (int angle = 0; angle < dataSize ; i++)
    {

        if (data[angle] == std::numeric_limits<float>::infinity())
            data[angle] = 8;
        else
        {
            std::vector<float> leftCones;
            std::vector<float> rightCones;
            while (data[angle] != std::numeric_limits<float>::infinity()
                    && angle < dataSize)
            {
                // ROS_INFO("Cone DATA : %f\n", data[angle]);
                if (angle >= dataSize / 2)
                    rightCones.push_back(getCosAlpha(angle, data[angle]));
                else
                    leftCones.push_back(getCosAlpha(angle, data[angle]));
                rightConeDist = minDist(rightConeDist);
                leftConeDist = minDist(leftConeDist);
                i++;
            }
        }
    }
}

int main(int ac, char **av)
{

    ros::init(ac, av, "v2", 0);
    ros::NodeHandle nodeManage;
    ros::Subscriber subs;
    ros::Publisher pub;

    
    ros::Rate rateHz(10);
    pub = nodeManage.advertise<fs_msgs::ControlCommand>("/fsds/control_command", 1);
    fs_msgs::ControlCommand cmd = fs_msgs::ControlCommand();
    cmd.header.stamp = ros::Time::now();
    subs = nodeManage.subscribe("scan", 1000, lidarScan);

    leftConeDist = 0;
    rightConeDist = 0;
    int throttleManageCount = 0;
    cmd.throttle = 0;
    cmd.steering = 0;
    cmd.brake = 0;
    // int steeringManip = 0;
    while (ros::ok())
    {
        // ROS_INFO("left: %lld\n", leftConeDist);
        // ROS_INFO("right: %lld\n", rightConeDist);
        // if (leftConeDist > 5 && steeringManip % 15 == 0)
        //     cmd.steering = -0.5;
        // else if (rightConeDist > 5 && steeringManip % 30 == 0)
        //     cmd.steering = +0.5;
        // if (steeringManip % 40 == 0){
        //     cmd.steering = 0;
        //     steeringManip = 0;
        // }
        float fark = ((leftConeDist + rightConeDist) / 2) - leftConeDist;
        ROS_INFO("FARK : %f\n", fark);
        if (fark != 0)
            cmd.steering = fark * (fark / 10);
        if (throttleManageCount % 50 == 0)
            cmd.throttle = 0.5;
        else if (throttleManageCount % 10 == 0)
            cmd.throttle = 0;
        else if (throttleManageCount % 60 == 0)
            throttleManageCount = 0;
        throttleManageCount++;
        // steeringManip++;
        pub.publish(cmd);
        rateHz.sleep();
        ros::spinOnce();
    }
    return (0);
}
