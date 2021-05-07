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

int main() {
    string result = "";
    Binary2(3);
}