#include <fstream>
#include <iostream>
#include <random>

using namespace std;

int main() {
    const uint64_t MIN = 5000000000;
    const uint64_t MAX = 6000000000;
    const uint64_t TOTAL_NUM = 1000000;

    ofstream output;
    output.open("randomNum", iostream::binary);
    uint64_t total = 0;

    random_device rd;
    mt19937_64 eng(rd());
    uniform_int_distribution<uint64_t> dist(MIN, MAX);

    for (int i = 0; i < TOTAL_NUM; i++) {
        uint64_t x = dist(eng);
        total += x;
        output.write((char*)&x, 8);
    }
    double avg = total / TOTAL_NUM;
    output.write((char*)(&avg), 8);
    printf("%f\n", avg);
    return 0;
}