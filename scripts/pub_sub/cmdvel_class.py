# Notice that this file doesn't have #! /usr/bin/python3. This makes it
# That line is only included when the file is an executable. 
# When the file is called ('cmdvel_node.py'), bash will refer to that line
# to dictate which program will help in executing the file. 

import rospy
import random
from geometry_msgs.msg import Twist


class CmdVel(object):
	"""
	This class just talks to itself.
	"""

	def __init__(self):
		self._pub = rospy.Publisher('cmd_vel', Twist, queue_size=10)

	def run_once(self):
		"""
		Main doer method. Blocking here is generally bad.
		"""
		twist = Twist()
		twist.linear.x = random.uniform(0, 1)
		twist.linear.y = random.uniform(0, 1)
		twist.linear.z = random.uniform(0, 1)
		twist.angular.x = 0
		twist.angular.y = 0
		twist.angular.z = random.uniform(0, 1)
		self._pub.publish(twist)

# No main/run code, see cmdvel_node.py for the node execution.
