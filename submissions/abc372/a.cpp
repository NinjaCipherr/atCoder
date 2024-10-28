#include <bits/stdc++.h>

#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s;
    string result = "";
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != '.') {
            result = result + s[i];
        }
    }
    cout << result << endl;
    ;
    return 0;
}
