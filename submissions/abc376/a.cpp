#include <bits/stdc++.h>

#include <vector>

using namespace std;

int main() {
    int n, c;

    cin >> n >> c;

    vector<int> T(n);
    for (int i = 0; i < n; ++i) {
        cin >> T[i];
    }

    int candies = 0;

    int last_press_time = -c;

    for (int i = 0; i < n; ++i) {
        if (T[i] - last_press_time >= c) {
            candies++;
            last_press_time = T[i];
        }
    }
    cout << candies << endl;
    return 0;
}
