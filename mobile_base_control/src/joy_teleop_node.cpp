#include <ros/ros.h>
#include "mobile_base_control/JoyTeleop.hpp"


int main(int argc, char** argv)
{
  ros::init(argc, argv, "joy_twist_node");
  ros::NodeHandle nh("~");

  joy_teleop::JoyTeleop joy(nh);
  ros::spin();
}
