#include <iostream>
#include <string>
#include <vector>

using namespace std;

// https://codeforces.com/problemset/problem/227/B
int main()
{
    // number of values
    int n;
    cin >> n;

    // array of values
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // number of queries
    int m;
    cin >> m;

    // array of queries
    vector<int> b(m);
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    int forward_sum = 0;
    int backward_sum = 0;
    for (int i = 0; i < m; i++)
    {
        // TODO
        // Find out how many comparisons are needed for each apporoach:
        // 1. start with the first element and proceed to the end
        // 2. start with the last element and go to the start
    }

    cout << forward_sum << ' ' << backward_sum << endl;
}