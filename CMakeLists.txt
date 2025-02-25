cmake_minimum_required(VERSION 3.31.3)
project(3d-render)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(SOURCES src/3d_structs.c src/file_obj.c src/rendering.c src/term_tweaks.c
            src/termios_init.c src/main.c)
add_executable(3d-render ${SOURCES})
target_include_directories(3d-render PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(3d-render m)
