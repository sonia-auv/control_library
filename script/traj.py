#!/usr/bin/env python

import rospy
from geometry_msgs.msg import Point, Vector3
from sonia_common.msg import AddPose
import time

class TrajectoryTest():
    def __init__(self, delay):
        rospy.init_node('trajectory_test', anonymous=True)
        self.delay = delay
        self.add_pose_pub = rospy.Publisher("/proc_control/add_pose", AddPose, queue_size=10)
        self.waypoints = [
                        # Go down:
                         #{ 'position': Point(0, 0, 1), 'orientation': Vector3(0, 0, 0), 'frame': 1, 'speed': 5, 'fine': 0, 'rotation': True }
                        # Funny stuff:
                          { 'position': Point(0, 0, 1), 'orientation': Vector3(0, 0, 0), 'frame': 1, 'speed': 5, 'fine': 0, 'rotation': True },
                          { 'position': Point(0, 0, 0), 'orientation': Vector3(0, 65, 0), 'frame': 1, 'speed': 4, 'fine': 0, 'rotation': True },
                          { 'position': Point(0, 0, 0), 'orientation': Vector3(0, 0, 180), 'frame': 1, 'speed': 6, 'fine': 0, 'rotation': True },
			 # { 'position': Point(0, 0, 1), 'orientation': Vector3(0, 0, 0), 'frame': 1, 'speed': 6, 'fine': 0, 'rotation': True },
			  #{ 'position': Point(0, 0, 0), 'orientation': Vector3(0, 0, 180), 'frame': 1, 'speed': 6, 'fine': 0, 'rotation': True },
			  { 'position': Point(0, 0, 0), 'orientation': Vector3(0, 65, 0), 'frame': 1, 'speed': 6, 'fine': 0, 'rotation': True },
			  { 'position': Point(1, 0, 0), 'orientation': Vector3(0, -0, 0), 'frame': 1, 'speed': 5, 'fine': 0, 'rotation': True }	,
                          { 'position': Point(0, 0, 0), 'orientation': Vector3(180, -0, 0), 'frame': 1, 'speed': 3, 'fine': 0, 'rotation': True },	
		          { 'position': Point(0, 0, 0), 'orientation': Vector3(180, -0, 0), 'frame': 1, 'speed': 3, 'fine': 0, 'rotation': True }

			#funnystuff2			  
			 #{ 'position': Point(0, 0, 1), 'orientation': Vector3(0, 0, 0), 'frame': 1, 'speed': 6, 'fine': 0, 'rotation': True },
			 #{ 'position': Point(5, 0, 0), 'orientation': Vector3(360, 0, 0), 'frame': 1, 'speed': 6, 'fine': 0, 'rotation': True }

                        # Square:
                          #{ 'position': Point(0, 0, 1), 'orientation': Vector3(0, 0, 0), 'frame': 1, 'speed': 5, 'fine': 0, 'rotation': True },
                          #{ 'position': Point(5, 0, 0), 'orientation': Vector3(0, 0, 0), 'frame': 1, 'speed': 12, 'fine': 0, 'rotation': True },
                          #{ 'position': Point(0, 0, 0), 'orientation': Vector3(0, 0, 90), 'frame': 1, 'speed': 4, 'fine': 0, 'rotation': True },
                          #{ 'position': Point(0, 5, 0), 'orientation': Vector3(0, 0, 0), 'frame': 1, 'speed': 12, 'fine': 0, 'rotation': True },
                          #{ 'position': Point(0, 0, 0), 'orientation': Vector3(0, 0, 90), 'frame': 1, 'speed': 4, 'fine': 0, 'rotation': True },
                          #{ 'position': Point(-5, 0, 0), 'orientation': Vector3(0, 0, 0), 'frame': 1, 'speed': 12, 'fine': 0, 'rotation': True },
                          #{ 'position': Point(0, 0, 0), 'orientation': Vector3(0, 0, 90), 'frame': 1, 'speed': 4, 'fine': 0, 'rotation': True },
                          #{ 'position': Point(0, -5, 0), 'orientation': Vector3(0, 0, 0), 'frame': 1, 'speed': 12, 'fine': 0, 'rotation': True },
                          #{ 'position': Point(0, 0, 0), 'orientation': Vector3(0, 0, 180), 'frame': 1, 'speed': 4, 'fine': 0, 'rotation': True }

                        # Barrel Roll
                        #  { 'position': Point(0, 0, 1.5), 'orientation': Vector3(0, 0, 0), 'frame': 1, 'speed': 5, 'fine': 0, 'rotation': True },
                        #  { 'position': Point(0, 0, 0), 'orientation': Vector3(180, 0, 0), 'frame': 1, 'speed': 6, 'fine': 0, 'rotation': True },
                        #  { 'position': Point(0, 0, 0), 'orientation': Vector3(180, 0, 0), 'frame': 1, 'speed': 6, 'fine': 0, 'rotation': True }
                         ]                     
        time.sleep(1)

    def start(self):
        for i in range(0, len(self.waypoints)):
            # print(self.waypoints[i])
            self.add_pose_pub.publish(self.waypoints[i]["position"], self.waypoints[i]["orientation"], 
                                      self.waypoints[i]["frame"], self.waypoints[i]["speed"], 
                                      self.waypoints[i]["fine"], self.waypoints[i]["rotation"])
            print("Waypoints {} published".format(i+1))
            print("Waiting {} seconds...".format(self.waypoints[i]["speed"]))
            time.sleep(self.waypoints[i]["speed"])
            print("Making sure he's arrived.")
            time.sleep(self.delay)
        print("Trajectory finished")

if __name__ == '__main__':
    print("************************************")
    print("* Single waypoint publisher script *")
    print("************************************")
    traj = TrajectoryTest(1 )
    traj.start()
