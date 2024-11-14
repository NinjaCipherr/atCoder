#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

int main() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        vec[i] = i + 1;
    }

    reverse(vec.begin() + l - 1, vec.begin() + r);
    for (auto element : vec) {
        cout << element << " ";
    }
    return 0;
}
