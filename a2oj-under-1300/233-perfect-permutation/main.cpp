#include <iostream>

using namespace std;

// https://codeforces.com/problemset/problem/233/A
int main()
{
    int n;
    cin >> n;

    if (n % 2 == 1) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 1; i < n; i += 2) {
        if (i > 1) cout << " ";
        cout << i + 1 << " " << i;
    }
    cout << endl;
}