#include <iostream>
#include "simpio.h"

using namespace std;

int CountOccurences(char ch, string str) {
    int count = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ch) {
            count++;
        }
    }
    return count;
}

void RemoveOccurences(char ch, string &s) {
    int found;
    while((found = s.find(ch)) != string::npos) {
        s.erase(found, 1);
    }
}

int main() {
    string myString = "for more details, please visit:";
    cout << CountOccurences('s', "for more details, please visit: ") << endl;
    RemoveOccurences('s', myString);
    cout << myString << endl;
    return 0;
}
