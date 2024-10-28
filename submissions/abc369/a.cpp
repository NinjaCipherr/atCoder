
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int count = 0;
    if (abs(a - 3) == abs(b - 3)) {
        count++;
    }
    if (abs(a - 6) == abs(b - 6)) {
        count++;
    }
    if (abs(a - 9) == abs(b - 9)) {
        count++;
    }
    cout << count;
    return 0;
}
