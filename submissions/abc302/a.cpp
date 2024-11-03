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
    long long a, b;
    cin >> a >> b;
    if (a % b == 0) {
        cout << a / b;
    } else {
        cout << (a / b) + 1;
    }
    return 0;
}
