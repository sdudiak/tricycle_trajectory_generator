cmake_minimum_required(VERSION 3.8)
project(tri_gen_msgs)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()


find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(builtin_interfaces REQUIRED)


rosidl_generate_interfaces(${PROJECT_NAME}
## Messages
  "msg/State.msg"
  "msg/Control.msg"
  "msg/Trajectory.msg"
## Services
  "srv/GenerateTrajectory.srv"
  DEPENDENCIES builtin_interfaces
 )

ament_package()
