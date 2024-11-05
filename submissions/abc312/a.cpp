#include <bits/stdc++.h>

#include <iostream>
#include <vector>

using namespace std;

int main() {
    string n;
    cin >> n;
    vector<string> vec = {"ACE", "BDF", "CEG", "DFA", "EGB", "FAC", "GBD"};

    for (int i = 0; i < vec.size(); ++i) {
        if (n == vec[i]) {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}
