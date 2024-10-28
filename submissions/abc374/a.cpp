#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    string str = "";
    cin >> str;
    if (str.size() >= 3 && str.substr(str.size() - 3) == "san") {
        cout << "true" << endl;
    } else {
        cout << "false";
    }
}