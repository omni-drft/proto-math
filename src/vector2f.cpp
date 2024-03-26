#include "vector2f.hpp"

pm::Vector2f::Vector2f()
	: x(0.0f), y(0.0f) {}

pm::Vector2f::Vector2f(float x, float y)
	: x(x), y(y) {}

float pm::Vector2f::getX() const
{
	return 0.0f;
}

float pm::Vector2f::getY() const
{
	return 0.0f;
}

int pm::Vector2f::setX(float x)
{
	this->x = x;
	return 0;
}

int pm::Vector2f::setY(float y)
{
	this->y = y;
	return 0;
}

int pm::Vector2f::print(pmEnum mode) const
{
	switch (mode) 
	{
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
	}
	return 0;
}
