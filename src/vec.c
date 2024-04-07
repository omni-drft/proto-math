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

struct pmVector3 pmVec3CrossProduct( const struct pmVector3* sourceVec1, const struct pmVector3* sourceVec2)
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

float pmVec3DotProduct(const struct pmVector3* vector1, const struct pmVector3* vector2)
{
	return vector1->components[0] * vector2->components[0] + 
		vector1->components[1] * vector2->components[1] + 
		vector1->components[2] * vector2->components[2];
}

float x(const struct pmVector3* vector)
{
	// get first component
	return vector->components[0];
}

float y(const struct pmVector3* vector)
{
	// get middle component
	return vector->components[1];
}

float z(const struct pmVector3* vector)
{
	// get last component
	return vector->components[2];
}

float pmVec3Length(struct pmVector3* vector)
{
	float sum = 0;
	// add all squared components to the sum
	for (int i = 0; i < 3; i++)
		sum += vector->components[i] * vector->components[i];

	// return square root of sum
	return sqrt(sum);
}

unsigned int pmVec3NormalizeInPlace(struct pmVector3* vector)
{
	// get length of the given vector
	float length = pmVec3Length(vector); 

	// if length is 0 then return NULL and print 
	// the error about trying to divide by 0 
	if (!length)
	{
		printf("ProtoMath Error!: Trying to divide vector by 0!\n");
		return 1;
	}

	// divide every component by vector length
	for (int i = 0; i < 3; i++)
		vector->components[i] /= length;
	return 0;

}

struct pmVector3 pmVec3NormalizeCopy(struct pmVector3 vector)
{
	// get length of the given vector
	float length = pmVec3Length(&vector);

	// if length is 0 then return NULL and print 
	// the error about trying to divide by 0
	if (!length)
	{
		printf("ProtoMath Error!: Trying to divide vector by 0!\n");
		return;
	}

	// divide every component by the length of vector
	for (int i = 0; i < 3; i++)
		vector.components[i] /= length;
	return vector;
}

void pmVec3Print(struct pmVector3* vector, enum pmVectorEnum mode)
{
	// if the mode is set to pmCompact
	if (!mode)
		printf("[ %.2f, %.2f, %.2f ]", vector->components[0], vector->components[1], vector->components[2]);
	// if the mode is set to pmFull
	else 
		printf("[ %f, %f, %f ]", vector->components[0], vector->components[1], vector->components[2]);
}
