#pragma once
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

class CmdVel {
	public:
		CmdVel(ros::NodeHandle *nodeHandle);
		virtual ~CmdVel(void);
		bool init(void);
		void pub(void);

	protected:
		ros::NodeHandle *nodeHandle_;
		ros::Publisher publisher_;
};
