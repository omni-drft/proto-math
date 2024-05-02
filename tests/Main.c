#include <stdio.h>

#include <pm.h>


int main() 
{
	
	struct pmMatrix3 mat1 = {
		{
			{1, 2, 3},
			{4, 5, 6},
			{7, 8, 9}
		}
	};
	struct pmMatrix3 mat2 = {
		{
			{9, 8, 7},
			{6, 5, 4},
			{3, 2, 1}
		}
	};

	pmMat3MultiplyByMatIP(&mat1, &mat2);

	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			printf("%f ", mat1.components[i][j]);
		printf("\n");
	}


	return 0;

}