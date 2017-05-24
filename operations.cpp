#include "operations.h"
#include <iostream>

using namespace std;

float add(float *num_array) {
    float total = 0;

    for (int i = 0; i < sizeof(num_array); ++i) {
        float tmp = total;

        __asm__(
        "fld %1;"
                "fld %2;"
                "faddp;"
                "fstp %0;" : "=m" (tmp) : "m" (total), "m" (num_array[i])
        );

        total = tmp;
    }

    return total;
}