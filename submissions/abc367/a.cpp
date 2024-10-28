#include <bits/stdc++.h>

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (b < c) {
        if (c < a) {
            cout << "Yes";
        } else {
            cout << "No";
        }
    }
    if (b > c) {
        if (a < c) {
            cout << "No";
        } else {
            cout << "Yes";
        }
    }
    return 0;
}
