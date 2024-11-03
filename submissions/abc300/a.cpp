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
    int n, a, b;
    // string s;
    cin >> n >> a >> b;
    vector<int> vec(n);
    int sum = a + b;
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    for (int i = 0; i < n; i++) {
        if (sum == vec[i]) {
            cout << i + 1 << endl;
            return 0;
        }
    }

    return 0;
}
