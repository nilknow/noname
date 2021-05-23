//
// Created by pg on 2021/5/13.
//

#ifndef NONAME_SHADER_HPP
#define NONAME_SHADER_HPP


#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader{
public:
    unsigned int programId;

    Shader(const char* vertexPath,const char* fragmentPath);
    //use the program
    void use();
    void deleteProgram();

    void setBool(const std::string &name,bool value) const;
    void setInt(const std::string &name,int value) const;
    void setFloat(const std::string &name,float value) const;
};

#endif //NONAME_SHADER_HPP
