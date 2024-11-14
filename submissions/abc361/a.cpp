#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, x;
    cin >> n >> k >> x;
    // vector<string> vec(n);
    // for (int i = 0; i < n; i++) {
    //   cin >> vec[i];
    // }
    //
    //
    //
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    vector<int> newVec(n + 1);
    for (int i = 0; i < k; ++i) {
        newVec[i] = vec[i];
    }
    newVec[k] = x;
    for (int i = k; i < n; i++) {
        newVec[i + 1] = vec[i];
    }
    for (int i = 0; i < n + 1; ++i) {
        cout << newVec[i] << " ";
    }
    return 0;
}
