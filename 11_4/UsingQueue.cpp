#include "queue.h"
#include "simpio.h"
#include <iostream>

void ManageQueue() {
    Queue<string> queue;

    while (true) {
        cout << "? ";
        string response = getLine();
        if (response == "") break;
        if (response == "next") {
            if (queue.isEmpty()) {
                cout << "Noone is waiting!" << endl;
            } else {
                cout << "Handle " << queue.dequeue() << endl;
            }
        }
        else {
            queue.enqueue(response);
            cout << "Add " << response << endl;
        }
    }
}

int main() {
    ManageQueue();
}