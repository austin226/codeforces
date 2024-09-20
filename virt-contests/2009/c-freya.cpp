// https://codeforces.com/contest/2009/problem/C

#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

void solve() {
    int x, y, k;
    cin >> x >> y >> k;

    int xk = (int)ceil(x / (float)k);
    int yk = (int)ceil(y / (float)k);
    
    int sum;
    if (yk >= xk) {
        sum = 2 * yk;
    } else {
        sum = 2 * xk - 1;
    }
    
    std::cout << sum << endl;
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }
}