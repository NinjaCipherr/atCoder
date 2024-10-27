
#include <bits/stdc++.h>

#include <iostream>
#include <vector>

using namespace std;
int main() {
    string s;
    cin >> s;
    if (s.length() != 3) {
        cout << "No";
    }
    bool hasA = false, hasB = false, hasC = false;
    for (char ch : s) {
        if (ch == 'A') {
            hasA = true;
        } else if (ch == 'B') {
            hasB = true;
        } else if (ch == 'C') {
            hasC = true;
        }
    }
    if (hasA && hasB && hasC) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}
