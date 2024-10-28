#include <iostream>
using namespace std;

int main() {
    int Y;
    cin >> Y;  // Nhập năm Y

    // Kiểm tra năm nhuận theo các quy tắc đã cho
    if (Y % 4 == 0) {
        if (Y % 100 == 0) {
            if (Y % 400 == 0) {
                cout << 366 << endl;  // Năm 400, 366 ngày
            } else {
                cout << 365 << endl;  // Năm 100 nhưng không phải 400, 365 ngày
            }
        } else {
            cout << 366 << endl;  // Năm 4 nhưng không phải 100, 366 ngày
        }
    } else {
        cout << 365 << endl;  // Năm không phải là năm nhuận, 365 ngày
    }

    return 0;
}
