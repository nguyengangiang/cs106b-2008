#include "string.h"
#include "strlib.h"

using namespace std;

int Eval(string& exp, int& ind) {
    if (exp[ind] == '(') {
        ind+=1;
        int left = Eval(exp, ind);
        char op = exp[++ind];
        int right = Eval(exp, ++ind);
        ind += 1;
        if (op == '+') {
            return left + right;
        } else {
            return left * right;
        }
    } else {
        return exp[ind] - '0';
    }
}

int Eval(string& exp) {
    int ind = 0;
    return Eval(exp, ind);
}


int main() {
    string exps[] = {"(2+3)", "(2*(3+2))", "((3+4)*((5+6)+3))"};
    for (string exp : exps) {
        cout << exp << " = " << Eval(exp) << endl;
    }
    return 0;
}