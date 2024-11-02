#include <bits/stdc++.h>

#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
    int a;
    cin >> a;
    vector<int> vector(a);
    for (int i = 0; i < a; ++i) {
        cin >> vector[i];
    }
    unordered_set<int> set(vector.begin(), vector.end());
    if (set.size() == 1) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}
