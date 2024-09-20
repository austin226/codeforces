// https://codeforces.com/contest/2009/problem/A

#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        cout << b - a << endl;
    }
}