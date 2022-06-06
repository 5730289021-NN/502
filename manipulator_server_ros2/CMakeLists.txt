cmake_minimum_required(VERSION 3.5)
project(manipulator_server)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(std_srvs REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(moveit_ros_planning_interface REQUIRED)

add_executable(man_serv src/man_serv.cpp)
ament_target_dependencies(man_serv rclcpp std_msgs geometry_msgs std_srvs tf2_geometry_msgs moveit_ros_planning_interface)

install(TARGETS
man_serv
  DESTINATION lib/${PROJECT_NAME})

ament_package()