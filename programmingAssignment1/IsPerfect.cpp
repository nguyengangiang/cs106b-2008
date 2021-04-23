#include "vector.h"

using namespace std;

bool isPerfect(int n) {
    Vector<int> perfectNum;
    int sumPerfect = 0;
    for (int i = 1; i <= n/2; i++) {
        if (n % i == 0) {
            sumPerfect += i;
        }
    }

    if (sumPerfect == n) {
        return true;
    } else {
        return false;
    }
}

int main () {
    for (int i = 1; i <= 10000; i++) {
        if (isPerfect(i)) {
            cout << i << " is a perfect number." << endl;
        }
    }
}