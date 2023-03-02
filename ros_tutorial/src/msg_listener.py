#!/usr/bin/env python

import rospy
from ros_tutorial.msg import Sensor

def chatter_callback(message) :
    rospy.loginfo(f"I heard :\nName: {message.name}\nTemperature: {message.temperature}\nHumidity: {message.humidity}")

def listener():
    rospy.init_node('msg_listener_node', anonymous=True)

    rospy.Subscriber('msg_topic', Sensor, chatter_callback)

    rospy.spin()

if __name__ == '__main__' :
    listener()
