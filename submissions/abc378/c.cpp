#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N + 1);
    vector<int> B(N + 1, -1);
    unordered_map<int, int> last_position;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];

        if (last_position.count(A[i])) {
            B[i] = last_position[A[i]];
        } else {
            B[i] = -1;
        }

        last_position[A[i]] = i;
    }

    for (int i = 1; i <= N; i++) {
        cout << B[i] << " ";
    }
    cout << endl;

    return 0;
}
