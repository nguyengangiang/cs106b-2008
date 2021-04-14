#include <fstream>
#include "stack.h"
#include "simpio.h"

using namespace std;

void reverseInput(ifstream& input, ofstream& output) {
    Stack<string> lines;
    string line = "";
    while(true) {
        getline(input, line);
        if (input.fail()) break;
        lines.push(toUpperCase(line));
    }

    while(!lines.isEmpty()) {
        output << lines.pop() << endl;
    }
}

int main() {
    ifstream input;
    ofstream output;
    input.open("mydata.txt");
    output.open("reverseMyData.txt");
    reverseInput(input, output);
    return 0;
}