#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    int sum = 0;
    int index = 0;

    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    for (int i = 0; i < n; ++i) {
        if (vec[i] <= k) {
            sum += vec[i];
        }
    }
    cout << sum;

    return 0;
}
