#pragma once 
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/Joy.h>
#include <shared_mutex>

namespace joy_teleop{

class JoyTeleop
{
public:
  JoyTeleop(ros::NodeHandle& nh);

private:
  bool initParams();
  void joyCallback(const sensor_msgs::Joy::ConstPtr& joy);
  void pubThreadCallback(const ros::TimerEvent& event);

  ros::NodeHandle nh_;

  bool initialized_ = false;
  int linear_, angular_;
  double l_scale_, a_scale_;
  
  std::string twist_topic_;
  std::string joy_topic_;
  ros::Publisher twist_pub_;
  ros::Subscriber joy_sub_;
  ros::Timer pub_thread_;

  std::atomic_bool enabled_;

  mutable std::shared_mutex mutex_;
  geometry_msgs::Twist last_twist_;

};



}