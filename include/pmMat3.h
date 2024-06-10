#ifndef PMMAT3_H
#define PMMAT3_H

#include <stdio.h>
#include <math.h>

#include "pmConstants.h"

/* Proto Math structure that represents 3x3 matrix and makes the library able
to perform different matrix calculations. At the moment only floating 
point components supported. */
struct pmMatrix3 {
	float components[3][3];
};

/* A function that prints the matrix in desired format. */
unsigned int pmMat3Print(const struct pmMatrix3*, enum pmEnum);

/* A function that multiplies 3x3 matrix by a given scalar.
The matrix is passed as a pointer. Result is stored in the 
matrix that was passed as argument. */
unsigned int pmMat3MultiplyByScalarIP(struct pmMatrix3*, float);

/* A function that multiplies 3x3 matrix by a given scalar.
The matrix is passed as a pointer. The result is returned 
as a pmMatrix3 struct. */
struct pmMatrix3 pmMat3MultiplyByScalarCP(const struct pmMatrix3*, float);

/* A function that adds 2 matrices together and returns the result as 
matrix struct. */
struct pmMatrix3 pmMat3Add(const struct pmMatrix3*, const struct pmMatrix3*);

/* A function that subtracts 2nd given matrix from first given matrix and returns
the result as matrix struct. */
struct pmMatrix3 pmMat3Subtract(const struct pmMatrix3*, const struct pmMatrix3*);

/* A function that multiplies two given matrices and stores the result in the first
given matrix. WARNING: This function modifies first given matrix. */
unsigned int pmMat3MultiplyByMatIP(struct pmMatrix3*, const struct pmMatrix3*);

/* A function that multiplies two given matrices and returns the returns 
the result as a struct. This function does not modify given parameters. */
struct pmMatrix3 pmMat3MultiplyByMatCP(const struct pmMatrix3*, const struct pmMatrix3*);

/* A function that calculates determinant of given 3x3 matrix and returns 
it as floating point value. */
float pmMat3Determinant(const struct pmMatrix3*);

/* A function that transposes the given matrix. 
WARNING: This function modifies the given argument. */
unsigned int pmMat3TransposeIP(struct pmMatrix3*);

/* A function that calculates cofactor matrix of a given 3x3 matrix
and returns it as a 3x3 matrix struct. */
struct pmMatrix3 pmMat3CofactorMatrix(const struct pmMatrix3*);

/* A function that inverts given matrix. 
WARNING: This function modifies given argument. */
unsigned int pmMat3InvertIP(struct pmMatrix3*);

/* A function that returns number of eigenvalues in
given matrix */
unsigned int pmMat3NumOfEigen(struct pmMatrix3*);

/* A function that calculates tr(A), where A is the given matrix. 
Result is returned as a floating point value. */
float pmMat3Trace(const struct pmMatrix3*);

/* A function that calculates Adj(A), where A is the given matrix. Result is 
placed in the given argument. WARNING: This function modifies given matrix */
unsigned int pmMat3AdjugateIP(struct pmMatrix3*);

/* A function that cacluates Frobenius Norm of given matrix. 
Result is returned as floating point value.*/
float pmMatFrobNorm(const struct pmMatrix3*);

#endif /* !PMMAT3_H */
