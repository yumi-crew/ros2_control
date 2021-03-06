cmake_minimum_required(VERSION 3.5)
project(controller_manager)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra)
endif()

find_package(ament_cmake)
find_package(ament_cmake_core REQUIRED)
find_package(ament_index_cpp REQUIRED)
find_package(class_loader REQUIRED)
find_package(controller_interface REQUIRED)
find_package(hardware_interface REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rcpputils REQUIRED)

add_library(controller_manager SHARED src/controller_manager.cpp)
target_include_directories(controller_manager PRIVATE include)
ament_target_dependencies(controller_manager
  "ament_index_cpp"
  "class_loader"
  "controller_interface"
  "hardware_interface"
  "rclcpp"
  "rcpputils"
)
# Causes the visibility macros to use dllexport rather than dllimport,
# which is appropriate when building the dll but not consuming it.
target_compile_definitions(controller_manager PRIVATE "CONTROLLER_MANAGER_BUILDING_DLL")

install(TARGETS controller_manager
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)
install(DIRECTORY include/
  DESTINATION include
)
install(DIRECTORY cmake/
  DESTINATION share/${PROJECT_NAME}/cmake
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()

  ament_index_get_prefix_path(ament_index_build_path SKIP_AMENT_PREFIX_PATH)
  # Get the first item (it will be the build space version of the build path).
  list(GET ament_index_build_path 0 ament_index_build_path)
  if(WIN32)
    # On Windows prevent CMake errors and prevent it being evaluated as a list.
    string(REPLACE "\\" "/" ament_index_build_path "${ament_index_build_path}")
  endif()

  add_library(test_controller SHARED test/test_controller/test_controller.cpp)
  target_include_directories(test_controller PRIVATE include)
  target_link_libraries(test_controller controller_manager)
  target_compile_definitions(test_controller PRIVATE "CONTROLLER_MANAGER_BUILDING_DLL")

  include(cmake/controller_manager_register_controller.cmake)
  controller_manager_register_controller(
    test_controller "test_controller::TestController"
    SKIP_INSTALL)

  ament_add_gtest(
    test_controller_manager
    test/test_controller_manager.cpp
  )
  target_include_directories(test_controller_manager PRIVATE include)
  target_link_libraries(test_controller_manager controller_manager test_controller)
  ament_target_dependencies(
    test_controller_manager
    test_robot_hardware
  )

  ament_add_gtest(
    test_load_controller
    test/test_load_controller.cpp
    APPEND_ENV AMENT_PREFIX_PATH=${ament_index_build_path}_$<CONFIG>
  )
  target_include_directories(test_load_controller PRIVATE include)
  target_link_libraries(test_load_controller controller_manager)
  ament_target_dependencies(
    test_load_controller
    test_robot_hardware
  )
endif()

ament_export_libraries(
  controller_manager
)
ament_export_include_directories(
  include
)
ament_export_dependencies(
  class_loader
)
ament_package(
  CONFIG_EXTRAS cmake/controller_manager_register_controller.cmake
)
