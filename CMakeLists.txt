cmake_minimum_required(VERSION 3.17)
project(noname)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE
        ${CMAKE_SOURCE_DIR}/glad.c
        ${CMAKE_SOURCE_DIR}/shader/src/shader.cpp
        ${CMAKE_SOURCE_DIR}/component/Fps.cpp
        Console.cpp
        stb_image.cpp

        ${CMAKE_SOURCE_DIR}/include/glad/glad.h
        ${CMAKE_SOURCE_DIR}/shader/src/shader.hpp
        ${CMAKE_SOURCE_DIR}/component/Fps.hpp
        Console.hpp
        stb_image.h
        )

add_executable(noname main.cpp ${SOURCE})
#target_sources(noname PRIVATE glad.c shader.cpp)
target_include_directories(noname PRIVATE ${CMAKE_SOURCE_DIR}/include)
link_directories(${CMAKE_SOURCE_DIR}/lib)

#find_package(glfw3 3.3 REQUIRED PATH ${CMAKE_SOURCE_DIR}/lib)
add_subdirectory(${CMAKE_SOURCE_DIR}/glfw)
target_link_libraries(noname GL pthread Xrandr Xi dl X11 glfw)