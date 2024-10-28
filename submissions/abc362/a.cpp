#include <bits/stdc++.h>

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int r, g, b;
    string e;
    cin >> r >> g >> b;
    cin >> e;
    if (e == "Blue") {
        cout << min(r, g);
    }
    if (e == "Red") {
        cout << min(g, b);
    }
    if (e == "Green") {
        cout << min(r, b);
    }

    return 0;
}
