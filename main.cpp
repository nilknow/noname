#define GLFW_INCLUDE_NONE

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <iostream>

#define WIN_WIDTH 800
#define WIN_HEIGHT 600

const char *vertexShaderSource = "#version 460 core\n"
                                 "layout (location = 0) in vec3 aPos;\n"
                                 "void main()\n"
                                 "{\n"
                                 "    gl_Position=vec4(aPos.x,aPos.y,aPos.z,1.0);\n"
                                 "}\0";
const char *fragmentShaderSource = "#version 460 core\n"
                                   "out vec4 FragColor;\n"
                                   "void main()\n"
                                   "{\n"
                                   "    FragColor=vec4(1.0f,0.5f,0.2f,1.0f);\n"
                                   "}\n";

void framebuffer_size_callback(GLFWwindow *pWindow, int width, int height);

void keyInputCheck(GLFWwindow *pWindow);

void cacheData();

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
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    int success;
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    char infoLog[512];
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    //link shader program
    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER_PROGRAM::LINK_FAILED\n" << infoLog << std::endl;
    }
    //we don't need shader which have been linked to shaderProgram object,过河拆桥:P
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    float vertices[] = {
            // first triangle
            0.5f,  0.5f, 0.0f,  // top right
            0.5f, -0.5f, 0.0f,  // bottom right
            -0.5f,  0.5f, 0.0f,  // top left
            // second triangle
            0.5f, -0.5f, 0.0f,  // bottom right
            -0.5f, -0.5f, 0.0f,  // bottom left
            -0.5f,  0.5f, 0.0f   // top left
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
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);

    //render loop
    while (!glfwWindowShouldClose(pWindow)) {
        keyInputCheck(pWindow);

        //rendering
        render();

        //draw
        glUseProgram(shaderProgram);
        glBindVertexArray(vertexArray);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        //double buffer
        glfwSwapBuffers(pWindow);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &vertexArray);
    glDeleteBuffers(1, &vertexBuffer);
    glDeleteProgram(shaderProgram);

    glfwTerminate();
    return 0;
}

void cacheData(){

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