cmake_minimum_required(VERSION 3.8)
project(tri_gen_trajectry_generator)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find required packages
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(tri_gen_msgs REQUIRED)
find_package(casadi REQUIRED)
find_package(visualization_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)




include_directories(include)

add_executable(trajectory_generator_node
  src/main.cpp
  src/trajectory_generator_node.cpp
  src/trajectory_generator.cpp
)

ament_target_dependencies(trajectory_generator_node
  rclcpp
  tri_gen_msgs
  visualization_msgs
  tf2
  tf2_geometry_msgs
)

target_link_libraries(trajectory_generator_node
  casadi::casadi
)

install(TARGETS
  trajectory_generator_node
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY
  config
  launch
  DESTINATION share/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_cmake_gtest REQUIRED)
  ament_add_gtest(test_trajectory_generator
    test/test_trajectory_generator.cpp src/trajectory_generator.cpp)
  ament_target_dependencies(test_trajectory_generator tri_gen_msgs)
  target_link_libraries(test_trajectory_generator casadi::casadi)
  find_package(ament_lint_auto REQUIRED)

  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)

  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
