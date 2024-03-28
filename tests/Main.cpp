#include <iostream>

#include "vector.hpp"

int main() {
	pm::Vector v1(1, 2);
	pm::Vector v2(3, 4);
	pm::Vector v3 = v1 + v2;
	pm::Vector v4 = v1 - v2;
	pm::Vector v5 = v1 * 2;
	pm::Vector v6 = v5 / 2;
	v1.print();
	v2.print();
	v3.print();
	v4.print();
	v5.print();
	v6.print();
	return 0;
}