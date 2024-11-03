#include <bits/stdc++.h>

#include <map>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    int count = 0;
    vector<int> result;
    sort(vec.begin(), vec.end());
    for (int i = 0; i < (n - 1); ++i) {
        if (x - vec[i] >= 0) {
            count++;
            x = x - vec[i];
        } else {
            break;
        }
    }
    if (x == vec[n - 1]) {
        count++;
    }

    cout << count;

    return 0;
}
