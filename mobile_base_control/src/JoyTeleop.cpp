#include "mobile_base_control/JoyTeleop.hpp"

using namespace joy_teleop;

JoyTeleop::JoyTeleop(ros::NodeHandle& nh): nh_(nh){
  initialized_ = initParams();
  if (initialized_){
    twist_pub_ = nh_.advertise<geometry_msgs::Twist>(twist_topic_, 1);
    joy_sub_ = nh_.subscribe<sensor_msgs::Joy>(joy_topic_, 10, &JoyTeleop::joyCallback, this);
    pub_thread_ = nh_.createTimer(ros::Duration(0.1), &JoyTeleop::pubThreadCallback, this);
  }
}


bool JoyTeleop::initParams(){
  std::cout << ros::this_node::getNamespace() << std::endl;
  if (!nh_.getParam("axis_linear", linear_)){
    ROS_ERROR_STREAM("Failed to parse linear axis.");
    return false;
  }
  if (!nh_.getParam("axis_angular", angular_)){
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
  enabled_ = false;
  return true;
}

void JoyTeleop::pubThreadCallback(const ros::TimerEvent& event){
  if (enabled_){
    std::shared_lock lock(mutex_);
    twist_pub_.publish(last_twist_);
  }
}


void JoyTeleop::joyCallback(const sensor_msgs::Joy::ConstPtr& joy)
{
  std::unique_lock lock(mutex_);
  enabled_ = true;
  last_twist_.angular.z = a_scale_*joy->axes[angular_];
  last_twist_.linear.x = l_scale_*joy->axes[linear_];
}
