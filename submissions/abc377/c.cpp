
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    long long N;
    int M;
    cin >> N >> M;

    set<pair<int, int>> occupied;

    vector<pair<int, int>> directions = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        occupied.insert({a, b});

        for (auto dir : directions) {
            int x = a + dir.first;
            int y = b + dir.second;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                occupied.insert({x, y});
            }
        }
    }

    long long total_cells = N * N;
    long long occupied_count = occupied.size();
    long long result = total_cells - occupied_count;

    cout << result << endl;

    return 0;
}
