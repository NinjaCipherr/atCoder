#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int M = -1;
    int R = -1;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == 'M') {
            M = i;
        } else if (s[i] == 'R') {
            R = i;
        }
    }
    if (M > R) {
        cout << "Yes";
        return 0;
    }
    cout << "No";
    return 0;
}
