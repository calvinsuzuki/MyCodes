#!/usr/bin/env python

from ros_tutorial.srv import Add_
from ros_tutorial.srv import Add_Request
from ros_tutorial.srv import Add_Response

import rospy

def handler_add(req) :
    print(f'Return [{req.a} + {req.b} = {req.a+req.b}]')
    return Add_Response(req.a + req.b)

def add_two_ints_server() :
    rospy.init_node('add_server')
    s = rospy.Service('add', Add_, handler_add)
    print('Ready to add: ')
    rospy.spin()

if __name__ == '__main__' :
    add_two_ints_server()