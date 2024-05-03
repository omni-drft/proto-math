#include "pmMat3.h"

EXPORT_SYMBOL unsigned int pmMat3MultiplyByScalarIP(struct pmMatrix3* destinationMatrix, float scalar)
{
  int i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			destinationMatrix->components[i][j] *= scalar;
	return 0;
}

EXPORT_SYMBOL struct pmMatrix3 pmMat3MultiplyByScalarCP(const struct pmMatrix3* matrix, float scalar)
{
  struct pmMatrix3 result;
	int i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			result.components[i][j] = matrix->components[i][j] * scalar;
	return result;
}

EXPORT_SYMBOL struct pmMatrix3 pmMat3Add(const struct pmMatrix3* mat1, const struct pmMatrix3* mat2)
{
	struct pmMatrix3 result;
	int i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			result.components[i][j] = mat1->components[i][j] + mat2->components[i][j];
	return result;
}

EXPORT_SYMBOL struct pmMatrix3 pmMat3Subtract(const struct pmMatrix3* mat1, const struct pmMatrix3* mat2)
{
	struct pmMatrix3 result;
	int i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			result.components[i][j] = mat1->components[i][j] - mat2->components[i][j];
	return result;
}

EXPORT_SYMBOL unsigned int pmMat3MultiplyByMatIP(struct pmMatrix3* mat1, const struct pmMatrix3* mat2)
{

	struct pmMatrix3 result;

	int i, j, k;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            result.components[i][j] = 0;
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                result.components[i][j] += mat1->components[i][k] * mat2->components[k][j];
            }
        }
    }

	*mat1 = result;
	return 0;
}

EXPORT_SYMBOL float pmMat3Determinant(struct pmMatrix3* mat)
{
    return 
		mat->components[0][0] * (mat->components[1][1] * mat->components[2][2] - mat->components[1][2] * mat->components[2][1])
	-	mat->components[0][1] * (mat->components[1][0] * mat->components[2][2] - mat->components[1][2] * mat->components[2][0])
	+	mat->components[0][2] * (mat->components[1][0] * mat->components[2][1] - mat->components[1][1] * mat->components[2][0]); 	
}
