#!/usr/bin/env python

import rospy
from std_msgs.msg import String

rospy.init_node("publisher_script", anonymous=True)
pub = rospy.Publisher("Anything", String, queue_size=10)

rate = rospy.Rate(10)

while not rospy.is_shutdown():
    message = "Selam Millett !!"
    rospy.loginfo(message)
    pub.publish(message)
    rate.sleep()

