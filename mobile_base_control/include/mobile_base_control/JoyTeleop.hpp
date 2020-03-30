#pragma once 
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/Joy.h>


namespace joy_teleop{

class JoyTeleop
{
public:
  JoyTeleop();

private:
  bool initFromParams();
  void joyCallback(const sensor_msgs::Joy::ConstPtr& joy);

  ros::NodeHandle nh_;

  bool initialized_ = false;
  int linear_, angular_;
  double l_scale_, a_scale_;
  
  std::string twist_topic_;
  std::string joy_topic_;
  ros::Publisher twist_pub_;
  ros::Subscriber joy_sub_;

};



}