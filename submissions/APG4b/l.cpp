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
    for (int i = 0; i < n; ++i) {
        int x;
        string s;
        cin >> s >> x;
        if (s == "+") {
            a = a + x;
        }

        else if (s == "-") {
            a = a - x;
        }

        else if (s == "*") {
            a = a * x;
        }

        else if (s == "/" && x != 0) {
            a = a / x;
        }

        else {
            cout << "error" << endl;
            break;
        }
        cout << i + 1 << ":" << a << endl;
    }

    return 0;
}
