#include "utils.h"
#include <iostream>
#include <cstring>
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

std::string *split(char str[100]){
    string result[200] ;
    char* point;
    point = strtok(str,".");

    while(point != NULL){
        result->append(point);
        point= strtok(NULL,".");
    }
    return result;
}