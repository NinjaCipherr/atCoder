#include <bits/stdc++.h>

#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    for (int i = 1; i < n; i++) {
        if (vec[i - 1] == "sweet" && vec[i] == "sweet" && i != vec.size() - 1) {
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";

    return 0;
}
