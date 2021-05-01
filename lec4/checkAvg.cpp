#include <fstream>
#include "strlib.h"
#include "vector.h"
#include "error.h"

using namespace std;

const int TOTAL_NUM = 1000000;

double CalvAvg(Vector<uint64_t> &vec) {
    double total = 0;
    for (int i = 0; i < TOTAL_NUM; i++) {
        total += vec[i];
    }
    return total / TOTAL_NUM;
}

int main() {
    ifstream input;
    input.open("randomNum", ifstream::binary);
    if (input.fail()) error("Couldn't open file to read");
    uint64_t readToken;
    Vector<uint64_t> temp(TOTAL_NUM);
    for (int i = 0; i < TOTAL_NUM; i++) {
        input.read((char*) &temp[i], 8);
    }
    input.read((char*) &readToken, 8);
    printf("%f\n", CalvAvg(temp));
    input.close();
    return 0;
}