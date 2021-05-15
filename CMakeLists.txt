cmake_minimum_required(VERSION 3.17)
project(noname)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE
        ${CMAKE_SOURCE_DIR}/glad.c
        ${CMAKE_SOURCE_DIR}/shader.cpp

        ${CMAKE_SOURCE_DIR}/include/glad/glad.h
        ${CMAKE_SOURCE_DIR}/shader.hpp)

add_executable(noname main.cpp ${SOURCE})
#target_sources(noname PRIVATE glad.c shader.cpp)
link_directories(${CMAKE_SOURCE_DIR}/lib)
target_include_directories(noname PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(noname GL pthread Xrandr Xi dl X11 glfw)