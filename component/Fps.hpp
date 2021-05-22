#ifndef NONAME_FPS_HPP
#define NONAME_FPS_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <utility>

#include "Console.hpp"

class Fps{
private:
    double lastTime = glfwGetTime();
public:
    std::string refresh();
    void show(std::string* content);
};

#endif