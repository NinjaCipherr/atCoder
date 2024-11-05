#include <bits/stdc++.h>

#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;
    string ans = "";
    for (char c : s) {
        if (c != 'a' && c != 'i' && c != 'u' && c != 'e' && c != 'o') {
            ans = ans + c;
        }
    }
    cout << ans;
    return 0;
}
