#include "pmMat3.h"

unsigned int pmMat3MultiplyIP(struct pmMatrix3* destinationMatrix, float scalar)
{
	// for each component multiply it by a given scalar
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			destinationMatrix->components[i][j] *= scalar;
	// return no error
	return 0;
}

struct pmMatrix3 pmMat3MultiplyCP(const struct pmMatrix3* matrix, float scalar)
{
	// create result matrix
	struct pmMatrix3 result;
	// store each multiplied component in the result
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			result.components[i][j] = matrix->components[i][j] * scalar;
	// return the result
	return result;
}

struct pmMatrix3 pmMat3Add(const struct pmMatrix3* mat1, const struct pmMatrix3* mat2)
{
	// create result matrix
	struct pmMatrix3 result;
	// store each added component in the result
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			result.components[i][j] = mat1->components[i][j] + mat2->components[i][j];
	// return the result
	return result;
}

struct pmMatrix3 pmMat3Subtract(const struct pmMatrix3* mat1, const struct pmMatrix3* mat2)
{
	// create result matrix
	struct pmMatrix3 result;
	// store each subtracted component in the result
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			result.components[i][j] = mat1->components[i][j] - mat2->components[i][j];
	// return the result
	return result;
}
