#include "strlib.h"
#include <iostream>

using namespace std;
bool isPalin(string str) {
    if (str.length() == 1) {
        return true;
    } else {
        if (str.at(0) == str.at(str.length() - 1)) {
            return isPalin(str.substr(1, str.length() - 2));
        } else {
            return false;
        }
    }
}

int main() {
    string str;
    while (str != "q") {
        cout << "Enter word: ";
        cin >> str;
        cout << isPalin(str) << endl;
    }
    return 0;
}