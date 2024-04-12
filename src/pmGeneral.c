#include "pmGeneral.h"

long long pmFactorial(int num)
{
	long long factorial = 1;
	for (int i = 2; i <= num; i++)
		factorial *= i;
	return factorial;
}

double pmPower(double base, double exponent)
{
	return 0.;
}
