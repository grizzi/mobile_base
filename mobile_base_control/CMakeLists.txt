cmake_minimum_required(VERSION 2.8.3)
project(mobile_base_control)
set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra")

set(PACKAGE_DEPENDENCIES
  controller_manager
  velocity_controllers
  diff_drive_controller
  geometry_msgs
  sensor_msgs
  roscpp
)

find_package(catkin REQUIRED COMPONENTS
  ${PACKAGE_DEPENDENCIES}
)

catkin_package(
  INCLUDE_DIRS 
    include
  LIBRARIES
    joy_teleop 	
  CATKIN_DEPENDS 
    ${PACKAGE_DEPENDENCIES} 
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

# joy control 
add_library(joy_teleop src/JoyTeleop.cpp)
add_dependencies(joy_teleop ${catkin_EXPORTED_TARGETS})
target_link_libraries(joy_teleop ${catkin_LIBRARIES})

add_executable(joy_teleop_node src/joy_teleop_node.cpp)
add_dependencies(joy_teleop_node joy_teleop ${catkin_EXPORTED_TARGETS})
target_link_libraries(joy_teleop_node joy_teleop ${catkin_LIBRARIES})

install(DIRECTORY launch config
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)
