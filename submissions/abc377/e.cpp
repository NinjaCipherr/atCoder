#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    long long K;
    cin >> N >> K;
    vector<int> P(N), result(N);

    for (int i = 0; i < N; ++i) {
        cin >> P[i];
        P[i]--;  // Đưa về 0-index để dễ làm việc
    }

    // Tìm chu kỳ cho mỗi vị trí
    vector<vector<int>> cycles(N);
    vector<bool> visited(N, false);

    for (int i = 0; i < N; ++i) {
        if (!visited[i]) {
            vector<int> cycle;
            int current = i;
            while (!visited[current]) {
                visited[current] = true;
                cycle.push_back(current);
                current = P[current];
            }
            for (int j : cycle) cycles[j] = cycle;
        }
    }

    // Xác định vị trí cuối cùng của từng phần tử
    for (int i = 0; i < N; ++i) {
        const vector<int>& cycle = cycles[i];
        int cycle_length = cycle.size();
        int final_pos = cycle[(K % cycle_length)];  // Sử dụng dư để tối ưu hóa
        result[i] = final_pos + 1;                  // Trả về 1-index
    }

    // Xuất kết quả
    for (int i = 0; i < N; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
