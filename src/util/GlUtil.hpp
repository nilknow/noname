//
// Created by pg on 2021/5/23.
//

#ifndef NONAME_GLUTIL_HPP
#define NONAME_GLUTIL_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace GlUtil{
    void init();
    void setErrorCallback();
    void glCheckError();
}

#endif //NONAME_GLUTIL_HPP
