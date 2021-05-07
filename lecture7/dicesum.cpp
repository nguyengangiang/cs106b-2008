#include <string>
#include "strlib.h"

using namespace std;

void DiceSumHelper(int dice, int desiredSum, string& roll) {
    if (desiredSum == 0 && dice == 0) {
        cout << roll << endl;
    } else if (dice * 1 <= desiredSum && dice * 6 >= desiredSum) {
        for (int i = 1; i <= 6; i++) {
            roll.append(integerToString(i));
            DiceSumHelper(dice - 1, desiredSum - i, roll);
            roll.erase(roll.length() - 1);
        }
    }
}

void DiceSum(int dice, int sum) {
    string roll = "";
    DiceSumHelper(dice, sum, roll);
}

int main() {
    DiceSum(3, 7);
}