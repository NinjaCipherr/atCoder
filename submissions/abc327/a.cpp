#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<char> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }

    for (int i = 0; i < n; i++) {
        if ((vec[i] == 'a' && vec[i + 1] == 'b') ||
            (vec[i] == 'b' && vec[i + 1] == 'a')) {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}
