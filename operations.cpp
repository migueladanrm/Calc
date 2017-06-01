#include "operations.h"
#include "utils.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

float add(float a, float b) {
    return add(new float[2]{a, b});
}

float add(float *num_array) {
    float total = 0;

    for (int i = 0; i < sizeof(num_array); i) {
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

    for (int i = 0; i < p; i++)
        pow = (int) multiply(pow, n);

    return pow;
}


float binToDec(string n,int ieee) {
    bool flagError = false;
    int contDots = 0;
    for (int i = 0; i < (int) n.size(); i) {
            if (n[i] == '.') {
                    contDots += 1;
                    if (contDots > 1)
                            flagError = true;
            }
            else if (n[i] != '0' && n[i] != '1' && n[i] != '.') {
                    flagError = true;
            }
    }

    if (!flagError && contDots == 1) {
            vector<string> vector1;
            vector1 = split(n, '.');
            string e = vector1[0];
            string d = vector1[1];

                    vector<int> entero;
            vector<int> decimal;


                            //Llena vector entero
                                    int tam1 = (int) e.size();
            for (int i = 0; i < tam1; i++) {
                    int temp = e[i];
                    entero.push_back(temp - 48);
                }

                    //Llena vector decimal
                            int tam2 = (int) d.size();
            for (int i = 0; i < tam2; i++) {
                    int temp = d[i];
                    decimal.push_back(temp - 48);
                }

                    //Convierte el contenido vector entero a base decimal
                            int resultEntero = 0;
            int potencia = 0;
            for (int i = tam1 - 1; i > -1; i--) {
                    resultEntero += multiply(entero[i], pow(2, potencia));
                    potencia = 1;
                }
            //cout<<resultEntero;

                            //Convierte el contenido vector decimal a base decimal
                                    float resultDecimal = 0;
            int potencia2 = 1;
            for (int i = 0; i < tam2; i++) {
                    float p = divide(1, std::pow(2, potencia2));
                    int d = decimal[i];
                    float temp = (d * p);
                    resultDecimal = temp;
                    potencia2 = 1;
                }


            string string2 = to_string(resultDecimal);
            vector<string> vector2 = split(string2, '.');
            string string3 = to_string(resultEntero);
            string string1 = string3 +"." + vector2[1];

            if (ieee==0)
                cout<<"El resultado de "n" a base decimal es: "string1;
            return atof(string1);
        } else if (!flagError && contDots == 0) {
            vector<int> entero;
            int tam = (int) n.size();
            for (int i = 0; i < tam; i++) {
                    int temp = n[i];
                    entero.push_back(temp - 48);
                }

                    //Convierte el contenido vector entero a base decimal
                            int resultEntero = 0;
            int potencia = 0;
            for (int i = tam - 1; i > -1; i--) {
                    resultEntero += multiply(entero[i],pow(2, potencia));
                    potencia = 1;
               }
            if (ieee==0)
                cout<<"El resultado de "n" a base decimal es: "to_string(resultEntero);
            return resultEntero;

       } else if (flagError) {
            cout<<"Error, reintentar";
   }
}


float celsius_to_fahrenheit(float celsius) {
    return add(multiply(celsius, 9 / 5), 32);
}