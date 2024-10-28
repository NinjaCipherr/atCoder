#include <bits/stdc++.h>

#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N;        // so tre
    long long x;  // so keo
    cin >> N >> x;
    vector<long long> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    int happyChilden = 0;
    for (int i = 0; i < N; i++) {
        if (x >= a[i]) {
            happyChilden++;
            x = x - a[i];
        }
    }
    if (x > 0) {
        happyChilden--;
    }
    cout << happyChilden << endl;

    return 0;
}