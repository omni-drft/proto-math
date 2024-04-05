#include <iostream>
#include <pm.hpp>


int main() 
{

	int **mat = new int*[3];
	for (int i = 0; i < 3; i++)
		mat[i] = new int[3];
	mat[0][0] = 1;
	mat[0][1] = 2;
	mat[0][2] = 3;
	mat[1][0] = 4;
	mat[1][1] = 5;
	mat[1][2] = 6;
	mat[2][0] = 7;
	mat[2][1] = 8;
	mat[2][2] = 9;


	pm::Mat<int> a(3, 3, mat);

	pm::Mat<int> b{ a.transpose() };

	a.print();
	std::cout << std::endl;
	b.print();

	pm::Vec<int> v{ new int[3]{1, 2, 3}, 3 };

	pm::Mat<int> multiplied{ a * v };

	multiplied.print();

	for (int i = 0; i < 3; i++)
		delete[] mat[i];
	delete[] mat;

	

	return 0;
}