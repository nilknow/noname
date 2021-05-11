cmake_minimum_required(VERSION 3.17)
project(noname)

set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(${CMAKE_SOURCE_DIR}/lib)
add_executable(noname main.cpp)
target_sources(noname PRIVATE glad.c)
target_link_libraries(noname GL pthread Xrandr Xi dl X11 glfw)

#add_executable()
#add_library()
#add_subdirectory(lib/gl EXCLUDE_FROM_ALL)
