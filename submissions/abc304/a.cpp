#include <bits/stdc++.h>

#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> age(n);
    vector<string> name(n);
    for (int i = 0; i < n; ++i) {
        cin >> name[i] >> age[i];
    }
    int minIndex = 0;
    for (int i = 0; i < n; ++i) {
        if (age[i] < age[minIndex])
            minIndex = i;
    }
    for (int i = minIndex; i < n; ++i) {
        cout << name[i] << endl;
        ;
    }

    for (int i = 0; i < minIndex; ++i) {
        cout << name[i] << endl;
    }
    return 0;
}
