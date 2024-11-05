#include <bits/stdc++.h>

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (a < b) {
        if (b - a <= 2) {
            cout << "Yes";
        } else {
            cout << "No";
        }
    } else {
        if (a - b <= 3) {
            cout << "Yes";
        } else {
            cout << "No";
        }
    }
    return 0;
}
