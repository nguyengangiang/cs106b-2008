#include <string>
#include <vector>
#include <iostream>

using namespace std;

void PowerSetHelper(vector<string> &v, vector<string>& chosen) {
    if (v.empty()) {
        for (string s : chosen) {
            cout << s;
        }
        cout << endl;
    } else {
        string s = v[0];
        v.erase(v.begin());
        PowerSetHelper(v, chosen);
        chosen.push_back(s);
        PowerSetHelper(v, chosen);

        v.insert(v.begin(), s);
        chosen.pop_back();
    }
}

void PowerSet(vector<string>& v) {
    vector<string> chosen;
    PowerSetHelper(v, chosen);
}

int main() {
    vector<vector<string> > tests{
        {"a", "b", "c"},
        {"1", "2", "3", "4"}
    };

    // expected for a, b, c: 8
    // abc, ab, bc, ca, a, c, b, {}
    // expected for 1, 2, 3, 4: 16
    for (vector<string> test : tests) {
        PowerSet(test);
    }
}