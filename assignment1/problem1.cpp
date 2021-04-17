#include "strlib.h"
#include "tokenscanner.h"
#include <string>
#include <iostream>

using namespace std;

string CensorString1(string text, string remove) {
    string result;
    for (int i = 0; i < text.size(); i++) {
        if (remove.find(text[i]) == -1) {
            result += text[i];
        }
    }
    return result;
}

void CensorString2(string & text, string remove) {
    for (int i = 0; i < remove.size(); i++) {
        int pos = 0;
        while ((pos = text.find(remove[i], pos)) != -1) {
            text.erase(pos, 1);
        }
    }
}

int main() {
    string text = "Stanford University";
    string remove = "nt";
    cout << CensorString1(text, remove) << endl;
    CensorString2(text, remove);
    cout << text << endl;

    text = "Llamas like to laugh";
    remove = "ls";
    cout << CensorString1(text, remove) << endl;
    CensorString2(text, remove);
    cout << text << endl;
}