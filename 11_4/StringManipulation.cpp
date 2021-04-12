#include <iostream>
#include "simpio.h"
#include <fstream>
#include "strings.h"

using namespace std; 

int CountLines(ifstream &in) {
    int count = 0; 
    while (true) {
        string line;
        getline(in, line);
        if (in.fail()) break;
        count++;
    }
    return count;
}

int main() {
    ifstream in;
    while (true) {
        cout << "Enter name: ";
        string s = getLine();
        in.open(s);
        if (!in.fail()) { break;}
        cout << "file didn't open, try again" << endl;
        in.clear();
    }
    cout << "Num lines = " << CountLines(in) << endl;
    return 0;
}