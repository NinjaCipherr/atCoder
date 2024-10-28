#include <bits/stdc++.h>

#include <iostream>
#include <vector>

using namespace std;
int main() {
    int n;
    cin >> n;
    string str = "";
    for (int i = 0; i < n; i++) {
        str = str + to_string(n);
    }
    cout << str;
    return 0;
}
