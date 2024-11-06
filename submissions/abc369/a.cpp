#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    // vector<int> vec(n);
    // for (int i = 0; i < n; i++) {
    //   cin >> vec[i];
    //
    // }
    if (n == k) {
        cout << 1;
    } else if ((n + k) % 2 == 0) {
        cout << 3;
    } else {
        cout << 2;
    }

    return 0;
}
