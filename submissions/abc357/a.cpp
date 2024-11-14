#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a;
    cin >> n >> a;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (a >= vec[i]) {
            a = a - vec[i];
            count++;
        } else {
            break;
        }
    }
    cout << count;

    return 0;
}
