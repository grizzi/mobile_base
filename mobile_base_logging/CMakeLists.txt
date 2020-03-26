cmake_minimum_required(VERSION 2.8.3)
project(mobile_base_logging)
set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra")

catkin_package()

install(DIRECTORY multiplot
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)
