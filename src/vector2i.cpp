#include "vector2i.hpp"

pm::Vector2i::Vector2i() : x(0), y(0) {}

pm::Vector2i::Vector2i(int x, int y) : x(x), y(y) {}

int pm::Vector2i::getX() const {
    return x;
}

int pm::Vector2i::getY() const {
    return y;
}

void pm::Vector2i::setX(int x) {
    this->x = x;
}

void pm::Vector2i::setY(int y) {
    this->y = y;
}

void pm::Vector2i::print() const {
    std::cout << "(" << x << ", " << y << ")" << std::endl;
}

