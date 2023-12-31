#include "LidarConeDetection.hpp"

LidarConeDetection::LidarConeDetection(ros::NodeHandle *nh)
{
    sub = nh->subscribe("/scan", 1000, &LidarConeDetection::lidarCallback, this);
    marker_array_pub = nh->advertise<visualization_msgs::MarkerArray>("LidarDetectedConePositionsMarkers", 0);
    cone_array_pub = nh->advertise<ytu_racing_msgs::Track>("LidarDetectedConePosition", 0);
}

void LidarConeDetection::lidarCallback(const sensor_msgs::LaserScan::ConstPtr &msg)
{
    std::vector<float> data = msg->ranges; // data arrayi
    std::vector<std::vector<float>> cone_data;
    std::vector<float> polar_coordinates;
    std::vector<float> cartasian_coordinates;
    inf_to_max(data); // infleri 8`e ceviriyor
    cone_data = found_cone(data);
    polar_coordinates = cone_data_to_polar_cordinates(cone_data);
    cartasian_coordinates = polar_coordinates_to_cartesian(polar_coordinates);
    publish_marker_array(cartasian_coordinates);
    publish_cone_array(cartasian_coordinates);
}

float LidarConeDetection::degree2radians(float degrees)
{
    return degrees * (PI / 180);
}

void LidarConeDetection::inf_to_max(std::vector<float> &data)
{
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i] == std::numeric_limits<float>::infinity())
            data[i] = 8;
    }
}

// -----------------------------------------------------------

std::vector<float> &LidarConeDetection::derivative(std::vector<float> &data)
{
    std::vector<float> derivativeData;
    float tempDerivative = 0;
    float left = 0;
    float right = 0;

    derivativeData.push_back(0);
    for (size_t i = 1; i < data.size() - 1; i++)
    {
        left = data[i - 1];
        right = data[i + 1];
        if (left > 0.20 && right > 0.20)
            tempDerivative = left - right;
        else
            tempDerivative = 0;
        derivativeData.push_back(tempDerivative);
    }
    derivativeData.push_back(0);
    return (derivativeData);
}

std::vector<std::vector<float>> &LidarConeDetection::setAngles(std::vector<float> &jumps, std::vector<float> &data)
{
    std::vector<std::vector<float>> cone_data;
    std::vector<float> cone_ranges;
    std::vector<float> cone_angles;
    bool cone;
    float threshold;
    size_t j;

    cone = false;
    threshold = 0.20;
    for (size_t i = 0; i < data.size(); i++)
    {
        if (abs(jumps[i]) > threshold && cone == false)
        {
            cone = true;
            j = i;
        }

        else if (cone == true)
        {
            if (abs(jumps[i]) > threshold && jumps[i] > 0)
                j = i;
            if (abs(jumps[i]) > threshold && jumps[i] < 0)
            {
                while (j < i && j < data.size())
                {
                    cone_angles.push_back(j);
                    cone_ranges.push_back(data[j]);
                    j++;
                }
                cone_data.push_back(cone_angles);
                cone_data.push_back(cone_ranges);
                cone_angles.clear();
                cone_ranges.clear();
                cone = false;
            }
        }
    }
    return (cone_data);
}

std::vector<std::vector<float>> LidarConeDetection::found_cone_2(std::vector<float> &data)
{
    std::vector<std::vector<float>> cone_data;
    std::vector<float> jumps;

    jumps = derivative(data);
    cone_data = setAngles(jumps, data);
    return (cone_data);
}

// -----------------------------------------------------------

std::vector<std::vector<float>> LidarConeDetection::found_cone(std::vector<float> &data)
{
    std::vector<std::vector<float>> cone_data;
    std::vector<float> cone_ranges;
    std::vector<float> cone_angles;
    bool flag;

    flag = false;
    for (int i = 0; i < data.size(); i++)
    {
        if (flag == false && data[i] < 8)
        {
            cone_ranges.push_back(data[i]);
            cone_angles.push_back(i);
            flag = true;
        }
        else if (flag == true && data[i] < 8)
        {
            cone_ranges.push_back(data[i]);
            cone_angles.push_back(i);
        }
        else if (flag == true && data[i] == 8)
        {
            cone_data.push_back(cone_ranges);
            cone_data.push_back(cone_angles);
            cone_ranges.clear();
            cone_angles.clear();
            flag = false;
        }
    }
    return (cone_data);
}

float LidarConeDetection::vector_min(std::vector<float> cone_data)
{
    float min;

    min = cone_data[0];
    for (int i = 0; i < cone_data.size(); i++)
    {
        if (cone_data[i] < min)
            min = cone_data[i];
    }
    return (min);
}

float LidarConeDetection::vector_mean(std::vector<float> cone_data)
{
    if ((cone_data.size() % 2) == 0)
    {
        return ((cone_data[(cone_data.size() / 2) - 1] + cone_data[(cone_data.size() / 2)]) / 2);
    }
    else if ((cone_data.size() % 2) == 1)
    {
        return (cone_data[(cone_data.size() / 2)]);
    }
}

std::vector<float> LidarConeDetection::cone_data_to_polar_cordinates(std::vector<std::vector<float>> &cone_data)
{
    std::vector<float> polar_cone_coordinates;

    for (int i = 0; i < cone_data.size(); i++)
    {
        if ((i % 2) == 0)
        {
            polar_cone_coordinates.push_back(vector_min(cone_data[i]));
        }
        else if ((i % 2) == 1)
        {
            polar_cone_coordinates.push_back(vector_mean(cone_data[i]));
        }
    }
    return (polar_cone_coordinates);
}

std::vector<float> LidarConeDetection::polar_coordinates_to_cartesian(std::vector<float> polar_cone_coordinates)
{
    std::vector<float> cartesian_cordinates;
    float x;
    float y;

    for (int i = 0; i < polar_cone_coordinates.size(); i++)
    {
        if ((i % 2) == 0)
        {
            x = polar_cone_coordinates[i] * sin(degree2radians((polar_cone_coordinates[i + 1] * 180.0) / 362));
            y = polar_cone_coordinates[i] * cos(degree2radians((polar_cone_coordinates[i + 1] * 180.0) / 362));
            cartesian_cordinates.push_back(x + 0.45);
            cartesian_cordinates.push_back(y);
        }
    }
    return (cartesian_cordinates);
}

void LidarConeDetection::publish_marker_array(std::vector<float> cone_coordinates)
{
    visualization_msgs::MarkerArray markerarray;
    for (int i = 0; i < cone_coordinates.size(); i++)
    {
        if ((i % 2) == 0)
        {
            visualization_msgs::Marker marker;
            marker.header.frame_id = "fsds/FSCar";
            marker.header.stamp = ros::Time();
            marker.ns = "ytu_racing";
            marker.id = i;
            marker.type = visualization_msgs::Marker::SPHERE;
            marker.action = visualization_msgs::Marker::ADD;
            marker.pose.position.x = cone_coordinates[i];
            marker.pose.position.y = cone_coordinates[i + 1] * -1;
            marker.pose.position.z = 0.5;
            marker.pose.orientation.x = 0.0;
            marker.pose.orientation.y = 0.0;
            marker.pose.orientation.z = 0.0;
            marker.pose.orientation.w = 1.0;
            marker.scale.x = 0.1;
            marker.scale.y = 0.1;
            marker.scale.z = 0.1;
            marker.color.a = 1.0;
            marker.color.r = 0.0;
            marker.color.g = 1.0;
            marker.color.b = 0.0;
            markerarray.markers.push_back(marker);
        }
        marker_array_pub.publish(markerarray);
    }
}

void LidarConeDetection::publish_cone_array(std::vector<float> cone_coordinates)
{
    ytu_racing_msgs::Track conearray;
    for (int i = 0; i < cone_coordinates.size(); i++)
    {
        if ((i % 2) == 0)
        {
            ytu_racing_msgs::TrackCone cone;
            cone.x = cone_coordinates[i];
            cone.y = cone_coordinates[i + 1] * -1;
            conearray.cones.push_back(cone);
        }
        cone_array_pub.publish(conearray);
    }
}