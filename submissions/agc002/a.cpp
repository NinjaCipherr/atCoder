#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    // Nếu khoảng chứa 0 thì kết quả là "Zero"
    if (a <= 0 && b >= 0)
        cout << "Zero";
    // Nếu tất cả các số đều dương, kết quả là "Positive"
    else if (a > 0)
        cout << "Positive";
    // Nếu tất cả các số đều âm, kiểm tra số lẻ hay chẵn số âm
    else
        cout << ((b - a + 1) % 2 ? "Negative" : "Positive");

    return 0;
}
