/**
 * Tecnológico de Costa Rica
 * Ingeniería en Computación, San Carlos
 * Arquitectura de Computadores
 * I Semestre - 2017
 * III Proyecto programado
 * Integrantes:
 *  - Luis Carlos González
 *  - Miguel Rivas Méndez
 *  - Jafet Suárez Jiménez
 */

#include <iostream>
#include "utils.h"
#include "operations.h"

using namespace std;



//Firmas de métodos
void ui_index();


void ui_module_sum() {
    write_title("SUMA", true);
    int total_values = 0;
    cout << "Introdúzca la cantidad de números a sumar: ";
    cin >> total_values;

    float nums[total_values];

    for (int i = 0; i < total_values; ++i) {
        cout << "Introdúca un valor (" << i + 1 << "/" << total_values << "): ";
        cin >> nums[i];
    }

    float total = add(nums);

    cout << "La suma de los valores es: " << total << endl;
}

void ui_module_subtract() {
    write_title("RESTA", true);

    float a;
    float b;

    cout << "Introdúzca el primer número: ";
    cin >> a;
    cout << endl << "Introdúzca el valor que desea restar al primer número: ";
    cin >> b;

    cout << "El resultado de la operación " << a << " — " << b <<" es: " << subtract(a, b);
}

void ui_module_multiply() {
    write_title("MULTIPLICACIÓN", true);

    float a;
    float b;

    cout << "Introdúzca el primer valor: ";
    cin >> a;

    cout << "Introdúzca el segundo valor: ";
    cin >> b;

    cout << "El resultado de la multiplicación " << a << " * " << b << " es: " << multiply(a, b) << endl;
}

void ui_module_divide() {
    write_title("DIVISIÓN", true);

    float a;
    float b;

    cout << "Introdúzca el primer número: ";
    cin >> a;

    cout << "Introdúzca el segundo número: ";
    cin >> b;

    cout << "El resultado de la operación " << a << " / " << b << " es: " << divide(a, b) << endl;
}

void ui_module_factorial() {
    write_title("FACTORIAL", true);

    float n;

    cout << "Introdúzca un número: ";
    cin >> n;

    cout << "El resultado de !" << n << " es: " << factorial((int)n) << endl;

}

void ui_module_pow() {
    write_title("POTENCIA", true);

    float b;
    float p;

    cout << "Introdúzca la base: ";
    cin >> b;

    cout << "Introdúzca el exponente: ";
    cin >> p;

    cout << "El resultado de " << b << "^" << p << " es: " << pow(b, p) << endl;
}

void ui_index() {
    char opt;
    write_title("CALCULADORA", true);
    cout
            << "Seleccione una opción a continuación.\n1) Suma\n2) Resta\n3) Multiplicación\n4) División\n5) Factorial\n6) Potencia"
            << "\ns) Salir"
            << endl << endl << "> ";
    cin >> opt;

    if (opt == '1')
        ui_module_sum();
    else if (opt == '2')
        ui_module_subtract();
    else if (opt == '3')
        ui_module_multiply();
    else if (opt == '4')
        ui_module_divide();
    else if (opt == '5')
        ui_module_factorial();
    else if (opt == '6')
        ui_module_pow();
    else if (opt == 's') {
        cout << "\nEl programa ha finalizado." << endl;
        return;
    } else {
        clear_ui();
        cout << "\nHa ingresado una opción incorrecta. Inténtelo de nuevo.\n\n";
        ui_index();
    }
}

/**
 * Punto de entrada del programa.
 * @return Código de resultado.
 */
int main() {
    ui_index();

    return 0;
}

