#include "pmGeneral.h"

EXPORT_SYMBOL double pmPower(double base, double exponent)
{
    /* FIXME: This function will need exponential function 
    and natural logarithm function. Now i'm working on them
    so this one will be implemented soon. */
    return -1.0L;
}

EXPORT_SYMBOL double pmNatLog(double x) {
    double result = 0;
    int i;
    for (i = 0; i < 32; i++) {
        
        int a = -1;
        int j;
        for (j = 0; j < i; j++)
            a *= (-1);

        double b = x - 1;
        for (j = 0; j <= i; j++)
            b *= (x - 1);

        result += (a)/(i + 1);
    }
        
    return result;
    
        
}

EXPORT_SYMBOL double pmExp(double x) {
    int i, j;

    long double result;

    for (i = 0; i < 20; i++) {
        double adder = 1;
        for (j = 0; j < i; j++)
            adder *= x;
        result += adder / pmFactorial(i);
    }

    return result;
}

EXPORT_SYMBOL long long pmFactorial(int x)
{
    signed long long result = 1;
    int i;
    for (i = 1; i <= x; i++)
        result *= i;
    
    return result;
}
