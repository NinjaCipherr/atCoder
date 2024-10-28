#include <bits/stdc++.h>

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int d = a - b - c;
    if ((a + d > b) && (b + d > a)) {
        cout << "No";
    } else {
        cout << "Yes";
    }

    return 0;
}
