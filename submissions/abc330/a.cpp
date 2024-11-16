#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l;
    cin >> n >> l;
    vector<int> vec(n);
    int count = 0;
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    for (int i = 0; i < n; ++i) {
        if (vec[i] >= l) {
            count++;
        }
    }
    cout << count;

    return 0;
}
