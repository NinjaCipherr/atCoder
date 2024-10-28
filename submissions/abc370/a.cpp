#include <bits/stdc++.h>

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (a == 1 && b == 0) {
        cout << "Yes";
    } else if (a == b) {
        cout << "Invalid";
    } else {
        cout << "No";
    }

    return 0;
}
