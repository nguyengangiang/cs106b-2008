#include <iostream>
#include "stack.h"
#include "simpio.h"

void ReverseResponse() {
    cout << "What say you? ";
    string response = getLine();
    Stack<char> s;
    for (int i = 0; i < response.size(); i++) {
        s.push(response[i]);
    }
    while (!s.isEmpty()) {
        cout << s.pop();
    }
    cout << endl;
}

int main() {
    ReverseResponse();
}