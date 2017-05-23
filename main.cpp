/**
 * Tecnológico de Costa Rica
 * Ingeniería en Computación, San Carlos
 * Arquitectura de Computadores, I Semestre - 2017
 * III Proyecto programado
 * Integrantes:
 *  - Luis Carlos González
 *  - Miguel Rivas Méndez
 *  - Jafet Suárez Jiménez
 */

#include <iostream>
#include "utils.h"

using namespace std;

void ui_module_sum() {
    write_title("SUMA", true);
}

void ui_index() {
    char opt;
    write_title("CALCULADORA");
    cout << "Seleccione una opción a continuación.\n1) Suma\n2) Resta" << endl;
    cout << endl << "> ";
    cin >> opt;

    if (opt == '1')
        ui_module_sum();
}

/**
 * Punto de entrada del programa.
 * @return Código de resultado.
 */
int main() {
    ui_index();

    return 0;
}