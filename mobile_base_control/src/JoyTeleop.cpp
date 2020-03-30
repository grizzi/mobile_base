#include "mobile_base_control/JoyTeleop.hpp"

using namespace joy_teleop;

JoyTeleop::JoyTeleop(){
  initialized_ = initFromParams();
  twist_pub_ = nh_.advertise<geometry_msgs::Twist>(twist_topic_, 1);
  joy_sub_ = nh_.subscribe<sensor_msgs::Joy>(joy_topic_, 10, &JoyTeleop::joyCallback, this);
}


bool JoyTeleop::initFromParams(){
  if (!nh_.getParam("axis_linear", linear_)){
    ROS_ERROR_STREAM("Failed to parse linear axis.");
    return false;
  }
  if (!nh_.getParam("axis_angular", linear_)){
    ROS_ERROR_STREAM("Failed to parse angular axis.");
    return false;
  }
  if (!nh_.getParam("axis_linear", l_scale_)){
    ROS_ERROR_STREAM("Failed to parse linear max speed.");
    return false;
  }
  if (!nh_.getParam("axis_linear", a_scale_)){
    ROS_ERROR_STREAM("Failed to parse angular max speed.");
    return false;
  }
  if (!nh_.getParam("twist_topic", twist_topic_)){
    ROS_ERROR_STREAM("Failed to parse twist topic.");
    return false;
  }
  if (!nh_.getParam("joy_topic", joy_topic_)){
    ROS_ERROR_STREAM("Failed to parse joy topic.");
    return false;
  } 
  return true;
}


void JoyTeleop::joyCallback(const sensor_msgs::Joy::ConstPtr& joy)
{
  if (!initialized_){
    ROS_WARN_THROTTLE(2.0, "Failed to initialize joy teleop. Skipping command.");
    return;
  }

  geometry_msgs::Twist twist;
  twist.angular.z = a_scale_*joy->axes[angular_];
  twist.linear.x = l_scale_*joy->axes[linear_];
  twist_pub_.publish(twist);
}
