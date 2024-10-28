#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    unordered_set<long long> rows, cols, diag1, diag2;

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    long long free_cells = 0;

    for (long long i = 1; i <= N; ++i) {
        for (long long j = 1; j <= N; ++j) {
            if (rows.find(i) == rows.end() &&
                cols.find(j) == cols.end() &&
                diag1.find(i + j) == diag1.end() &&
                diag2.find(i - j) == diag2.end()) {
                free_cells++;
            }
        }
    }

    cout << free_cells << endl;
    return 0;
}
