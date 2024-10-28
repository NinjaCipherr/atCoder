#include <bits/stdc++.h>

#include <iostream>
#include <vector>

using namespace std;
int main() {
    // int n;
    // cin >> n;
    // vector<int> arr(n);
    // for (int i = 0; i < n; i++) {
    //   cin >> arr[i];
    // }
    //
    string str;
    cin >> str;
    int first_A = -1;
    int last_Z = -1;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'A' && first_A == -1) {
            first_A = i;
        }
        if (str[i] == 'Z') {
            last_Z = i;
        }
    }
    cout << last_Z - first_A + 1;

    return 0;
}
