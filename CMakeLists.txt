cmake_minimum_required(VERSION 3.17)
project(noname)

set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_BUILD_TYPE Debug)
#set(CMAKE_BUILD_TYPE Release)

set(SOURCE
        src/main.cpp
        src/shader/src/shader.cpp
        src/component/src/Fps.cpp
        src/component/src/Console.cpp
        # dependency
        dep/glad/glad.c
        dep/stb_image/stb_image.cpp
        src/component/src/window.cpp)

add_executable(${PROJECT_NAME} ${SOURCE})
#add_compile_options(-Wall -std=c++11 -O2)
#set(CMAKE_C_FLAGS -g)

include_directories(
        dep/stb_image
        src/shader/include
        src/component/include
)

link_directories(${CMAKE_SOURCE_DIR}/lib)

find_package(glfw3 3.3 REQUIRED COMPONENTS filesystem system)
# check if glfw3 was found
if(glfw3_FOUND)
    message ("glfw3 found")
else()
    message (FATAL_ERROR "Cannot find glfw3")
    add_subdirectory(${CMAKE_SOURCE_DIR}/dep/glfw)
endif()
#add_subdirectory(${CMAKE_SOURCE_DIR}/glfw)
target_link_libraries(noname GL pthread Xrandr Xi dl X11 glfw)