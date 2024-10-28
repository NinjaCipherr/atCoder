#include <bits/stdc++.h>

#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<char> T(n);
    for (int i = 0; i < n; ++i) {
        cin >> T[i];
    }
    int count = 0;
    for (int i = 0; i <= n - 3; ++i) {
        if (T[i] == '#' && T[i + 2] == '#' && T[i + 1] == '.') {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}
