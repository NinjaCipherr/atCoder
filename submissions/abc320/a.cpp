#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int result = pow(a, b) + pow(b, a);
    cout << result;
    return 0;
}
