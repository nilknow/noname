//
// Created by pg on 6/15/21.
//

#include "Window.h"


const int WIN_WIDTH = 800;
const int WIN_HEIGHT = 600;

void error_callback(int error, const char *description);

void framebuffer_size_callback(GLFWwindow *pWindow, int width, int height);

GLFWwindow* Window::_window;

Window::Window() {
    //glfw initiation
    glfwInit();
    glfwSetErrorCallback(error_callback);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //for debug
//    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);

    //good code style, learn it
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    //create window
    GLFWwindow *pWindow = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, "noname", nullptr, nullptr);
    if (pWindow == nullptr) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(1);
    }
    glfwMakeContextCurrent(pWindow);
    glfwSetFramebufferSizeCallback(pWindow, framebuffer_size_callback);
    Window::_window = pWindow;
}

GLFWwindow* Window::getInstance() {
    if(Window::_window== nullptr){
        Window window;
    }
    return Window::_window;
}

void error_callback(int error, const char *description) {
    fprintf(stderr, "Error: %s\n", description);
}


void framebuffer_size_callback(GLFWwindow *pWindow, int width, int height) {
    glViewport(0, 0, width, height);
}