#ifndef VEC_H
#define VEC_H

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
struct pmVector3 pmVec3CrossProduct(struct pmVector3*, struct pmVector3*);

// Functions that are an alternative form of accessing coordinates.
float x(struct pmVector3*);
float y(struct pmVector3*);
float z(struct pmVector3*);

float pmVec3Length(struct pmVector3*);

// A function that normalizes vector under given address.\
// WARNING!: It modifies the given vector
// Returns an error code.
unsigned int pmVec3NormalizeInPlace(struct pmVector3*);

// A function that creates copy of given vector.
// It normalizes it and returns.
// It doesn't modify the given vector.
struct pmVector3 pmVec3NormalizeCopy(struct pmVector3);



#endif // VEC_H!