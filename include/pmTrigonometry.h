#ifndef PMTRIGONOMETRY_H
#define PMTRIGONOMETRY_H

#include "pmGeneral.h"
#include "pmConstants.h"

// A function that calculates the sin(x) value.
// It uses Taylor-Series expansion for aproximating the correct value.
// First parameter is the x, and the second parameter
// is the amount of steps that the algorithm takes to aproximate the final value.
double pmSin(double, int);

// A function that calculates the arccos(x) value.
// It uses Taylor-Series expansion for aproximating the correct value.
// First parameter is the x, and the second parameter
// is the amount of steps that the algorithm takes to aproximate the final value.
double pmArcCos(double, int);

#endif // !PMTRIGONOMETRY_H

