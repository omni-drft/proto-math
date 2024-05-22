#include "pmTrigonometry.h"

EXPORT_SYMBOL double pmSine(double angle)
{
    const double K = 0.6072529350088812561694;

    double x = K;
    double y = 0.0;
    double z = angle;

    int i;
    for (i = 0; i < 32; i++) {
        double x_new, y_new;

        if (z < 0) {
            x_new = x + (y * pow(2, -i));
            y_new = y - (x * pow(2, -i));
            z += atan_table[i];
        } else {
            x_new = x - (y * pow(2, -i));
            y_new = y + (x * pow(2, -i));
            z -= atan_table[i];
        }

        x = x_new;
        y = y_new;
    }

    return y;
}

EXPORT_SYMBOL double pmCosine(double angle)
{
    const double K = 0.6072529350088812561694;

    double x = K;
    double y = 0.0;
    double z = angle;

    int i;
    for (i = 0; i < 32; i++) {
        double x_new, y_new;

        if (z < 0) {
            x_new = x + (y * pow(2, -i));
            y_new = y - (x * pow(2, -i));
            z += atan_table[i];
        } else {
            x_new = x - (y * pow(2, -i));
            y_new = y + (x * pow(2, -i));
            z -= atan_table[i];
        }

        x = x_new;
        y = y_new;
    }

    return x;
}