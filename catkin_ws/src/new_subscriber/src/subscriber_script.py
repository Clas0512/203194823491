#!/usr/bin/env python

import rospy
from std_msgs.msg import String

def callback(data):
    rospy.loginfo("Received message: %s", data.data)

def listener():
    rospy.init_node("subscriber_script", anonymous=True)
    rospy.Subscriber("Anything", String, callback)
    rospy.spin()

if __name__ == "__main__":
    listener()