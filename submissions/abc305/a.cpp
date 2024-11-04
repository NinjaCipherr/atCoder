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
    cin >> n;
    int lower = (n / 5) * 5;
    int upper = lower + 5;
    if ((n - lower) < (upper - n)) {
        cout << lower;
    } else {
        cout << upper;
    }
    return 0;
}
