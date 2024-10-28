#include <bits/stdc++.h>

#include <iostream>
#include <vector>

using namespace std;

int main() {
    char ab, ac, bc;
    cin >> ab >> ac >> bc;
    if (ab != ac) {
        cout << "A";
    } else if (ab == bc) {
        cout << "B";
    } else {
        cout << "C";
    }

    return 0;
}
