
#include <bits/stdc++.h>

#include <iostream>
#include <vector>

using namespace std;
int main() {
    vector<string> broad(8);
    for (int i = 0; i < 8; ++i) {
        cin >> broad[i];
    }
    bool row[8] = {false};
    bool col[8] = {false};
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; ++j) {
            if (broad[i][j] == '#') {
                row[i] = true;
                col[j] = true;
            }
        }
    }

    int count = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; ++j) {
            if (broad[i][j] == '.' && !row[i] && !col[j]) {
                count++;
            }
        }
    }
    cout << count;
    return 0;
}
