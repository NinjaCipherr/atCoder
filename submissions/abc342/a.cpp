#include <bits/stdc++.h>

#include <unordered_map>
using namespace std;

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        bool diff = true;
        for (int j = 0; j < s.length(); j++) {
            if (i != j and s[i] == s[j]) {
                diff = false;
            }
        }
        if (diff) {
            cout << i + 1;
        }
    }

    return 0;
}
