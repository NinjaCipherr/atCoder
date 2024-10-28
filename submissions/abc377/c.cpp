#include <iostream>
#include <set>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    set<pair<int, int>> occupied;

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        occupied.insert({a, b});

        pair<int, int> potential_moves[] = {
            {a + 2, b + 1},
            {a + 1, b + 2},
            {a - 1, b + 2},
            {a - 2, b + 1},
            {a - 2, b - 1},
            {a - 1, b - 2},
            {a + 1, b - 2},
            {a + 2, b - 1}};

        for (auto move : potential_moves) {
            if (move.first >= 1 && move.first <= N && move.second >= 1 && move.second <= N) {
                occupied.insert(move);
            }
        }
    }

    int total_cells = N * N;
    int occupied_count = occupied.size();
    int result = total_cells - occupied_count;

    cout << result << endl;

    return 0;
}
