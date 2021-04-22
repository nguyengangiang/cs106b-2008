#include <iostream>

using namespace std;

int fracR(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * fracR(n-1);
    }
}

int fracL(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    cout << "Calculate frac of? ";
    int inp;
    cin >> inp;
    cout << "recursion: " << fracR(inp) << endl;
    cout << "loops: " << fracL(inp) << endl;
}