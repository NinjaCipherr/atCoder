#include <bits/stdc++.h>

#include <iostream>
#include <vector>

using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> result;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] % k == 0) {
            result.push_back(arr[i] / k);
        }
    }
    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}
