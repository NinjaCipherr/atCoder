#include <iostream>
using namespace std;

int main() {
    int A1, A2, A3, A4;
    cin >> A1 >> A2 >> A3 >> A4;

    int color_counts[5] = {0};
    color_counts[A1]++;
    color_counts[A2]++;
    color_counts[A3]++;
    color_counts[A4]++;

    int max_operations = 0;
    for (int i = 1; i <= 4; i++) {
        max_operations += color_counts[i] / 2;
    }

    cout << max_operations << endl;

    return 0;
}
