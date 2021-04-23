#include <iostream>

using namespace std;

uint64_t fibR(uint64_t n) {
    if (n == 2) {
        return 1;
    } else if (n == 1) {
        return 1;
    } else {
        return fibR(n-2) + fibR(n - 1);
    }
}

uint64_t fibL(uint64_t n) {
    uint64_t result1 = 1;
    uint64_t result2 = 1;
    uint64_t result = 0;

    if (n <= 2) {
        return 1;
    }

    for (uint64_t i = 2; i < n; i++) {
        result = result1 + result2;
        result2 = result1;
        result1 = result;
    }
    return result;
}

int main() {
    cout << "Calculate fib of? ";
    uint64_t inp;
    cin >> inp;
    //cout << "recursion: " << fibR(inp) << endl;
    cout << "loops: " << fibL(inp) << endl;
}