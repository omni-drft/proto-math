#include "pmVec4.h"

unsigned int pmVec4Multiply(struct pmVector4* v, float scalar)
{
	// Iterating through components and multiplying them.
	for (int i = 0; i < 4; i++)
		v->components[i] *= scalar;
	// Returning 0 if no errors occured.
	return 0;
}

unsigned int pmVec4Divide(struct pmVector4* v, float scalar)
{
	// Check for division by zero
	if (!scalar)
	{
		printf("ProtoMath Error!: Trying to divide vector by 0!\n");
		// Error code "1" means division by 0 error.
		return 1;
	}
	// Iterating through components and dividing them.
	for (int i = 0; i < 4; i++)
		v->components[i] /= scalar;
	// Returning 0 if no error occured.
	return 0;
}

float pmVec4DotProduct(const struct pmVector4* v1, const struct pmVector4* v2)
{
	return v1->components[0] * v2->components[0] +
		v1->components[1] * v2->components[1] +
		v1->components[2] * v2->components[2] +
		v1->components[3] * v2->components[3];
}

float x(const struct pmVector4* v)
{
	return v->components[0];
}

float y(const struct pmVector4* v)
{
	return v->components[1];
}

float z(const struct pmVector4* v)
{
	return v->components[2];
}

float w(const struct pmVector4* v)
{
	return v->components[3];
}

float pmVec4Length(const struct pmVector4* v)
{
	float sum = 0;
	// add all squared components to the sum
	for (int i = 0; i < 4; i++)
		sum += v->components[i] * v->components[i];

	// return square root of sum
	return sqrt(sum);
}

unsigned int pmVec4NormalizeInPlace(struct pmVector4* v)
{
	float length = pmVec4Length(v);

	if (!length)
	{
		printf("ProtoMath Error!: Trying to divide vector by 0!\n");
		return 1;
	}

	for (int i = 0; i < 4; i++)
		v->components[i] /= length;
	return 0;
}

struct pmVector4 pmVec4NormalizeCopy(struct pmVector4 v)
{
	float length = pmVec4Length(&v);
	if (!length)
	{
		printf("ProtoMath Error!: Trying to divide vector by 0!\n");
		return;
	}

	for (int i = 0; i < 4; i++)
		v.components[i] /= length;
	return v;
}

void pmVec4Print(const struct pmVector4* v, enum pmVectorEnum mode)
{
	// if the mode is set to pmCompact
	if (mode == pmCompact)
		printf("[ %.2f, %.2f, %.2f, %.2f ]", v->components[0], v->components[1], v->components[2], v->components[3]);
	// if the mode is set to pmFull
	else if (mode == pmFull)
		printf("[ %f, %f, %f, %f ]", v->components[0], v->components[1], v->components[2], v->components[3]);
}

float pmVec4Angle(const struct pmVector4* v1, const struct pmVector4* v2, enum pmVectorEnum mode)
{
	float angle = acos(pmVec4DotProduct(v1, v2) / (pmVec4Length(v1) * pmVec4Length(v1)));
	if (mode == pmRadians)
		return angle;
	else if (mode == pmDegrees)
		return angle * (180.0 / PM_PI);
	else
	{
		printf("ProtoMath Error!: Wrong print mode.\n");
		return;
	}
}

unsigned int pmVec4IsParallel(const struct pmVector4* v1, const struct pmVector4* v2)
{
	if (pmVec4DotProduct(v1, v2) == pmVec4Length(v1) * pmVec4Length(v2))
		return 1;
	return 0;
}

unsigned int pmVec4IsPerpendicular(const struct pmVector4* v1, const struct pmVector4* v2)
{
	if (!pmVec4DotProduct(v1, v2))
		return 1;
	return 0;
}
