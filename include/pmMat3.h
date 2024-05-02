#ifndef PMMAT3_H
#define PMMAT3_H

#include "pmConstants.h"

/* Proto Math structure that represents 3x3 matrix and makes the library able
to perform different matrix calculations. At the moment only floating 
point components supported. */
struct pmMatrix3 {
	float components[3][3];
};

/* A function that multiplies 3x3 matrix by a given scalar.
The matrix is passed as a pointer. Result is stored in the 
matrix that was passed as argument. */
unsigned int pmMat3MultiplyIP(struct pmMatrix3*, float);

/* A function that multiplies 3x3 matrix by a given scalar.
The matrix is passed as a pointer. The result is returned 
as a pmMatrix3 struct. */
struct pmMatrix3 pmMat3MultiplyCP(const struct pmMatrix3*, float);

/* A function that adds 2 matrices together and returns the result as 
matrix struct. */
struct pmMatrix3 pmMat3Add(const struct pmMatrix3*, const struct pmMatrix3*);

/* A function that subtracts 2nd given matrix from first given matrix and returns
the result as matrix struct. */
struct pmMatrix3 pmMat3Subtract(const struct pmMatrix3*, const struct pmMatrix3*);

#endif /* !PMMAT3_H */
