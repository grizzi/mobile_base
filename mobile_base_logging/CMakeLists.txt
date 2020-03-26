cmake_minimum_required(VERSION 2.8.3)
project(mobile_base_logging)

find_package(catkin REQUIRED)

catkin_package()

install(DIRECTORY multiplot
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)
