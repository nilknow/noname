#include "Fps.hpp"

double Fps::refresh() {
    double last = this->lastTime;
    double now = glfwGetTime();
    this->lastTime=now;
    return 1000.0/(now-last);
}