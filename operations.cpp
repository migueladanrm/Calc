#include "operations.h"
#include <iostream>

using namespace std;

float add(float a, float b) {
    return add(new float[2]{a, b});
}

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

float divide(float a, float b) {
    float result;

    __asm__ (
        "fld %2;"
        "fld %1;"
        "fdivp;"
        "fstp %0;" : "=m" (result) : "m" (a), "m" (b)
    );

    return result;
}

float multiply(float a, float b) {
    float result;

    __asm__ (
        "fld %1;"
        "fld %2;"
        "fmulp;"
        "fstp %0;" : "=m" (result) : "m" (a), "m" (b)
    );

    return result;
}

float subtract(float a, float b) {
    float result;

    __asm__ (
        "fld %2;"
        "fld %1;"
        "fsubp;"
        "fstp %0;" : "=m" (result) : "m" (a), "m" (b)
    );

    return result;
}

int factorial(int n) {
    int factorial = 1;

    while(n > 1) {
        int tmp = (int)multiply(factorial, n);
        factorial = tmp;
        n = n - 1;
    }

    return factorial;
}

int pow(int n, int p) {
    int pow = 1;

    for (int i = 0; i < p; ++i)
        pow = (int) multiply(pow, n);

    return pow;
}

float binToDec(float n){


}

float celsius_to_fahrenheit(float celsius) {
    return add(multiply(celsius, 9 / 5), 32);
}

float decimal_binario(float a){
    int entero;
    int decimales;
    string parada =entero+"";

    string ent;
    string deci;
    int aux;
    while(aux<=sizeof(parada)){


    }
}