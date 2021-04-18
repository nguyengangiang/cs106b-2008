#include <cctype>
#include "string.h"
#include "vector.h"
#include "tokenscanner.h"
#include <fstream>
#include "error.h"
#include <iostream>
#include <stdio.h>

using namespace std;

struct letterFrequencyT {
    char letter; 
    long frequency;
};

const int NUM_LETTER = 'z' - 'a' + 1;

void initVector(Vector<letterFrequencyT>& lf) {
    for (int i = 0; i < NUM_LETTER; i++) {
        letterFrequencyT lft;
        lft.frequency = 0;
        lft.letter = i + 'a';
        lf.add(lft);
    }
}

void countFrequency(Vector<letterFrequencyT>& lf, ifstream& inp) {
    while (!inp.eof()) {
        char ch = inp.get();
        if (isalpha(ch)) {
            lf[tolower(ch) - 'a'].frequency++;
        }
    }
}

void writeFrequency(Vector<letterFrequencyT>& lfv, string filename) {
    ofstream outp;
    outp.open(filename, iostream::binary);
    letterFrequencyT v[NUM_LETTER];
    for (int i = 0; i < NUM_LETTER; i++) {
        v[i] = (lfv[i]);
    }
    outp.write((char*) &v, NUM_LETTER * sizeof(letterFrequencyT));
}

void printVector(Vector<letterFrequencyT>& lfv) {
    for (int i = 0; i < lfv.size(); i++) {
        printf("letter: %c, frequency: %ld\n", lfv[i].letter, lfv[i].frequency);
    }
}

Vector<letterFrequencyT> readFrequency(string filename) {
    ifstream inp;
    inp.open(filename, iostream::binary);
    if (inp.fail()) error("couldnt open file.");
    Vector<letterFrequencyT> readFromFile;
    letterFrequencyT v[NUM_LETTER];
    inp.read((char*) &v, sizeof(letterFrequencyT) * NUM_LETTER);
    inp.close();
    for (int i = 0; i < NUM_LETTER; i++) {
        readFromFile.add(v[i]);
    }
    return readFromFile;
}

void CountLetters(string filename) {
    Vector<letterFrequencyT> lfv;
    Vector<letterFrequencyT> readFromFile;
    ifstream inp;
    inp.open(filename);
    ofstream outp;
    outp.open("shakespeare.bin", iostream::binary);
    if (inp.fail() | outp.fail()) {
        error("Cannot open file.");
    }
    initVector(lfv);
    countFrequency(lfv, inp);
    writeFrequency(lfv, "shakespeare.bin");
    readFromFile = readFrequency("shakespeare.bin");
    printVector(readFromFile);
    outp.close();
    inp.close();
}

int main() {
    CountLetters("shakespeare.txt");
    return 0;
}