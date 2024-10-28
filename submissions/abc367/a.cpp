#include <bits/stdc++.h>

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (b < c) {
        if (c > a && a > b) {
            cout << "No";
        } else {
            cout << "Yes";
        }
    } else {
        if (c < a && a < b) {
            cout << "Yes";
        } else {
            cout << "No";
        }
    }
    return 0;
}
