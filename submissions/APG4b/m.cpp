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
    int a, b;
    cin >> a >> b;
    cout << "A:";
    while (a > 0) {
        cout << "]";
        a--;
    }
    cout << endl;
    cout << "B:";
    while (b > 0) {
        cout << "]";
        b--;
    }
    cout << endl;

    return 0;
}
