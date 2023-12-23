#ifndef LIDARCONEDETECTION
# define LIDARCONEDETECTION

# include <ros/ros.h>
# include <iostream>
# include <cmath>
# include <sensor_msgs/LaserScan.h>
# include <visualization_msgs/Marker.h>
# include <visualization_msgs/MarkerArray.h>
# include <ytu_racing_msgs/TrackCone.h>
# include <ytu_racing_msgs/Track.h>

# define PI 3.141592653589793238462643383279502884L 


class LidarConeDetection
{
private:
    ros::Subscriber sub;
    ros::Publisher marker_array_pub;
    ros::Publisher cone_array_pub;

public:
    LidarConeDetection(ros::NodeHandle *nh);
    void lidarCallback(const sensor_msgs::LaserScan::ConstPtr &msg);
    float degree2radians(float degrees);
    void inf_to_max(std::vector<float> &data);
    std::vector<float> &derivative(std::vector<float> &data);
    std::vector<std::vector<float>> &setAngles(std::vector<float> &jumps, std::vector<float> &data);
    std::vector<std::vector<float>> found_cone_2(std::vector<float> &data);
    std::vector<std::vector<float>> found_cone(std::vector<float> &data);
    float vector_min(std::vector<float> cone_data);
    float vector_mean(std::vector<float> cone_data);
    std::vector<float> cone_data_to_polar_cordinates(std::vector<std::vector<float>> &cone_data);
    std::vector<float> polar_coordinates_to_cartesian(std::vector<float> polar_cone_coordinates);
    void publish_marker_array(std::vector<float> cone_coordinates);
    void publish_cone_array(std::vector<float> cone_coordinates);
};

#endif