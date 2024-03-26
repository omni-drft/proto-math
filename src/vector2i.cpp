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

pm::Vector2i pm::Vector2i::operator+(const Vector2i& other) const
{
    pm::Vector2i result;
    result.setX(this->getX() + other.getX());
    result.setY(this->getY() + other.getY());
    return result;
}

pm::Vector2i pm::Vector2i::operator-(const Vector2i& other) const
{
    pm::Vector2i result;
    result.setX(this->getX() - other.getX());
    result.setY(this->getY() - other.getY());
    return result;
}

pm::Vector2i pm::Vector2i::operator*(int scalar) const
{
    pm::Vector2i result;
    result.setX(this->getX() * scalar);
    result.setY(this->getY() * scalar);
    return result;
}

pm::Vector2i pm::Vector2i::operator/(int scalar) const
{
    pm::Vector2i result;
    result.setX(this->getX() / scalar);
    result.setY(this->getY() / scalar);
    return result;
}

pm::Vector2i pm::vector2i::dotProduct(const Vector2i& vector1, const Vector2i& vector2)
{
    std::cout << "TODO: Implement dot product for Vector2i" << std::endl;
    return Vector2i();
}

pm::Vector2i pm::vector2i::crossProduct(const Vector2i& vector1, const Vector2i& vector2)
{
    std::cout << "TODO: Implement cross product for Vector2i" << std::endl;
    return Vector2i();
}
