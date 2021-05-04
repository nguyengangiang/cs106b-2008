#include "vector.h"
#include <iostream>
#include <fstream>
#include "simpio.h"
#include "strlib.h"
#include "stringutils.h"

using namespace std;

void Histogram(ifstream& input) {
    Vector<int> hist(10, 0);
    int grade;

    while (true) {
        if (input.eof()) {break;}
        input >> grade;
        hist.set(grade/10, hist.get(grade/10) + 1);
    }

    for (int i = 0; i < 10; i++) {
        if (i != 0) {
            cout << i << "0-" << i << "9: ";
        } else {
            cout << "0-9:";
        }
        for (int x = 0; x < hist.get(i); x++) {
            cout << "X";
        }
        cout << endl;
    }
}

int main() {
    ifstream input;
    while (true) {
        string filename = getLine ("File to open: ");
        input.open(filename);
        if (!input.fail()) {
            break;
        }
        cout << "Couldn't open " << filename << ".Try again" << endl;
    }
    Histogram(input);
    return 0;
}
