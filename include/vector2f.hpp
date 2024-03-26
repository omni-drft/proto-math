#ifndef VECTOR2F_HPP
#define VECTOR2F_HPP

#include <iostream>

#include "Enum.hpp"

namespace pm
{
	/// <summary>
	/// Vector2i is a class that represents a 2D vector with single precision floating point components.
	/// It provides essential features for 2D vector manipulation.
	/// </summary>
	class Vector2f
	{
		public:
			Vector2f();
			Vector2f(float x, float y);

			float getX() const;
			float getY() const;

			int setX(float x);
			int setY(float y);

			int print(pmEnum mode = PM_PRINT_DEFAULT) const;
		
		private:
			float x;
			float y;
	};
}

#endif // VECTOR2F_HPP