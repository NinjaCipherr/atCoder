#include <bits/stdc++.h>

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a, b;

    cin >> a >> b;
    // for (int i = 0; i < n; ++i) {
    //   cin >> str[i];
    // }
    int seki = 1;
    for (int i = a; i <= b; i++) {
        seki = seki * i;
    }
    if (seki > 0) {
        cout << "Positive" << endl;
    } else if (seki == 0) {
        cout << "Zero";
    } else {
        cout << "Negative";
    }
}