#include <iostream>
#include <pm.hpp>


int main() 
{
	double a[3] = {1, 2, 3};
	pm::Vec v1(a, 3);

	pm::Vec v2{ v1.getNormalized() };
	v2.print();

	double b[3] = {4, 5, 6};
	pm::Vec v3(b, 3);

	pm::Vec v4{ pm::vector::crossProduct(v1, v3) };
	v4.print();

	pm::Vec v5{ pm::vector::projection(v1, v3) };
	v5.print();

	double angle = pm::vector::angle(v1, v3, PM_DEGREES);
	std::cout << "Angle: " << angle << std::endl;

	bool ortho = pm::vector::orthogonal(v1, v3);
	std::cout << "Orthogonal: " << ortho << std::endl;

	return 0;
}