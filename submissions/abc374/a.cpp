#include <bits/stdc++.h>

#include <iostream>

using namespace std;

int main() {
    string str = "";
    cin >> str;
    if (str.size() >= 3 && str.substr(str.size() - 3) == "san") {
        cout << "Yes" << endl;
    } else {
        cout << "No";
    }
}
