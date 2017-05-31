#include "utils.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>

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

template<typename Out>
void split(const string &s, char delim, Out result) {
    stringstream ss;
    ss.str(s);
    string item;
    while (getline(ss, item, delim)) {
        *(result++) = item;
    }
}


vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, back_inserter(elems));
    return elems;
}