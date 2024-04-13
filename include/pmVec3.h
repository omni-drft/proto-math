#ifndef PMVEC3_H
#define PMVEC3_H

#include <stdio.h>

#include "pmConstants.h"

#include <math.h>

// Proto Math structure for holding 3-component vectors and 
// perform calculations on them. At the moment only floating 
// point components supported.
struct pmVector3 {
	float components[3];
};

// A function that multiplies vector under given address
// by a scalar given as a 2nd argument.
unsigned int pmVec3Multiply(struct pmVector3*, float);

// A function that divides vector under given address
// by a scalar given as a 2nd argument.
unsigned int pmVec3Divide(struct pmVector3*, float);

// A function that takes two vectors as first two arguments 
// and calculates the cross product of those two vectors.
// The result is returned as struct.
struct pmVector3 pmVec3CrossProduct(const struct pmVector3*, const struct pmVector3*);

// A function that calculates the dot product of two given
// vectors and returns it as float value.
float pmVec3DotProduct(const struct pmVector3*, const struct pmVector3*);

// Functions that are an alternative form of getting coordinates.
float x(struct pmVector3*);
float y(struct pmVector3*);
float z(struct pmVector3*);


// A function that calculates magnitude (length) of given
// vector and returns it as float value.
float pmVec3Length(struct pmVector3*);

// A function that normalizes vector under given address.\
// WARNING!: It modifies the given vector
// Returns an error code.
unsigned int pmVec3NormalizeInPlace(struct pmVector3*);

// A function that creates copy of given vector.
// It normalizes it and returns.
// It doesn't modify the given vector.
struct pmVector3 pmVec3NormalizeCopy(struct pmVector3);

// A function that prints the vector to the console using stdio.h.
// It has two modes:
//	- pmCompact - a mode when the float values are displayed in short form
//  - pmFull - a mode when the float values are displayed in their full form
void pmVec3Print(const struct pmVector3*, enum pmVectorEnum mode);

// A function that calculates angle between two given vectors
// and returns result as a float value.
// The result depend on the mode provided by user.
// Two supported modes are:
//   - pmRadians
//	 - pmDegrees
// If the mode is set to pmRadians the result is angle in radians
// If the mode is set to pmDegrees the result is angle in degrees
float pmVec3Angle(const struct pmVector3*, const struct pmVector3*, enum pmVectorEnum mode);

// A function that calculates projection of first given vector onto another.
// It returns new vector as a result.
struct pmVector3 pmVec3Projection(const struct pmVector3*, const struct pmVector3*);

// A function that checks if two given vectors are parallel to each other.
// Returns:
//	1 if they are parallel
//  0 if they are not parallel
unsigned int pmVec3IsParallel(const struct pmVector3*, const struct pmVector3*);

// A function that checks if two given vectors are perpendicular to each other.
// Returns:
//  1 if they are perpendicular
//  0 if they are not perpendicular
unsigned int pmVec3IsPerpendicular(const struct pmVector3*, const struct pmVector3*);

#endif // PMVEC3_H!