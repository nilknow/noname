#include "Fps.hpp"

std::string Fps::refresh() {
    double last = this->lastTime;
    double now = glfwGetTime();
    this->lastTime=now;
    return std::to_string(1.0/(now-last));
}

void Fps::show(std::string* content) {
    refresh();
    Console* console = Console::getInstance();
    console->setContent(content);
}
