#include <stdio.h>
#include <fstream>
#include <vector>

using namespace std;

struct Stats
{
    uint8_t min;
    uint8_t max;
    float avg;
};

void ReadScores(string fileName, vector<uint8_t>& scores)
{
     ifstream input;
     input.open(fileName);
     int x;
     while (!input.eof())
     {
        input >> x;
        scores.push_back(uint8_t(x));
     }
     input.close();
     return;
}

Stats Compute(const vector<uint8_t>& scores)
{
    Stats stat;
    stat.max = 0;
    stat.min = 100;
    stat.avg = 0.0;

    for (int i = 0; i < scores.size(); i++)
    {
        if (scores[i] > stat.max)
        {
            stat.max = scores[i];
        }

        if (scores[i] < stat.min)
        {
            stat.min = scores[i];
        }
        stat.avg += scores[i];
    }
    stat.avg = stat.avg / scores.size();
    return stat;
} 

void WriteRecords(string fileName, const vector<uint8_t>& scores, Stats stat)
{
    ofstream output;
    output.open(fileName, iostream::binary);
    int sz = scores.size();
    output.write((char*) &sz, sizeof(sz));
    output.write((char*) scores.data(), sz*sizeof(uint8_t));
    output.write((char*) &stat, sizeof(stat));
    output.close();
}

Stats ReadStats(string fileName)
{
    ifstream input;
    input.open(fileName, iostream::binary);
    Stats stat;
    int sz;
    input.read((char*) &sz, sizeof(sz));
    input.ignore(sz);
    input.read((char*) &stat, sizeof(stat));
    input.close();
    return stat;
}

int main()
{
    vector<uint8_t> scores;
    ReadScores("record.data", scores);
    Stats s = Compute(scores);
    WriteRecords("score.bin", scores, s);
    Stats s2 = ReadStats("score.bin");
    printf("Min: %d, Max %d, Avg %.3f \n", s2.min, s2.max, s2.avg);
}