#include <iostream>

#include "vector2i.hpp"

int main() {
	pm::Vector2i v1(1, 2);
	pm::Vector2i v2(3, 4);
	pm::Vector2i v3 = v1 + v2;
	pm::Vector2i v4 = v1 - v2;
	pm::Vector2i v5 = v1 * 2;
	pm::Vector2i v6 = v5 / 2;
	v1.print();
	v2.print();
	v3.print();
	v4.print();
	v5.print();
	v6.print();
	return 0;
}