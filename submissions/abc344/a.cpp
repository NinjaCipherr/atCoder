#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int count = 0;
    string result = "";
    for (char c : s) {
        if (c == '|') {
            count++;
        } else {
            if (count != 1) {
                result = result + c;
            }
        }
    }
    cout << result;

    return 0;
}
