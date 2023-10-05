#include "ros/init.h"
#include "ros/node_handle.h"
#include "ros/service_server.h"
#include "ros/ros.h"
#include "calculate_factorial/server.h"

bool factorialCalc(calculate_factorial::server::Request& req, calculate_factorial::server::Response& resp)
{
    // basit bir factorial bulma fonksiyonu
    long int result = 1;
    for (long int i = 1; i <= req.number; i++)
        result *= i;
    // clientin de erişmesi için sonucu service'in icindeki resulta atıyoruz.
    resp.result = result;
    ROS_INFO("Input number: %ld, Result: %ld\n", (long int)req.number, resp.result);
    return true;
}


int main(int ac, char **av)
{
    ros::init(ac, av, "factorial_calculate_server", 0);

    // NodeHandle turunden bir degisken tanimliyoruz.
    ros::NodeHandle node_handle;

    // ServiceServer turunden degisken tanimliyoruz.
    ros::ServiceServer server;

    // server degiskenini baslatiyoruz.
    server = node_handle.advertiseService("factorial_calculate", factorialCalc);

    ros::spin();

    return (0);
}