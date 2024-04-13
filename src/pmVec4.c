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
