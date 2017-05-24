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
    int total_values = 0;
    write_title("SUMA", true);
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

void ui_index() {
    char opt;
    write_title("CALCULADORA");
    cout << "Seleccione una opción a continuación.\n1) Suma\n2) Resta" << endl << endl << "> ";;
    cin >> opt;

    if (opt == '1')
        ui_module_sum();
    else {

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
