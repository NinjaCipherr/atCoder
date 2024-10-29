#include <bits/stdc++.h>

using namespace std;
int main() {
    string S;
    cin >> S;
    int count = S.rfind('.');

    string result = S.substr(count + 1);
    cout << result;

    return 0;
}