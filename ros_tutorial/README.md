# ros_tutorial: A simple ROS package with 3 Example Nodes

Created after study [ROS for Beginners](https://www.udemy.com/course/ros-essentials) Anis Koubaa course.

## Installation

Clone it to your src folder in your ros workspace and build.

```bash
cd ~/catkin_ws/src
<place ros_tutorial folder here>
cd ~/catkin_ws
catkin_make
```

## IMPORTANT

To run any of the exercises, you must run the command:

>Terminal 0:

```bash
roscore
```

In order to get everything connected in ROS Network, we must run ROS Master.

## Exercise 1: Basic Publisher and Listener

Firstly, let's run Talker Node:

>Terminal 1:

```bash
rosrun ros_tutorial talker.py
```

After starting it, you should see some messages popping in Terminal 1. Those messages are being published by this node.

>Terminal 2:

```bash
rosrun ros_tutorial listener.py
```

Now this Node will subscribe to Talker Node publisher and mimic what is the Terminal 1.

This is exactly the communication point-to-point in Network.

NOTE: If you stop ROS Master, the communication will remain normal, but if you try to restart one of the Nodes, ROS will raise an error.

## Exercise 2: Custom message

ROS supports creation of custom messages to optimize and organize your ROS Application.

In this case, if you peek inside the msg folder, you will find:

>Sensor.msg

```
int32 id
string name
float32 temperature
float32 humidity
```

You also may check this ROS Message with command:

>Terminal 1

```bash
rosmsg show Sensor
```

Similarly to Exercise 1, we are running both Nodes to see their communication:

>Terminal 1:

```bash
rosrun ros_tutorial msg_talker.py
```

>Terminal 2:

```bash
rosrun ros_tutorial msg_listener.py
```

## Exercise 3: ROS Service

A ROS Service is an useful way to request a Node to perform a synchronous action.

We may create our own service, so if you peek inside the srv folder, you will find:

>Add_.srv

```
int64 a
int64 b
---
int64 acc
```

Those three dashes separates the service request from the service response.

This service simply returns the sum of a and b.

>Terminal 1:

```bash
rosrun ros_tutorial srv_server.py
```

>Terminal 2:

```bash
rosrun ros_tutorial srv_client.py
```