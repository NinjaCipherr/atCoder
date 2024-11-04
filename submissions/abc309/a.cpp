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
    int a, b;
    cin >> a >> b;
    vector<int> vec(9);
    for (int i = 0; i < 9; ++i) {
        vec[i] = i + 1;
    }

    for (int i = 0; i < 9; i++) {
        if (vec[i] % 3 != 0 && vec[i] == a && vec[i + 1] == b) {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}
