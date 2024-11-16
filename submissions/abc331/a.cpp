#include <bits/stdc++.h>

using namespace std;

int main() {
    int M, D;
    cin >> M >> D;

    int y, m, d;
    cin >> y >> m >> d;

    if (d + 1 > D) {
        d = 1;
        if (m + 1 > M) {
            y = y + 1;
            m = 1;
        } else {
            m = m + 1;
        }
    } else {
        d = d + 1;
    }
    cout << y << " " << m << " " << d << endl;
    return 0;
}
