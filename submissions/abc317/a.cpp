#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, H, X;
    cin >> N >> H >> X;

    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    for (int i = 0; i < N; i++) {
        if (H + P[i] >= X) {
            cout << (i + 1) << endl;  // Chỉ số bắt đầu từ 1
            break;                    // Ngừng tìm kiếm sau khi tìm thấy thuốc đầu tiên thỏa mãn
        }
    }

    return 0;
}
