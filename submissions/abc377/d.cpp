#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> L(N), R(N);
    for (int i = 0; i < N; ++i) {
        cin >> L[i] >> R[i];
    }

    vector<int> valid_left(M + 1, 1);

    for (int i = 0; i < N; ++i) {
        if (R[i] <= M) {
            valid_left[R[i]] = max(valid_left[R[i]], L[i] + 1);
        }
    }

    for (int i = 1; i <= M; ++i) {
        valid_left[i] = max(valid_left[i], valid_left[i - 1]);
    }

    long long result = 0;
    for (int r = 1; r <= M; ++r) {
        result += r - valid_left[r] + 1;
    }

    cout << result << endl;

    return 0;
}
