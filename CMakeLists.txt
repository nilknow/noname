cmake_minimum_required(VERSION 3.17)
project(noname)

set(CMAKE_CXX_STANDARD 11)

file(GLOB_RECURSE SRC_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)
set(SOURCE
        ${SRC_FILES}
        ${CMAKE_SOURCE_DIR}/src/util/GlUtil.cpp
        )
set(INCLUDE
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/include)

add_executable(${PROJECT_NAME} ${SOURCE})
target_include_directories(${PROJECT_NAME}
        PRIVATE
        ${INCLUDE})


link_directories(${CMAKE_SOURCE_DIR}/lib)
# add third party library
add_library(stb_image ${CMAKE_SOURCE_DIR}/thirdparty/stb_image/stb_image.cpp)
target_include_directories(stb_image PUBLIC ${CMAKE_SOURCE_DIR}/thirdparty)
add_library(glad ${CMAKE_SOURCE_DIR}/thirdparty/glad/glad.c)
target_include_directories(glad PUBLIC ${CMAKE_SOURCE_DIR}/thirdparty)
find_package(glfw3 3.3 REQUIRED COMPONENTS filesystem system)
# check if glfw3 was found
if(glfw3_FOUND)
    message ("glfw3 found")
else()
    message (FATAL_ERROR "Cannot find glfw3")
    add_subdirectory(${CMAKE_SOURCE_DIR}/thirdparty/glfw)
endif()

#add_subdirectory(${CMAKE_SOURCE_DIR}/glfw)
target_link_libraries(noname GL pthread Xrandr Xi dl X11 glfw glad)