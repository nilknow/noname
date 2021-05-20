cmake_minimum_required(VERSION 3.17)
project(noname)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE
        main.cpp
        ${CMAKE_SOURCE_DIR}/glad.c
        ${CMAKE_SOURCE_DIR}/shader/src/shader.cpp
        ${CMAKE_SOURCE_DIR}/component/Fps.cpp
        stb_image.cpp
        )

add_library(console STATIC Console.cpp)
target_include_directories(console PUBLIC ${CMAKE_SOURCE_DIR})

add_executable(${PROJECT_NAME}  ${SOURCE})
#target_sources(noname PRIVATE glad.c shader.cpp)
target_include_directories(noname PRIVATE
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/shader/src
        ${CMAKE_SOURCE_DIR}/component
        ${CMAKE_SOURCE_DIR}
        )

link_directories(${CMAKE_SOURCE_DIR}/lib)
#find_package(glfw3 3.3 REQUIRED PATH ${CMAKE_SOURCE_DIR}/lib)
add_subdirectory(${CMAKE_SOURCE_DIR}/glfw)
target_link_libraries(noname GL pthread Xrandr Xi dl X11 glfw console)