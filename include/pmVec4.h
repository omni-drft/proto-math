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

#endif // !PMVEC4_H
