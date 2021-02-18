#include <ros/ros.h>
#include <CmdVel.hpp>

int main (int argc, char **argv) {
	ros::init(argc, argv, "demo_pub_sub");
	ros::NodeHandle nodeHandle;

	CmdVel worker(&nodeHandle);
	ros::Duration(0.5).sleep();
	worker.init();
	
	ROS_INFO_STREAM("Node started");
	ros::Rate rate = ros::Rate(10);

	while (ros::ok()) {
		ros::spinOnce();
		rate.sleep();
		worker.pub();
	}
}
