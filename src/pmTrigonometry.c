#include "pmTrigonometry.h"

EXPORT_SYMBOL double pmSine(double angle)
{
    const double K = 0.6072529350088812561694;

    const double atan_table[16] = {
        0.7853981633974483,
        0.4636476090008061,
        0.24497866312686414,
        0.12435499454676144,
        0.06241880999595735,
        0.031239833430268277,
        0.015623728620476831,
        0.007812341060101111, 
        0.0039062301319669718, 
        0.0019531225164788188, 
        0.0009765621895593195, 
        0.0004882812111948983,
        0.00024414062014936177,
        0.00012207031189367021,
        0.00006103515617420877,
        0.000030517578115526096
    };

    double x = K;
    double y = 0.0;
    double z = angle;

    int i;
    for (i = 0; i < 16; i++) {
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