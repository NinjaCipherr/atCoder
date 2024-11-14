#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    // vector<string> vec(n);
    // for (int i = 0; i < n; i++) {
    //   cin >> vec[i];
    // }
    //

    if (n < 100) {
        cout << 100 - n;
    } else if (n < 200) {
        cout << 200 - n;
    } else {
        cout << 300 - n;
    }
    return 0;
}
