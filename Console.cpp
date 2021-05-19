#include "Console.hpp"

Console::Console(std::string content) {
    this->content = content;
}

void Console::showOutput() {
    std::cout << content << std::endl;
}

void Console::setContent(std::string text) {
    this->content = text;
    showOutput();
}