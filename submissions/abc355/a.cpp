#include <iostream>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    if (A == B) {
        cout << -1 << endl;
    } else {
        for (int i = 1; i <= 3; ++i) {
            if (i != A && i != B) {
                cout << i << endl;
                return 0;
            }
        }
    }

    return 0;
}
