cmake_minimum_required(VERSION 2.8.3)
project(mobile_base_sim)
set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra")

set(PACKAGE_DEPENDENCIES
  mobile_base_gazebo
  mobile_base_control
  rqt_controller_manager
)

find_package(catkin REQUIRED COMPONENTS
  ${PACKAGE_DEPENDENCIES}
)

catkin_package()

install(DIRECTORY launch config
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)
