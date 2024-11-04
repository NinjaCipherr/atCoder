#include <bits/stdc++.h>

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    string pi =
        "3."
        "1415926535897932384626433832795028841971693993751058209749445923"
        "078164062862089986280348253421170679";
    for (int i = 0; i < n + 2; ++i) {
        cout << pi[i];
    }
    return 0;
}
