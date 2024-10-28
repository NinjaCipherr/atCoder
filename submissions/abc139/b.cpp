#include <bits/stdc++.h>

#include <vector>

using namespace std;

int main() {
    int a, b;

    cin >> a >> b;
    int required = b - 1;
    int extend = a - 1;
    int count = (required + extend - 1) / extend;

    cout << count << endl;
    return 0;
}