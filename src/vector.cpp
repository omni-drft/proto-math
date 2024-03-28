#include "vector.hpp"

pm::Vector::Vector() : x(0), y(0) {}

pm::Vector::Vector(int x, int y) : x(x), y(y) {}

int pm::Vector::getX() const 
{
    return x;
}

int pm::Vector::getY() const 
{
    return y;
}

int pm::Vector::setX(int x) 
{
    this->x = x;
    return 0;
}

int pm::Vector::setY(int y) 
{
    this->y = y;
    return 0;
}

int pm::Vector::print(pmEnum mode) const 
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

pm::Vector pm::Vector::operator+(const Vector& other) const
{
    pm::Vector result;
    result.setX(this->getX() + other.getX());
    result.setY(this->getY() + other.getY());
    return result;
}

pm::Vector pm::Vector::operator-(const Vector& other) const
{
    pm::Vector result;
    result.setX(this->getX() - other.getX());
    result.setY(this->getY() - other.getY());
    return result;
}

pm::Vector pm::Vector::operator*(int scalar) const
{
    pm::Vector result;
    result.setX(this->getX() * scalar);
    result.setY(this->getY() * scalar);
    return result;
}

pm::Vector pm::Vector::operator/(int scalar) const
{
    pm::Vector result;
    result.setX(this->getX() / scalar);
    result.setY(this->getY() / scalar);
    return result;
}

int pm::vector::dotProduct(const Vector& vector1, const Vector& vector2)
{
    return vector1.getX() * vector2.getX() + vector1.getY() * vector2.getY();
}

float pm::vector::magnitude(const Vector& vector)
{
    return sqrt(vector.getX() * vector.getX() + vector.getY() * vector.getY());
}

pm::Vector pm::vector::normalize(const Vector& vector)
{
    pm::Vector result{};
    float mag{ magnitude(vector) };
    result.setX(vector.getX() / mag);
    result.setY(vector.getY() / mag);
    return result;
}

float pm::vector::angle(const Vector& vector1, const Vector& vector2, pmEnum angleUnit)
{
    float angle{ acos(dotProduct(vector1, vector2) / (magnitude(vector1) * magnitude(vector2))) };

    if (angleUnit == PM_DEGREES) 
		angle = angle * 180 / PM_PI;
    
	return angle;
}
