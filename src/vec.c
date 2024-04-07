#include "vec.h"

unsigned int pmVec3Multiply(struct pmVector3* vector, float scalar)
{
	// Iterating through components and multiplying them.
	for (int i = 0; i < 3; i++)
		vector->components[i] *= scalar;
	// Returning 0 if no errors occured.
	return 0;
}

unsigned int pmVec3Divide(struct pmVector3* vector, float scalar)
{
	// Check for division by zero
	if (!scalar) 
	{
		printf("ProtoMath Error!: Trying to divide vector by 0!\n");
		// Error code "1" means division by 0 error.
		return 1;
	}
	// Iterating through components and dividing them.
	for (int i = 0; i < 3; i++)
		vector->components[i] /= scalar;
	// Returning 0 if no error occured.
	return 0;
}

struct pmVector3 pmVec3CrossProduct( struct pmVector3* sourceVec1, struct pmVector3* sourceVec2)
{

	struct pmVector3 destinationVec;

	// Calculating first component of cross product.
	destinationVec.components[0] = 
		sourceVec1->components[1] * sourceVec2->components[2] - 
		sourceVec1->components[2] * sourceVec2->components[1];

	// Calculating second component of cross product.
	destinationVec.components[1] =
		sourceVec1->components[2] * sourceVec2->components[0] -
		sourceVec1->components[0] * sourceVec2->components[2];

	// Calculating third component of cross product.
	destinationVec.components[2] =
		sourceVec1->components[0] * sourceVec2->components[1] -
		sourceVec1->components[1] * sourceVec2->components[0];

	return destinationVec;
}

float x(struct pmVector3* vector)
{
	return vector->components[0];
}

float y(struct pmVector3* vector)
{
	return vector->components[1];
}

float z(struct pmVector3* vector)
{
	return vector->components[2];
}

float pmVec3Length(struct pmVector3* vector)
{
	float sum = 0;
	for (int i = 0; i < 3; i++)
		sum += vector->components[i] * vector->components[i];

	return sqrt(sum);
}

unsigned int normalizeInPlace(struct pmVector3* vector)
{
	float length = pmVec3Length(vector);

	if (!length)
	{
		printf("ProtoMath Error!: Trying to divide vector by 0!\n");
		return 1;
	}

	for (int i = 0; i < 3; i++)
		vector->components[i] /= length;
	return 0;

}

struct pmVector3 normalizeCopy(struct pmVector3 vector)
{
	float length = pmVec3Length(&vector);

	for (int i = 0; i < 3; i++)
		vector.components[i] /= length;
	return vector;
}
