cmake_minimum_required(VERSION 3.5)
project(panda_description)

find_package(ament_cmake REQUIRED)
find_package(ament_cmake REQUIRED)
find_package(urdf REQUIRED)
find_package(xacro REQUIRED)

install(DIRECTORY
  launch robots meshes rviz
  DESTINATION share/${PROJECT_NAME}/
)

ament_package()
