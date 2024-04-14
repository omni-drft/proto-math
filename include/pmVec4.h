#ifndef PMVEC4_H
#define PMVEC4_H

#include <stdio.h>
#include <math.h>

#include "pmConstants.h"

// Proto Math structure for holding 4-component vectors and 
// perform calculations on them. At the moment only floating 
// point components supported.
struct pmVector4 {
	float components[4];
};

// A function that multiplies vector under given address
// by a scalar given as a 2nd argument.
unsigned int pmVec4Multiply(struct pmVector4*, float);

// A function that divides vector under given address
// by a scalar given as a 2nd argument.
unsigned int pmVec4Divide(struct pmVector4*, float);

// A function that calculates the dot product of two given
// vectors and returns it as float value.
float pmVec4DotProduct(const struct pmVector4*, const struct pmVector4*);

// Functions that are an alternative form of getting coordinates.
float x(const struct pmVector4*);
float y(const struct pmVector4*);
float z(const struct pmVector4*);
float w(const struct pmVector4*);

// A function that calculates vector length
float pmVec4Length(const struct pmVector4*);

// A function that normalizes vector under given address.
// WARNING!: It modifies the given vector
// Returns an error code.
unsigned int pmVec4NormalizeInPlace(struct pmVector4*);

// A function that creates copy of given vector.
// It normalizes it and returns.
// It doesn't modify the given vector.
struct pmVector4 pmVec4NormalizeCopy(struct pmVector4);

// A function that prints the vector to the console using stdio.h.
// It has two modes:
//	- pmCompact - a mode when the float values are displayed in short form
//  - pmFull - a mode when the float values are displayed in their full form
void pmVec4Print(const struct pmVector4*, enum pmVectorEnum mode);

// A function that calculates angle between two given vectors
// and returns result as a float value.
// The result depend on the mode provided by user.
// Two supported modes are:
//   - pmRadians
//	 - pmDegrees
// If the mode is set to pmRadians the result is angle in radians
// If the mode is set to pmDegrees the result is angle in degrees
float pmVec4Angle(const struct pmVector4*, const struct pmVector4*, enum pmVectorEnum mode);

// A function that checks if two given vectors are parallel to each other.
// Returns:
//	1 if they are parallel
//  0 if they are not parallel
unsigned int pmVec4IsParallel(const struct pmVector4*, const struct pmVector4*);

// A function that checks if two given vectors are perpendicular to each other.
// Returns:
//  1 if they are perpendicular
//  0 if they are not perpendicular
unsigned int pmVec4IsPerpendicular(const struct pmVector4*, const struct pmVector4*);

#endif // !PMVEC4_H
