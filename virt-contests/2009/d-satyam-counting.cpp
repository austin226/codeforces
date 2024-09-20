// https://codeforces.com/contest/2009/problem/D

#include <algorithm>
#include <iostream>
#include <stack>
#include <cmath>
#include <map>
#include <set>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<bool> row0;
    row0.resize(n);
    std::fill(row0.begin(), row0.end(), false);

    vector<bool> row1(n, false);
    row1.resize(n);
    std::fill(row1.begin(), row1.end(), false);

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        if (y == 0) {
            row0[x] = true;
        } else {
            row1[x] = true;
        }
    }

    long long sum = 0;

    // Find any x with y=0 and y=1
    for (int x = 0; x < n; x++) {
        if (row0[x] && row1[x]) {
            // A triangle can be formed for each other point
            sum += (n - 2);
        }
        if (x + 2 < n && row0[x] && row1[x+1] && row0[x+2]) {
            sum++;
        }
        if (x + 2 < n && row1[x] && row0[x+1] && row1[x+2]) {
            sum++;
        }
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