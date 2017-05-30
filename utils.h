#include <iostream>


/**
 * Limpia el contenido de la consola.
 */
void clear_ui();

/**
 * Escribe una línea de título adornada.
 * @param title Título.
 */
void write_title(std::string title);

/**
 * Escribe una línea de título adornada.
 * @param title Título.
 * @param clean Especifica si se limpiará la consola.
 */
void write_title(std::string title, bool clean);

/**
 *
 * @param n string para hacer split
 * @return Array de string
 */
std::string *split(std::string n);