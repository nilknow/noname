#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <valarray>

#include "shader.hpp"

#define WIN_WIDTH 800
#define WIN_HEIGHT 600

void framebuffer_size_callback(GLFWwindow *pWindow, int width, int height);

void keyInputCheck(GLFWwindow *pWindow);

void render();

int main() {
    //glfw initiation
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //good code style, learn it
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    //create window
    GLFWwindow *pWindow = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, "noname", NULL, NULL);
    if (pWindow == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(pWindow);
    glfwSetFramebufferSizeCallback(pWindow, framebuffer_size_callback);

    //load all openGL functions
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        glfwTerminate();
        return -1;
    }

    //shader setting
    Shader shader = Shader("./shader/src/vertexShader.vs",
                           "./shader/src/fragmentShader.fs");

    //indexed drawing
    float vertices[] = {
            // positions         // colors
            0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,   // bottom right
            -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,   // bottom left
            0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f    // top
    };

    unsigned int vertexArray;
    glGenVertexArrays(1, &vertexArray);
    //bind the vertex array object first, then set vertex buffer and config vertex attribute
    glBindVertexArray(vertexArray);

    unsigned int vertexBuffer;
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    //tell gl how interpret vertex data
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    //render loop
    while (!glfwWindowShouldClose(pWindow)) {
        keyInputCheck(pWindow);

        //rendering
        render();

        //draw
        shader.use();
        glDrawArrays(GL_TRIANGLES, 0, 3);
        //double buffer
        glfwSwapBuffers(pWindow);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &vertexArray);
    glDeleteBuffers(1, &vertexBuffer);
    shader.deleteProgram();

    glfwTerminate();
    return 0;
}

void cacheData() {

}

void render() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void framebuffer_size_callback(GLFWwindow *pWindow, int width, int height) {
    glViewport(0, 0, width, height);
}

void keyInputCheck(GLFWwindow *pWindow) {
    if (glfwGetKey(pWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(pWindow, true);
    }
}