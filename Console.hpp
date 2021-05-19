//
// Created by pg on 2021/5/19.
//

#ifndef NONAME_CONSOLE_HPP
#define NONAME_CONSOLE_HPP

#include <iostream>

class Console {
private:
    std::string content;
    void showOutput();
public:

    Console(std::string content);
    void setContent(std::string text);
};

#endif //NONAME_CONSOLE_HPP
