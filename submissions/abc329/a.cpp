#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    string result = "";
    for (int i = 0; i < s.length() - 1; ++i) {
        result = result + s[i] + " ";
    }
    cout << result << s[s.length() - 1];

    return 0;
}
