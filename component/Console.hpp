//
// Created by pg on 2021/5/19.
//

#ifndef NONAME_CONSOLE_HPP
#define NONAME_CONSOLE_HPP

#include <iostream>
#include <ft2build.h>
#include FT_FREETYPE_H

class Console {
    std::string* _content;
    static Console* _instance;

    Console();

    Console(Console const &);

    void operator=(Console const &);

    void showOutput();

public:
    static void loadFont();

    static Console* getInstance();

    void setContent(std::string* content);
};

#endif //NONAME_CONSOLE_HPP
