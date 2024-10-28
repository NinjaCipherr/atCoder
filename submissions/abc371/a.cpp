#include <bits/stdc++.h>

#include <iostream>
#include <vector>

using namespace std;

int main() {
    char ab, ac, bc;
    cin >> ab >> ac >> bc;
    char people[3] = {'a', 'b', 'c'};
    char temp;
    if (ab == '>') {
        temp = people[0];
        people[0] = people[1];
        people[1] = temp;
    }
    if (ac == '>') {
        temp = people[0];
        people[0] = people[2];
        people[2] = temp;
    }

    if (bc == '>') {
        temp = people[1];
        people[1] = people[2];
        people[2] = temp;
    }
    cout << people[1] << endl;

    return 0;
}
