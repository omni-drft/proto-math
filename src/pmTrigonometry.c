#include "pmTrigonometry.h"

#include <math.h>

double pmSin(double angle, int steps)
{
	double sine = 0;

	for (int i = 0; i < steps; i++)
		sine += (pow(-1, i) * pow(angle, 2 * i + 1)) / (tgamma(2 * i + 2));

	return sine;
}

double pmArcCos(double x, int steps)
{
	double arccos = PM_PI / 2;
	double power = x;
	double factorial = 1;
	for (int i = 0; i < steps; i++)
	{
		factorial *= (2 * i) * (2 * i - 1);
		power *= x * x;
		double term = pow(-1, i) * (power / factorial) / (2 * i + 1);
		arccos += term;
	}

	return arccos;
}
