#include "pmVec3.h"

unsigned int pmVec3Multiply(struct pmVector3* vector, float scalar)
{
	int i;
	for (i = 0; i < 3; i++)
		vector->components[i] *= scalar;
	return 0;
}

unsigned int pmVec3Divide(struct pmVector3* vector, float scalar)
{
	if (!scalar)
	{
		printf("ProtoMath Error!: Trying to divide vector by 0!\n");
		return 1;
	}
	int i;
	for (i = 0; i < 3; i++)
		vector->components[i] /= scalar;
	return 0;
}

struct pmVector3 pmVec3CrossProduct( const struct pmVector3* sourceVec1, const struct pmVector3* sourceVec2)
{

	struct pmVector3 destinationVec;

	destinationVec.components[0] =
		sourceVec1->components[1] * sourceVec2->components[2] -
		sourceVec1->components[2] * sourceVec2->components[1];

	destinationVec.components[1] =
		sourceVec1->components[2] * sourceVec2->components[0] -
		sourceVec1->components[0] * sourceVec2->components[2];

	destinationVec.components[2] =
		sourceVec1->components[0] * sourceVec2->components[1] -
		sourceVec1->components[1] * sourceVec2->components[0];

	return destinationVec;
}

float pmVec3DotProduct(const struct pmVector3* vector1, const struct pmVector3* vector2)
{
	return vector1->components[0] * vector2->components[0] +
		vector1->components[1] * vector2->components[1] +
		vector1->components[2] * vector2->components[2];
}

float pmVec3x(const struct pmVector3* vector)
{
	return vector->components[0];
}

float pmVec3y(const struct pmVector3* vector)
{
	return vector->components[1];
}

float pmVec3z(const struct pmVector3* vector)
{
	return vector->components[2];
}

float pmVec3Length(const struct pmVector3* vector)
{
	float sum = 0;
	int i;
	for (i = 0; i < 3; i++)
		sum += vector->components[i] * vector->components[i];

	return (float)(sqrt(sum));
}

unsigned int pmVec3NormalizeInPlace(struct pmVector3* vector)
{
	float length = pmVec3Length(vector);

	if (!length)
	{
		printf("ProtoMath Error!: Trying to divide vector by 0!\n");
		return 1;
	}

	int i;
	for (i = 0; i < 3; i++)
		vector->components[i] /= length;
	return 0;

}

struct pmVector3 pmVec3NormalizeCopy(struct pmVector3 vector)
{
	float length = pmVec3Length(&vector);

	if (!length)
	{
		printf("ProtoMath Error!: Trying to divide vector by 0!\n");
		printf("Given vector returned...\n");
		return vector;
	}

	int i;
	for (i = 0; i < 3; i++)
		vector.components[i] /= length;
	return vector;
}

void pmVec3Print(const struct pmVector3* vector, enum pmVectorEnum mode)
{
	if (mode == pmCompact)
		printf("[ %.2f, %.2f, %.2f ]", vector->components[0], vector->components[1], vector->components[2]);
	else if (mode == pmFull)
		printf("[ %f, %f, %f ]", vector->components[0], vector->components[1], vector->components[2]);
}

float pmVec3Angle(const struct pmVector3* vector1, const struct pmVector3* vector2, enum pmVectorEnum mode)
{

	struct pmVector3 v1 = *vector1;
	struct pmVector3 v2 = *vector2;

	pmVec3NormalizeInPlace(&v1);
	pmVec3NormalizeInPlace(&v2);

	float angle = (float)(acos(pmVec3DotProduct(&v1, &v2) / (pmVec3Length(&v1)) * pmVec3Length(&v2)));

	if (mode == pmRadians)
		return (float)angle;
	else if (mode == pmDegrees)
		return (float)(angle * (180 / PM_PI));
	else
	{
		printf("ProtoMath Error!: Wrong print mode.\n");
		printf("Returning -1\n");
		return -1;
	}
}

struct pmVector3 pmVec3Projection(const struct pmVector3* vector1, const struct pmVector3* vector2)
{
	float scalar = pmVec3DotProduct(vector1, vector2) / (pmVec3Length(vector2) * pmVec3Length(vector2));

	struct pmVector3 newVec;

	int i;
	for (i = 0; i < 3; i++)
		newVec.components[i] = vector1->components[i] * scalar;

	return newVec;
}

unsigned int pmVec3IsParallel(const struct pmVector3* vector1, const struct pmVector3* vector2)
{
	if (pmVec3DotProduct(vector1, vector2) == pmVec3Length(vector1) * pmVec3Length(vector2))
		return 1;
	return 0;
}

unsigned int pmVec3IsPerpendicular(const struct pmVector3* vector1, const struct pmVector3* vector2)
{
	if (!pmVec3DotProduct(vector1, vector2))
		return 1;
	return 0;
}
