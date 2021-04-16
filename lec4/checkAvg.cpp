#include <iostream>
#include <fstream>
#include "tokenscanner.h"
#include "strlib.h"
#include "vector.h"
#include "error.h"

using namespace std;

const int TOTAL_NUM = 1000000;

double CalvAvg(Vector<uint64_t> &vec) {
    double total = 0;
    for (int i = 0; i < vec.size(); i++) {
        total += vec[i];
    }
    return total / TOTAL_NUM;
}

int main() {
    ifstream input;
    ofstream output;
    output.open("copyNum");
    input.open("randomNum", iostream::binary);
    if (input.fail()) error("Couldn't open file to read");
    uint64_t readToken;
    uint64_t total;
    Vector<uint64_t> temp(TOTAL_NUM);
    for (int i = 0; i < TOTAL_NUM; i++) {
        input.read((char*) &temp[i], 8);
    }
    input.read((char*) &readToken, 8);
    printf("%f\n", CalvAvg(temp));
    return 0;
}