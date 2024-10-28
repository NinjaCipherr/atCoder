#include <bits/stdc++.h>

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int d = a - b - c;

    if (b > c + d) {
        cout << "Yes";
    } else if (c > b + d) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}
