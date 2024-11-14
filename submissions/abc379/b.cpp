#include <iostream>
#include <string>
using namespace std;

int main() {
    int N, K;
    string S;
    cin >> N >> K >> S;

    int count = 0;
    for (int i = 0; i <= N - K; i++) {
        bool canEat = true;
        for (int j = i; j < i + K; j++) {
            if (S[j] == 'X') {
                canEat = false;
                break;
            }
        }
        if (canEat) {
            count++;
            for (int j = i; j < i + K; j++) {
                S[j] = 'X';
            }
        }
    }

    cout << count << endl;
    return 0;
}
