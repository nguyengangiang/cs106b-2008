#include <fstream>
#include <stdio.h>
#include "vector.h"
#include "strlib.h"

using namespace std;

struct Grades {
    int min;
    int max;
    float avg;
};

Grades CalcAvgAndWrite(Vector<int>& vec, ofstream& outp) {
    int total = 0;
    int min = vec[0];
    int max = vec[0];
    for (int i = 0; i < 20; i++) {
        total += vec[i];
        if (min > vec[i]) {
            min = vec[i];
        }
        if (max < vec[i]) {
            max = vec[i];
        }
    }
    float avg = total / vec.size();
    Grades grades;
    grades.avg = avg;
    grades.max = max;
    grades.min = min;
    outp.write((char*) &grades, sizeof(Grades));
    return grades;
}

void readFile(Vector<int>& vec, ifstream& inp, ofstream& outp) {
    int temp;
    while(!inp.eof()) {
        inp >> temp;
        cout << temp << endl;
        outp.write((char*) &temp, 4);
        vec.add(temp);
    }
}

void printGrade(Grades& grades) {
    printf("min grade = %d, max grade = %d, avg = %.3f\n", grades.min, grades.max, grades.avg);
}

int main() {
    ifstream inp;
    ofstream outp;
    inp.open("record.data", ifstream::binary);
    outp.open("record_in_bin.data", ofstream::binary);

    if (inp.fail() || outp.fail()) {
        error("Couldn't open file");
    }
    Vector<int> records;
    readFile(records, inp, outp);
    Grades grades = CalcAvgAndWrite(records, outp);
    printGrade(grades);
    outp.close();
    inp.close();
}