#include <iostream>
#include <pm.hpp>


int main() 
{

	int **mat = new int*[3];
	for (int i = 0; i < 3; i++)
		mat[i] = new int[3];
	mat[0][0] = 2;
	mat[0][1] = 1;
	mat[0][2] = 3;
	mat[1][0] = 4;
	mat[1][1] = 0;
	mat[1][2] = -1;
	mat[2][0] = 5;
	mat[2][1] = 2;
	mat[2][2] = 6;


	pm::Mat<int> a(3, 3, mat);

	std::cout << a.det() << std::endl;

	

	return 0;
}