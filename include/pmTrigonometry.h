#ifndef PMTRIGONOMETRY_H
#define PMTRIGONOMETRY_H

#include "pmConstants.h"
#include <stdio.h>
#include <math.h>

/* A function that approximates value of sine function at given angle.
It uses CORDIC algorithm as approximation method. LUT needed for this algorithm 
is located inside the function body. */
double pmSine(double angle);

#endif /* !PMTRIGONOMETRY_H */