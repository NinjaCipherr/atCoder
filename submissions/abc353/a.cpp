#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    for (int i = 0; i < n; i++) {
        if (vec[i] > vec[0]) {
            cout << i + 1;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
