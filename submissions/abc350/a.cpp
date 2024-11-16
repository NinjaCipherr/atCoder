#include <bits/stdc++.h>

#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    string check = "";
    for (int i = 3; i < 6; ++i) {
        check = check + s[i];
        if (check == "316") {
            cout << "No" << endl;
            return 0;
        }
    }
    int checkNum = stoi(check);
    if (1 > checkNum or checkNum > 349) {
        cout << "No";
        return 0;
    }
    cout << "Yes";
    return 0;
}
