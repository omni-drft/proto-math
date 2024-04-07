#ifndef VEC_H
#define VEC_H

#include <math.h>
#include <stdio.h>

enum pmVectorEnum {
	pmCompact,
	pmFull
};

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

// Functions that are an alternative form of accessing coordinates.
float x(const struct pmVector3*);
float y(const struct pmVector3*);
float z(const struct pmVector3*);


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
void pmVec3Print(struct pmVector3*, enum pmVectorEnum mode);

#endif // VEC_H!