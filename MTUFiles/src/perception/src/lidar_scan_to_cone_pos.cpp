#include "LidarConeDetection.hpp"

int main(int argc, char** argv)
{
    ros::init(argc, argv, "cone_detection");
    ros::NodeHandle nh;
	LidarConeDetection lidar = LidarConeDetection(&nh);
    ros::spin();
}
