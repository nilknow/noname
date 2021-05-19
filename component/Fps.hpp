#ifndef NONAME_FPS_HPP
#define NONAME_FPS_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>
class Fps{
private:
    double lastTime = glfwGetTime();
public: double refresh();
};

#endif