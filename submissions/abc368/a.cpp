#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    for (int i = n - k; i < n + (n - k); ++i) {
        cout << vec[i % n] << " ";
    }

    return 0;
}
