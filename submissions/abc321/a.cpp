#include <bits/stdc++.h>

#include <vector>

using namespace std;

int main() {
    string a;
    cin >> a;
    for (int i = 0; i < a.length() - 1; i++) {
        if (a[i] <= a[i + 1]) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";

    return 0;
}
