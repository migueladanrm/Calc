#include <iostream>
#include <vector>


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

template<typename Out>
void split(const std::string &s, char delim, Out result);

std::vector<std::string> split(const std::string &s, char delim);