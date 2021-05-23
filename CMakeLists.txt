cmake_minimum_required(VERSION 3.17)
project(noname)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE
        src/main.cpp
        ${CMAKE_SOURCE_DIR}/thirdparty/glad/glad.c
        ${CMAKE_SOURCE_DIR}/src/component/shader.cpp
        ${CMAKE_SOURCE_DIR}/src/component/Fps.cpp
        thirdparty/stb_image/stb_image.cpp
        )

add_library(console SHARED ${CMAKE_SOURCE_DIR}/src/component/Console.cpp)
target_include_directories(console
        PUBLIC
        ${CMAKE_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/shader/src
        ${CMAKE_SOURCE_DIR}/component
        )

add_executable(${PROJECT_NAME} ${SOURCE})
#target_sources(noname PRIVATE glad.c shader.cpp)

link_directories(${CMAKE_SOURCE_DIR}/lib)
find_package(glfw3 3.3 REQUIRED COMPONENTS filesystem system)
# check if glfw3 was found
if(glfw3_FOUND)
    message ("glfw3 found")
else()
    message (FATAL_ERROR "Cannot find glfw3")
    add_subdirectory(${CMAKE_SOURCE_DIR}/thirdparty/glfw)
endif()
#add_subdirectory(${CMAKE_SOURCE_DIR}/glfw)
target_link_libraries(noname GL pthread Xrandr Xi dl X11 glfw console)

# Binaries
install(TARGETS noname DESTINATION bin)

# Library
# Note: may not work on windows
install(TARGETS console
        LIBRARY DESTINATION lib)

# Header files
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
        DESTINATION include)

# Config
install(FILES
        src/resources/shader/vertexShader.vs
        src/resources/shader/fragmentShader.fs
        DESTINATION etc)