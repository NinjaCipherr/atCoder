#include <bits/stdc++.h>

#include <iostream>
#include <vector>

using namespace std;
int main() {
    int n;
    cin >> n;
    string a = "";
    for (int i = 0; i < n; i++) {
        a = a + "o";
    }
    string result = "L" + a + "ng";
    cout << result;
    return 0;
}
