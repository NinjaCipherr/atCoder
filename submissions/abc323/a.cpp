#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    bool result = true;
    for (int i = 1; i < 16; i = i + 2) {
        if (s[i] != '0') {
            result = false;
            cout << "No";
            return 0;
        }
    }
    if (result)
        cout << "Yes";

    return 0;
}
