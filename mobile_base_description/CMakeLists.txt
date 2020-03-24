cmake_minimum_required(VERSION 2.8.3)
project(mobile_base_description)

set(PACKAGE_DEPENDENCIES xacro)

find_package(catkin REQUIRED COMPONENTS ${PACKAGE_DEPENDENCIES})

catkin_package()

install(DIRECTORY bin launch rviz urdf resources
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)
