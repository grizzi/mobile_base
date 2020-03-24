cmake_minimum_required(VERSION 2.8.3)
project(mobile_base_gazebo)
set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra")

set(PACKAGE_DEPENDENCIES
  mobile_base_description
  transmission_interface
  hardware_interface
)

find_package(catkin REQUIRED
  COMPONENTS
    ${PACKAGE_DEPENDENCIES}
)

find_package(gazebo REQUIRED)
find_package(Boost REQUIRED)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${GAZEBO_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIRS}
)
link_directories(
  ${GAZEBO_LIBRARY_DIRS}
)

catkin_package()

install(DIRECTORY gazebo launch world
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)
