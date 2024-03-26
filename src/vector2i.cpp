#include "vector2i.hpp"

pm::Vector2i::Vector2i() : x(0), y(0) {}

pm::Vector2i::Vector2i(int x, int y) : x(x), y(y) {}

int pm::Vector2i::getX() const 
{
    return x;
}

int pm::Vector2i::getY() const 
{
    return y;
}

int pm::Vector2i::setX(int x) 
{
    this->x = x;
    return 0;
}

int pm::Vector2i::setY(int y) 
{
    this->y = y;
    return 0;
}

int pm::Vector2i::print(pmEnum mode) const 
{
    switch (mode) {
        case PM_PRINT_DEFAULT:
            std::cout << "( " << x << ", " << y << " )" << std::endl;
            break;
        case PM_PRINT_SIMPLEST:
            std::cout << x << " " << y << std::endl;
            break;
        case PM_PRINT_POLAR:
            std::cout << "TODO: Implement polar print mode" << std::endl;
            break;
        default:
            std::cout << "Invalid print mode" << std::endl;
            return 1;
            break;
    }
    return 0;
}

