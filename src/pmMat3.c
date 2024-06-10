#include "pmMat3.h"

EXPORT_SYMBOL unsigned int pmMat3Print(const struct pmMatrix3* mat, enum pmEnum mode)
{
    if (mode == pmCompact)
	{
		printf(
			"%.2f %.2f %.2f\n%.2f %.2f %.2f\n%.2f %.2f %.2f\n",
			mat->components[0][0], mat->components[0][1], mat->components[0][2],
			mat->components[1][0], mat->components[1][1], mat->components[1][2],
			mat->components[2][0], mat->components[2][1], mat->components[2][2]
		);
		return 0;
	}
	else if (mode == pmFull)
	{
		printf(
			"| %f %f %f |\n| %f %f %f |\n| %f %f %f |\n",
			mat->components[0][0], mat->components[0][1], mat->components[0][2],
			mat->components[1][0], mat->components[1][1], mat->components[1][2],
			mat->components[2][0], mat->components[2][1], mat->components[2][2]
		);
		return 0;
	}
	else 
	{
		printf("ProtoMath Error!: Wrong print mode.\n");
		printf("Returning 1\n");
		return 1;
	}

} 

EXPORT_SYMBOL unsigned int pmMat3MultiplyByScalarIP(struct pmMatrix3 *destinationMatrix, float scalar)
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

EXPORT_SYMBOL struct pmMatrix3 pmMat3MultiplyByMatCP(const struct pmMatrix3* mat1, const struct  pmMatrix3* mat2)
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

	return result;
}

EXPORT_SYMBOL float pmMat3Determinant(const struct pmMatrix3* mat)
{
    return 
		mat->components[0][0] * (mat->components[1][1] * mat->components[2][2] - mat->components[1][2] * mat->components[2][1])
	-	mat->components[0][1] * (mat->components[1][0] * mat->components[2][2] - mat->components[1][2] * mat->components[2][0])
	+	mat->components[0][2] * (mat->components[1][0] * mat->components[2][1] - mat->components[1][1] * mat->components[2][0]); 	
}

EXPORT_SYMBOL unsigned int pmMat3TransposeIP(struct pmMatrix3* mat)
{
	struct pmMatrix3 copy = *mat;

    int i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			mat->components[i][j] = copy.components[j][i];
	
	return 0;
}

EXPORT_SYMBOL struct pmMatrix3 pmMat3CofactorMatrix(const struct pmMatrix3* mat)
{
    struct pmMatrix3 cofMat;

	cofMat.components[0][0] = (mat->components[1][1] * mat->components[2][2] - mat->components[1][2] * mat->components[2][1]);
	cofMat.components[0][1] = -(mat->components[1][0] * mat->components[2][2] - mat->components[1][2] * mat->components[2][0]);
	cofMat.components[0][2] = (mat->components[1][0] * mat->components[2][1] - mat->components[1][1] * mat->components[2][0]);

	cofMat.components[1][0] = -(mat->components[0][1] * mat->components[2][2] - mat->components[0][2] * mat->components[2][1]);
	cofMat.components[1][1] = (mat->components[0][0] * mat->components[2][2] - mat->components[0][2] * mat->components[2][0]);
	cofMat.components[1][2] = -(mat->components[0][0] * mat->components[2][1] - mat->components[0][1] * mat->components[2][0]);
	
	cofMat.components[2][0] = (mat->components[0][1] * mat->components[1][2] - mat->components[0][2] * mat->components[1][1]);
	cofMat.components[2][1] = -(mat->components[0][0] * mat->components[1][2] - mat->components[0][2] * mat->components[1][0]);
	cofMat.components[2][2] = (mat->components[0][0] * mat->components[1][1] - mat->components[0][1] * mat->components[1][0]);

	return cofMat;
}

EXPORT_SYMBOL unsigned int pmMat3InvertIP(struct pmMatrix3* mat)
{
	struct pmMatrix3 cofMat = pmMat3CofactorMatrix(mat);
	pmMat3TransposeIP(&cofMat);
	*mat = pmMat3MultiplyByScalarCP(&cofMat, 1/pmMat3Determinant(mat));
    return 0;
}

EXPORT_SYMBOL unsigned int pmMat3NumOfEigen(struct pmMatrix3* mat)
{
	/* FIXME: To be implemented later... */
    return 0;
}

EXPORT_SYMBOL float pmMat3Trace(const struct pmMatrix3* mat)
{
    return mat->components[0][0] + mat->components[1][1] + mat->components[2][2];
}

EXPORT_SYMBOL unsigned int pmMat3AdjugateIP(struct pmMatrix3* mat)
{
	struct pmMatrix3 newMat = pmMat3CofactorMatrix(mat);

    pmMat3TransposeIP(&newMat);

	*mat = newMat;

	return 0;
}

float pmMatFrobNorm(const struct pmMatrix3 * mat)
{
    return sqrt(
		mat->components[0][0] * mat->components[0][0] + 
		mat->components[0][1] * mat->components[0][1] + 
		mat->components[0][2] * mat->components[0][2] +

		mat->components[1][0] * mat->components[1][0] + 
		mat->components[1][1] * mat->components[1][1] + 
		mat->components[1][2] * mat->components[1][2] +

		mat->components[2][0] * mat->components[2][0] + 
		mat->components[2][1] * mat->components[2][1] + 
		mat->components[2][2] * mat->components[2][2]
	);
}
