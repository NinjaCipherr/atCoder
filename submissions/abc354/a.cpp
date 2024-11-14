#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

int main() {
    int a;
    cin >> a;
    // vector<int> vec(n);
    // for (int i = 0; i < n; i++) {
    //   vec[i] = i + 1;
    // }
    //
    int now = 0;
    int ans = 0;
    while (now <= a) {
        now = now + (1 << ans);
        ans++;
    }
    cout << ans;
    return 0;
}
