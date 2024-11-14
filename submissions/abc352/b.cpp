#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string S, T;
    cin >> S >> T;

    vector<int> result;
    int s_index = 0;

    for (int t_index = 0; t_index < T.size(); ++t_index) {
        if (s_index < S.size() && T[t_index] == S[s_index]) {
            result.push_back(t_index + 1);
            s_index++;
        }
    }

    for (int i = 0; i < result.size(); ++i) {
        if (i > 0) cout << " ";
        cout << result[i];
    }
    cout << endl;

    return 0;
}
