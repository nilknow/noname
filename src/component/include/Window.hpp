//
// Created by pg on 6/15/21.
//

#ifndef NONAME_WINDOW_HPP
#define NONAME_WINDOW_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>


class Window{
public:
    static GLFWwindow* getInstance();
private:
    static GLFWwindow* _window;

    Window();
    Window(Window const&);
    void operator=(Window const&);
};

#endif //NONAME_WINDOW_HPP
