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
    int n;
    cin >> n;
    vector<int> count(4, 0);
    for (int i = 0; i < n; ++i) {
        string color;
        cin >> color;
        if (color == "P") {
            count[0]++;
        }

        else if (color == "W") {
            count[1]++;
        }

        else if (color == "G") {
            count[2]++;
        }

        else if (color == "Y") {
            count[3]++;
        }
    }

    int distinColor = 0;
    for (int i = 0; i < 4; ++i) {
        if (count[i] > 0) {
            distinColor++;
        }
    }

    if (distinColor == 3) {
        cout << "Three" << endl;
    }

    if (distinColor == 4) {
        cout << "Four" << endl;
    }

    return 0;
}
