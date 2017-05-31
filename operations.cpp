#include "operations.h"
#include "utils.h"
#include <iostream>
#include <vector>
#include <cmath>

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



string decimal_binario(string numero){

    bool banderaError=false;
    int contPuntos=0;
    for(int i=0;i<(int)numero.size();i++){
        if(numero[i]=='.'){
            contPuntos++;
            if(contPuntos>1){
                banderaError=true;
            }
        }else if(numero[i]>=48 && numero[i]<=57 ){
            banderaError=false;

        }else{
            banderaError=true;

        }

    }

    if(!banderaError && contPuntos==1) {
        vector<string> vector1 = split(numero, '.');
        string resultFinal;// string valor entero mas decimal en binario

        string binDeci;//string donde se almacena la parte decimal
        string binEntero;//string donde se almacena la parte entera
        int ent = stoi(vector1[0]);//vector de la parte entera
        int deci = stoi(vector1[1]);


        //pasar parte decimal a binario
        while (ent > 0) {
            float result;//resultado en flotante
            int resultado;
            int dos = 2;
            //resultado=ent/2;
            __asm__ (
            "fld %2;"
                    "fld %1;"
                    "fdivp;"
                    "fstp %0;" : "=m" (result) : "m" (ent), "m" (dos)
            );
            string num = to_string(result);//pasar de float a string
            vector<string> resultEntero = split(num, '.');
            string numeroString = resultEntero[0];
            resultado = atoi(numeroString.c_str());//pasar de string a integer
            if (ent % 2 == 0) {
                binEntero += "0";//si el resultado es par concatenar 0 al resultado en binario de la parte entera
            } else {
                binEntero += "1";//si el resultado es impar concatenar 1 al resultado en binario de la parte entera
            }
            ent = resultado;
        }
        for (int i = (int) binEntero.size() - 1;
             i > -1; i--) {//se recorre el string de residuos de atras hacia adelante para obtener el numero en binario
            resultFinal += binEntero[i];
        }

        //pasar parte decimal a binario

        string numDecimal = to_string(deci);//se utiliza para obtener el len del string

        int exponent = pow(10, (int) numDecimal.size());
        int uno = 1;
        float expo;
        __asm__ (
        "fld %2;"
                "fld %1;"
                "fdivp;"
                "fstp %0;" : "=m" (expo) : "m" (uno), "m" (exponent)
        );

        while (deci >= 1) {
            float decim = multiply((float) deci,
                                   expo);//pasar de un entero a un float ejemplo 5 a 0.5 se utiliza el metodo en ensamblador


            //guardar los numeros ya pasados a binario
            string flotante = to_string(decim * 2);//paso de flotante a string
            vector<string> resultDecimal = split(flotante, '.');//optenemos la parte entera del float
            binDeci += resultDecimal[0];//se le concatena la parte decimal al string binDeci que seria la parte decimal del resultado final
            deci = atoi(
                    resultDecimal[1].c_str());//paso la parte decimal de la variable resultDecimal a int y se lo asigno a deci para continuar con el ciclo
        }

        resultFinal += "." + binDeci;

        return resultFinal;
    }else if(!banderaError && contPuntos==0){
        vector<string> vector1 = split(numero, '.');
        string resultFinal;// string valor entero mas decimal en binario

        string binDeci;//string donde se almacena la parte decimal
        string binEntero;//string donde se almacena la parte entera
        int ent = stoi(vector1[0]);//vector de la parte entera



        //pasar parte decimal a binario
        while (ent > 0) {
            float result;//resultado en flotante
            int resultado;
            int dos = 2;
            //resultado=ent/2;
            __asm__ (
            "fld %2;"
                    "fld %1;"
                    "fdivp;"
                    "fstp %0;" : "=m" (result) : "m" (ent), "m" (dos)
            );
            string num = to_string(result);//pasar de float a string
            vector<string> resultEntero = split(num, '.');
            string numeroString = resultEntero[0];
            resultado = atoi(numeroString.c_str());//pasar de string a integer
            if (ent % 2 == 0) {
                binEntero += "0";//si el resultado es par concatenar 0 al resultado en binario de la parte entera
            } else {
                binEntero += "1";//si el resultado es impar concatenar 1 al resultado en binario de la parte entera
            }
            ent = resultado;
        }
        for (int i = (int) binEntero.size() - 1;
             i > -1; i--) {//se recorre el string de residuos de atras hacia adelante para obtener el numero en binario
            resultFinal += binEntero[i];
        }
        return resultFinal;

    }else if(banderaError){
        return "Error, reintentar";

    }
}