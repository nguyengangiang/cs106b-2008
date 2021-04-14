#include <fstream>
#include "strlib.h"
#include "filelib.h"

using namespace std;

void CopyData(ifstream& input, ofstream& output) {
    string line = "";
    while (true) {
        string upperLine = "";
        getline(input, line);
        if (input.fail()) break;
        upperLine = toUpperCase(line);
        output << upperLine << endl;
    }
}

int main() {
    ifstream input;
    ofstream output;
    input.open("mydata.txt");
    output.open("copy.txt");
    if (input.fail() || output.fail()) {
        error("Couldn't open file \n");
    }
    CopyData(input, output);
    input.close();
    output.close();
    return 0;
}
