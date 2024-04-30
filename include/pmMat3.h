#ifndef PMMAT3_H
#define PMMAT3_H

// Proto Math structure that represents 3x3 matrix and makes the library able
// to perform different matrix calculations. At the moment only floating 
// point components supported.
struct pmMatrix3 {
	float components[3][3];
};

// A function that multiplies 3x3 matrix by a given scalar.
// The matrix is passed as a pointer. Result is stored in the 
// matrix that was passed as argument.
unsigned int pmMat3Multiply(struct pmMatrix3*, float);


#endif // !PMMAT3_H
