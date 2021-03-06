#include "stdio.h"
#include <map>
#include <fstream>
#include "error.h"
#include "strlib.h"
#include "string.h"

using namespace std;

const string commonWord[] = {"and", "a", "i", "the", "to", "of", "that", "you", "for", "my", "in"};

void CountOccurences(ifstream & inp, map<string, int>& wordFrequency) {
    while (!inp.eof()) {
        string temp;
        inp >> temp;
        temp = toLowerCase(temp);
        wordFrequency[temp] += 1;
    }
}

bool Contains(string str) {
    for (string word : commonWord) {
        if (word == str) {
            return true;
        }
    }
    return false;
}

void MostFrequency(map<string, int> wordFrequency) {
    std::map<string, int>::iterator itr;
    int maxFreq = 0;
    string maxFreqWord;
    for (itr = wordFrequency.begin(); itr != wordFrequency.end(); itr++) {
        if (!Contains(itr->first) && maxFreq < itr->second) {
            maxFreq = itr->second;
            maxFreqWord = itr->first;
        }
    }
    cout << "Most common word \"" << maxFreqWord << "\" occurs " << maxFreq << " times." << endl;
}

int main() {
    ifstream inp;
    inp.open("shakespeare.txt");
    if (inp.fail()) {
        error("Cannot open shakespeare.txt");
    }
    map<string, int> wordFrequency;
    CountOccurences(inp, wordFrequency);
    MostFrequency(wordFrequency);
    inp.close();
    return 0;
}