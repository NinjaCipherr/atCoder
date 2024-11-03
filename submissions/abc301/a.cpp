#include <bits/stdc++.h>

#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    vector<char> vec(n);
    int a = 0;
    int b = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'T')
            b++;
        else if (s[i] == 'A')
            a++;
    }
    if (a != b) {
        if (a > b)
            cout << "A" << endl;
        else
            cout << "T" << endl;
    } else {
        char last_char = s[n - 1];
        if (last_char == 'A')
            cout << "T" << endl;
        else
            cout << "A" << endl;
        ;
    }
    return 0;
}
