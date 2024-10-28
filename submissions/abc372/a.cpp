#include <bits/stdc++.h>

using namespace std;

int main() {
    string S;
    cin >> S;
    string result;
    for (int i = 0; i < S.length(); ++i) {
        if (S[i] != '.') {
            result = result + S[i];
        }
    }
    cout << result;
}
