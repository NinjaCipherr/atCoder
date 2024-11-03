#include <bits/stdc++.h>

#include <iostream>
#include <map>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int n, a;
    cin >> n >> a;
    int one_yen = n % 500;
    if (one_yen <= a) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
