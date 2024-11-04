#include <bits/stdc++.h>

#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int n;
    // string s;
    cin >> n;
    if (n == 12) {
        cout << 1 << endl;
    } else if (n < 12 && n >= 1) {
        cout << n + 1 << endl;
    }
    return 0;
}
