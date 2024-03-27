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

int pm::vector2i::dotProduct(const Vector2i& vector1, const Vector2i& vector2)
{
    return vector1.getX() * vector2.getX() + vector1.getY() * vector2.getY();
}

float pm::vector2i::magnitude(const Vector2i& vector)
{
    return sqrt(vector.getX() * vector.getX() + vector.getY() * vector.getY());
}

pm::Vector2i pm::vector2i::normalize(const Vector2i& vector)
{
    pm::Vector2i result{};
    float mag{ magnitude(vector) };
    result.setX(vector.getX() / mag);
    result.setY(vector.getY() / mag);
    return result;
}

float pm::vector2i::angle(const Vector2i& vector1, const Vector2i& vector2, pmEnum angleUnit)
{
    float angle{ acos(dotProduct(vector1, vector2) / (magnitude(vector1) * magnitude(vector2))) };

    if (angleUnit == PM_DEGREES) 
		angle = angle * 180 / PM_PI;
    
	return angle;
}
