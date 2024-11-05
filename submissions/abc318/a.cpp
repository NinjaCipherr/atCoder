#include <bits/stdc++.h>

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int count = 0;
    if (a < b) {
        cout << 0;
        return 0;
    }
    cout << (a - b) / c + 1;
    return 0;
}
