#include <iostream>

using namespace std;

int fibR(int n) {
    if (n == 2) {
        return 1;
    } else if (n == 1) {
        return 1;
    } else {
        return fibR(n-2) + fibR(n - 1);
    }
}

int fibL(int n) {
    int result1 = 1;
    int result2 = 1;
    int result = 0;

    if (n <= 2) {
        return 1;
    }

    for (int i = 2; i < n; i++) {
        result = result1 + result2;
        result2 = result1;
        result1 = result;
    }
    return result;
}

int main() {
    cout << "Calculate fib of? ";
    int inp;
    cin >> inp;
    cout << "recursion: " << fibR(inp) << endl;
    cout << "loops: " << fibL(inp) << endl;
}