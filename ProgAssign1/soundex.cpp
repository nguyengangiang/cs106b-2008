#include "string.h"
#include "strlib.h"
#include "iostream"
#include "simpio.h"

using namespace std;

void Soundex(string* surname) {
    surname->replace(0, 1, charToString(toUpperCase(surname->at(0))));
    Vector<char> code0 = {'a', 'e', 'i', 'o', 'u', 'h', 'w', 'y'};
    Vector<char> code1 = {'b', 'f', 'p', 'v'};
    Vector<char> code3 = {'d', 't'};
    Vector<char> code4 = {'m', 'n'};

    for (int i = 1; i < surname->size(); i++) {
        if (code0.contains(toLowerCase(surname->at(i)))) {
            surname->replace(i, 1, "0");
        } else if (code1.contains(toLowerCase(surname->at(i)))) {
            surname->replace(i, 1, "1");
        } else if (code3.contains(toLowerCase(surname->at(i)))) {
            surname->replace(i, 1, "3");
        } else if (code4.contains(toLowerCase(surname->at(i)))) {
            surname->replace(i, 1, "4");
        } else if (toLowerCase(surname->at(i)) == 'l') {
            surname->replace(i, 1, "5");
        } else if (toLowerCase(surname->at(i)) == 'r') {
            surname->replace(i, 1, "6");
        } else {
            surname->replace(i, 1, "2");
        }
    }
}

string Truncate(string* surname) {
    int i = 1;
    string result = "" + surname->at(0);
    while (i < (surname->size())) {
        char prevChar = surname->at(i - 1);
        char nextChar = surname->at(i);
        if (prevChar != nextChar) {
            result += surname->at(i);
        }
        i++;
    }
    return result;
}

void RemoveZero(string* surname) {
    for (int i = 0; i < surname->size(); i++) {
        int pos = 0;
        while ((pos = surname->find('0', pos)) != string::npos) {
            surname->replace(pos, 1, "");
        }
    }
}


void PadAndTrim(string* surname) {
    if (surname->size() < 4) {
        while (surname->size() < 4) {
            surname->insert(surname->end(), '0');
        }
    } else {
        surname->erase(4, surname->size() - 4);
    }
}

int mainS() {
    string surname = getLine("Enter surname (RETURN to quit): ");
    while (surname != "") {
        string surname1 = surname;
        string result = "";
        Soundex(&surname);
        result = Truncate(&surname);
        RemoveZero(&result);
        PadAndTrim(&result);
        cout << "Soundex code for " << surname1 << " is " << result << endl;
        surname = getLine("Enter surname (RETURN to quit): ");
    }
    cout << "Program ended" << endl;
    return 0;
}
