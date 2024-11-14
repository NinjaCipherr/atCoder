#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int a = N / 100;
    int b = (N / 10) % 10;
    int c = N % 10;

    int first = b * 100 + c * 10 + a;
    int second = c * 100 + a * 10 + b;

    cout << first << " " << second << endl;

    return 0;
}
