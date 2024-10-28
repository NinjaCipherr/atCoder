#include <bits/stdc++.h>

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a, b, c;

    cin >> a >> b >> c;
    int count = 0;
    while (a % 2 == 0 || b % 2 == 0 || c % 2 == 0) {
        if (a == b && b == c) {
            cout << -1 << endl;
            break;
        }
        int newA = (b + c) / 2;
        int newB = (a + c) / 2;
        int newC = (a + b) / 2;

        a = newA;
        b = newB;
        c = newC;
        count++;

        if (!a % 2 == 0 || !b % 2 == 0 || !b % 2 == 0) {
            cout << count;
            break;
        }
    }

    return 0;
}
