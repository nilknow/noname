cmake_minimum_required(VERSION 3.17)
project(noname)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)
#set(CMAKE_BUILD_TYPE Release)

set(SOURCE
        main.cpp
        ${CMAKE_SOURCE_DIR}/glad.c
        ${CMAKE_SOURCE_DIR}/shader/src/shader.cpp
        ${CMAKE_SOURCE_DIR}/component/src/Fps.cpp
        ${CMAKE_SOURCE_DIR}/component/src/Console.cpp
        stb_image.cpp
        )

add_executable(${PROJECT_NAME} ${SOURCE})
#add_compile_options(-Wall -std=c++11 -O2)
#set(CMAKE_C_FLAGS -g)

include_directories(
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/shader/include
        ${CMAKE_SOURCE_DIR}/component/include
)

link_directories(${CMAKE_SOURCE_DIR}/lib)

find_package(glfw3 3.3 REQUIRED COMPONENTS filesystem system)
# check if glfw3 was found
if(glfw3_FOUND)
    message ("glfw3 found")
else()
    message (FATAL_ERROR "Cannot find glfw3")
    add_subdirectory(${CMAKE_SOURCE_DIR}/glfw)
endif()
#add_subdirectory(${CMAKE_SOURCE_DIR}/glfw)
target_link_libraries(noname GL pthread Xrandr Xi dl X11 glfw)

# Binaries
install(TARGETS noname DESTINATION bin)

# Header files
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
        DESTINATION include)

# Config
install(FILES
        ${PROJECT_SOURCE_DIR}/shader/src/vertexShader.vs
        ${PROJECT_SOURCE_DIR}/shader/src/fragmentShader.fs
        DESTINATION etc)