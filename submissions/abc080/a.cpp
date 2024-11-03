#include <bits/stdc++.h>

#include <iostream>
#include <map>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int free = a * b;
    if (free < c) {
        cout << free << endl;
    } else {
        cout << c << endl;
    }
    return 0;
}
