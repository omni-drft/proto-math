#ifndef PMGENERAL_H
#define PMGENERAL_H

#include "pmConstants.h"

/* A function that calculates power of given number to given exponent. */
double pmPower(double, double);

/* A function that calculates natural logarithm of given x using 
Taylor series expansion. */
double pmNatLog(double);

/* A function that calculates exponential function value for given x. 
Basically it returns the e^x value with given x. */
double pmExp(double);

/* A function that calculates factorial of given x.
pmFactorial(4) = 1 * 2 * 3 * 4 = 24 */
signed long long pmFactorial(int);

#endif /* !PMGENERAL_H */