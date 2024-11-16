#include <bits/stdc++.h>

using namespace std;

int main() {
    int sum1 = 0;
    int sum2 = 0;
    int element;
    for (int i = 0; i < 9; i++) {
        cin >> element;
        sum1 = sum1 + element;
    }

    for (int i = 0; i < 8; i++) {
        cin >> element;
        sum2 += element;
    }
    if (sum2 > sum1) {
        cout << 0;
    } else {
        cout << (sum1 - sum2 + 1);
    }
    return 0;
}
