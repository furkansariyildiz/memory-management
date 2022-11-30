cmake_minimum_required(VERSION 3.0.2)
project(memory_management)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)


find_package(catkin REQUIRED COMPONENTS
  std_msgs
  roscpp
)



catkin_package(
 INCLUDE_DIRS include src
 LIBRARIES memory_management
 CATKIN_DEPENDS roscpp 
#  DEPENDS system_lib
)


include_directories(
  INCLUDE_DIRS include src
  ${catkin_INCLUDE_DIRS}
  ${BOOST_INCLUDE_DIRS}
)

# Declare a C++ library
add_library(memory_management src/memory_management.cpp)

add_executable(memory_management_node src/memory_management.cpp)
add_dependencies(memory_management_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(memory_management_node ${catkin_LIBRARIES})




