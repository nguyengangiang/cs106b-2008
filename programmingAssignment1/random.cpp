#include "random.h"
#include "simpio.h"
#include <iostream>

using namespace std;

bool invalidElectionResult(int voterNum, float percentSpread, float errorPercent) {
    int initialVotesForA = (voterNum * percentSpread + voterNum) / 2;
    int initialVotesForB = voterNum - initialVotesForA;
    int newinitialVotesForB = 0;
    int newinitialVotesForA = 0;
    for (int i = 0; i < initialVotesForA; i++) {
        bool isInverted = randomChance(errorPercent);
        if (!isInverted) {
            newinitialVotesForA ++;
        } else {
            newinitialVotesForB++;
        }
    }

    for (int i = 0; i < initialVotesForB; i++) {
        bool isInverted = randomChance(errorPercent);
        if (!isInverted) {
            newinitialVotesForB ++;
        } else {
            newinitialVotesForA++;
        }
    }
    return newinitialVotesForA < newinitialVotesForB;
}

int main() {
    int invalidResult = 0;
    int voterNum;
    float percentSpread;
    float errorPercent;
    voterNum = getInteger("Enter number of voters: ");
    percentSpread = getReal("Enter percentage spread between candidates: ");
    while (percentSpread < 0 || percentSpread > 1) {
        percentSpread = getReal("Enter percentage spread between candidates: ");
    }
    errorPercent = getReal("Enter voting error percentage: ");
    while(errorPercent < 0 || errorPercent > 1) {
        errorPercent = getReal("Enter voting error percentage: ");
    }
    for (int i = 0; i < 500; i++) {
        if (invalidElectionResult(voterNum, percentSpread, errorPercent)) {
            invalidResult++;
        }
    }
    cout << "Chance of an invalid election result after 500 trials = " << endl;
    float invalidResultPercent = invalidResult / 5;
    cout << invalidResultPercent << "%" << endl;
}
