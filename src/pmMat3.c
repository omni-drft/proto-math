#include "pmMat3.h"

unsigned int pmMat3Multiply(struct pmMatrix3* destinationMatrix, float scalar)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			destinationMatrix->components[i][j] *= scalar;
}
