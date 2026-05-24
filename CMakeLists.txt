cmake_minimum_required(VERSION 3.31.3)
project(3d-render)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_executable(
  ${PROJECT_NAME}
  src/main.cpp
  src/terminal.cpp
  src/vector2.cpp
  src/vector3.cpp
  src/vector4.cpp
  src/quaternion.cpp
  src/matrix.cpp
  src/math.cpp
  src/buffer.cpp
  src/object.cpp
  src/camera.cpp)
add_compile_options(${PROJECT_NAME} -fsanitize=address)
add_link_options(${PROJECT_NAME} -fsanitize=address)
include_directories(${PROJECT_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} m)
