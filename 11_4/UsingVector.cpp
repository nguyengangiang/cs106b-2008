#include <iostream>
#include "simpio.h"
#include "vector.h"
#include "random.h"

using namespace std; 

Vector<int> MakeRandomVector(int size) {
    Vector<int> vector;
    for (int i = 0; i < size; i++) {
        vector.add(randomInteger(0, 100));
    }
    return vector;
}

void printVector(Vector<int> &vector) {
    for (int i = 0; i < vector.size(); i++) {
        cout << vector[i] << endl;
    }
}

int main() {
    Vector<int> v = MakeRandomVector(10);
    printVector(v);
}