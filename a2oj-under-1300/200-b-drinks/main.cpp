#include <iostream>
#include <vector>

using namespace std;

// https://codeforces.com/problemset/problem/200/B
int main()
{
    int n;
    cin >> n;

    double sum = 0.0;

    for (int i = 0; i < n; i++) {
        double k;
        cin >> k;
        sum += k;
    }

    cout << sum / static_cast<double>(n);
}