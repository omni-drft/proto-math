#ifndef PMTRIGONOMETRY_H
#define PMTRIGONOMETRY_H

#include "pmConstants.h"
#include <stdio.h>
#include <math.h>

/* A function that approximates value of sine function at given angle.
It uses CORDIC algorithm as approximation method. LUT needed for this algorithm 
is located in pmConstants.h */
double pmSine(double angle);

/* A function that approximates value of cosine function at given angle.
It uses CORDIC algorithm as approximation method. LUT needed for this algorithm 
is located in pmConstants.h */
double pmCosine(double angle);

#endif /* !PMTRIGONOMETRY_H */