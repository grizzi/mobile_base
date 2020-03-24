cmake_minimum_required(VERSION 2.8.3)
project(mobile_base_control)
set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra")

set(PACKAGE_DEPENDENCIES
  controller_manager
  velocity_controllers
  diff_drive_controller
)

find_package(catkin REQUIRED COMPONENTS
  ${PACKAGE_DEPENDENCIES}
)

catkin_package()

install(DIRECTORY launch config
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)
