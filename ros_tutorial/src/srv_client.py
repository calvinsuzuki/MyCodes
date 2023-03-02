#!/usr/bin/env python

from ros_tutorial.srv import Add_
from ros_tutorial.srv import Add_Request
from ros_tutorial.srv import Add_Response

import rospy
import sys

def add_two_ints_client(x, y) :
    rospy.wait_for_service('add')
    try:
        add = rospy.ServiceProxy('add', Add_)
        response = add(x, y)
        return response.acc
    except rospy.ServiceException(e) as e:
        print(f'Service call failed: {e}')

if __name__ == '__main__' :
    print(add_two_ints_client(7, 11))
    