#include "ros/node_handle.h"
#include "ros/ros.h"
#include "calculate_factorial/server.h"
#include "ros/service_client.h"

int main(int ac, char **av)
{
    ros::init(ac, av, "factorial_calculate_client");

    if (ac != 2)
    {
        ROS_INFO("Wrong argument!.\n");
        return (1);
    }

    ros::NodeHandle node_handle;

    ros::ServiceClient client;

    calculate_factorial::server serv;
    // programi calistirirken verilecek olan sayıyı string olarak tuttugu için longa ceviriyoruz ve
    // service'in icinde request'in sayisi olarak belirliyoruz. Bunu servera gonderecegiz.
    serv.request.number = atol(av[1]);

    client = node_handle.serviceClient<calculate_factorial::server>("factorial_calculate");

    if (client.call(serv))
    {
        ROS_INFO("Service called successfully and factorial is: %ld\n", serv.response.result);
    }
    else
    {
        ROS_ERROR("Failed to call service");
        return (1);
    }

    return (0);
}