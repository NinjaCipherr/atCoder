#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W, K;
    cin >> H >> W >> K;
    vector<string> grid(H);
    for (int i = 0; i < H; i++) {
        cin >> grid[i];
    }

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int result = 0;

    function<void(int, int, int, vector<vector<bool>>&)> dfs = [&](int x, int y, int steps, vector<vector<bool>>& visited) {
        if (steps == K) {
            result++;
            return;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && grid[nx][ny] == '.') {
                visited[nx][ny] = true;
                dfs(nx, ny, steps + 1, visited);
                visited[nx][ny] = false;
            }
        }
    };

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == '.') {
                vector<vector<bool>> visited(H, vector<bool>(W, false));
                visited[i][j] = true;
                dfs(i, j, 0, visited);
            }
        }
    }

    cout << result << endl;
    return 0;
}
