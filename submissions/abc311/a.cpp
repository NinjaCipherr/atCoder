#include <bits/stdc++.h>

#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> vec(3, 0);
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == 'A') {
            vec[0]++;
        }
        if (s[i] == 'B') {
            vec[1]++;
        }
        if (s[i] == 'C') {
            vec[2]++;
        }
        if (vec[0] > 0 && vec[1] > 0 && vec[2] > 0) {
            cout << i + 1;
            break;
        }
    }

    return 0;
}
