#include "utils.h"
#include <iostream>

using namespace std;

void clear_ui() {
    system("clear");
}

void write_title(string title) {
    string output = "----- " + title + " ";
    while (output.length() < 60)
        output = output + "-";
    cout << output << endl;
}

void write_title(string title, bool clean) {
    if (clean)
        clear_ui();
    write_title(title);
}