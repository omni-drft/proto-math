#include "pmMat3.h"

unsigned int pmMat3MultiplyIP(struct pmMatrix3* destinationMatrix, float scalar)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			destinationMatrix->components[i][j] *= scalar;
	return 0;
}

struct pmMatrix3 pmMat3MultiplyCP(struct pmMatrix3* matrix, float scalar)
{
	struct pmMatrix3 result;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			result.components[i][j] = matrix->components[i][j] * scalar;
	return result;
}