# noname

A game inspired by minecraft developed with OpenGL. I haven't come up with the name of this game.

## build

Download and build correspond version of GLFW and glad library. Use cmake to build and run (
see `With CMake and GLFW source` in GLFW official website. `glfw` folder is the GLFW source).

If you use Clion, don't forget to set working directory to the project's root directory, in case the relative path in
this project prefix with `./build/`

## tools

* Manjaro (Linux distro)
* C++
* OpenGL(GLFW+glad)
* cmake

## documentation

## reference

* [learnopengl.com](https://learnopengl.com/)
* ![relationship between VAO,VBO and EBO](documentation/img/img.png)
* [cmake-example](https://github.com/ttroy50/cmake-examples)

## notes
* ways to debug in opengl: console, `glGetError()` and some other GUI tools
* cmake:
    0. print log: `message()`
    1. headers: `target_include_directories()`
    2. static/shared library: `add_library()` with `STATIC` or `SHARED` param
    3. install: create `make install` rule with cmake. use `install` function in cmake
    4. build type: can set compile level by build type. It can also let cmake compile it in debug mode.
    5. compile flag: `target_compile_definitions()` or `CMAKE_CXX_FLAGS`. They will not override.
    6. third party library: `find_package()`, `xxx_FOUND`, `xxx_INCLUDE_DIRS`
    7. generator: cmake can generate not only gnu make file, but also build files for other build tools.
    8. subproject