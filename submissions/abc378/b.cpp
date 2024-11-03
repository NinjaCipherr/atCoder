#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> q(N + 1), r(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> q[i] >> r[i];
    }

    int Q;
    cin >> Q;

    while (Q--) {
        int t, d;
        cin >> t >> d;

        int qi = q[t];
        int ri = r[t];

        if (d % qi == ri) {
            cout << d << endl;
        } else {
            int next_collect_day = d + (ri - d % qi + qi) % qi;
            cout << next_collect_day << endl;
        }
    }

    return 0;
}
