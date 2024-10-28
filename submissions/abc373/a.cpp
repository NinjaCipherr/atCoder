#include <bits/stdc++.h>

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n = 12;
    vector<string> str(n);
    for (int i = 0; i < n; ++i) {
        cin >> str[i];
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (str[i].length() == i + 1) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}