#! /usr/bin/python
import rospy

# You can do this cause of the __init__.py. This declares a python package
# Everything inside the directory becomes a python module
from cmdvel_class import CmdVel


def run():	
	# Initialise node. Same as a nodehandle when comparing with roscpp
	rospy.init_node('cmdvel')

	# Instantiate the object cmdvel. Essentially from cmdvel_class.py
	cmdvel = CmdVel()
	print(cmdvel.test)
	rospy.sleep(0.5)
	rospy.loginfo('Node started')

	rospy.loginfo('Running until shutdown (Ctrl-C).')
	while not rospy.is_shutdown():
		cmdvel.run_once()
		rospy.sleep(0.5)

	rospy.loginfo('Node finished')

if __name__ == '__main__':
	run()
