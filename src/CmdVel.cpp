#include <CmdVel.hpp>

CmdVel::CmdVel(ros::NodeHandle *nodeHandle) :  nodeHandle_(nodeHandle) {}

CmdVel::~CmdVel(void) {}

bool CmdVel::init(void) {
	// Intialise /cmd_vel publisher
	publisher_ = nodeHandle_->advertise<geometry_msgs::Twist>("/cmd_vel", 10);
	return true;
}

void CmdVel::pub(void) {
	float rand_ = rand() / (RAND_MAX + 1.);
	geometry_msgs::Twist msg;
	
	// Initialise the message
	msg.linear.x = rand_;
	msg.linear.y = 0.0f;
	msg.linear.z = rand_;

	msg.angular.x = 0.0f;
	msg.angular.y = 0.0f;
	msg.angular.z = rand_;
	publisher_.publish(msg);
}
