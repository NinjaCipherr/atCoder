#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> count(M + 1, 0);
    vector<bool> valid_range(M + 1, true);

    for (int i = 0; i < N; ++i) {
        int L, R;
        cin >> L >> R;
        valid_range[L]++;
        if (R + 1 <= M) {
            valid_range[R + 1]--;
        }
    }

    for (int i = 1; i <= M; ++i) {
        valid_range[i] += valid_range[i - 1];
        if (valid_range[i] > 0) {
            valid_range[i] = false;
        } else {
            valid_range[i] = true;
        }
    }

    for (int i = 1; i <= M; ++i) {
        count[i] = count[i - 1] + valid_range[i];
    }

    long long result = 0;
    for (int l = 1; l <= M; ++l) {
        if (valid_range[l]) {
            result += count[M] - count[l - 1];
        }
    }

    cout << result << endl;
    return 0;
}
