#!/usr/bin/env python

import rospy
from ros_tutorial.msg import Sensor
import random

pub = rospy.Publisher('msg_topic', Sensor, queue_size=10)

rospy.init_node('msg_publisher_node', anonymous=True)

rate = rospy.Rate(1)

i = 0

while not rospy.is_shutdown() :
    msg = Sensor()
    msg.id = 1
    msg.name = 'Front door sensor'
    msg.temperature = 24.3 + random.random()*2
    msg.humidity = 24.3 + random.random()*2
    rospy.loginfo('I publish:')
    rospy.loginfo(msg)
    pub.publish(msg)
    rate.sleep()
    i += 1
