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
const string outputFileName = "letters.bin";

void InitVector(Vector<letterFrequencyT>& frequencies) {
    for (int i = 0; i < NUM_LETTER; i++) {
        letterFrequencyT lft;
        lft.frequency = 0;
        lft.letter = i + 'a';
        frequencies.add(lft);
    }
}

void CountFrequency(Vector<letterFrequencyT>& frequencies, ifstream& inp) {
    while (!inp.eof()) {
        char ch = inp.get();
        if (isalpha(ch)) {
            frequencies[tolower(ch) - 'a'].frequency++;
        }
    }
}

void WriteFrequency(Vector<letterFrequencyT>& frequencies, string filename) {
    ofstream outp;
    outp.open(filename, iostream::binary);
    if (outp.fail()) {
        error("Couldn't open " + filename);
    }
    letterFrequencyT v[NUM_LETTER];
    for (int i = 0; i < NUM_LETTER; i++) {
        v[i] = (frequencies[i]);
    }
    outp.write((char*) &v, NUM_LETTER * sizeof(letterFrequencyT));
    outp.close();
}

void PrintVector(Vector<letterFrequencyT>& frequencies) {
    for (int i = 0; i < frequencies.size(); i++) {
        if (frequencies[i].frequency > 0) {
            printf("letter: %c, frequency: %ld\n", frequencies[i].letter, frequencies[i].frequency);
        }
    }
}

void ReadFrequency(string filename, Vector<letterFrequencyT>& frequenciesFromFile) {
    ifstream inp;
    inp.open(filename, iostream::binary);
    if (inp.fail()) error("couldn't open " + filename);
    letterFrequencyT v[NUM_LETTER];
    inp.read((char*) &v, sizeof(letterFrequencyT) * NUM_LETTER);
    inp.close();
    for (int i = 0; i < NUM_LETTER; i++) {
        frequenciesFromFile.add(v[i]);
    }
    inp.close();
}

void CountLetters(string filename) {
    Vector<letterFrequencyT> frequencies;
    Vector<letterFrequencyT> frequenciesFromFile;
    ifstream inp;
    inp.open(filename);
    ofstream outp;
    outp.open(outputFileName, iostream::binary);
    if (inp.fail()) {
        error("Cannot open file " + filename);
    }
    if (outp.fail()) {
        error("Cannot open file" + outputFileName);
    }
    InitVector(frequencies);
    CountFrequency(frequencies, inp);
    WriteFrequency(frequencies, outputFileName);
    ReadFrequency(outputFileName, frequenciesFromFile);
    PrintVector(frequenciesFromFile);
    outp.close();
    inp.close();
}

int main() {
    CountLetters("letters.txt");
    return 0;
}