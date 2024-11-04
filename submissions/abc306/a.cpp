#include <bits/stdc++.h>

#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int n;
    string a;
    cin >> n >> a;
    string result = "";
    for (int i = 0; i < n; ++i) {
        result = result + a[i] + a[i];
    }
    cout << result << endl;
    return 0;
}
