#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int count = 0;
    vector<string> vec(n);

    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    for (int i = 0; i < n; i++) {
        if (vec[i] == "Takahashi") {
            count++;
        }
    }
    cout << count;

    return 0;
}
