#include <iostream>

using namespace std;

void Binary(int size, string result) {
    if (size == 0) {
        cout << result << endl;
    } else {
        Binary(size - 1, result + "0");
        Binary(size - 1, result + "1");
    }
}

void Binary2(int size) {
    if (size <= 0) {
        cout << endl;
    } else {
        cout << "0";
        Binary2(size - 1);
        cout << "1";
        Binary2(size -1 );
    }
}

int main() {
    string result = "";
    Binary2(3);
}