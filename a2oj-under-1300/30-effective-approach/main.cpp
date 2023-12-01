#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// https://codeforces.com/problemset/problem/227/B
int main()
{
    // number of values
    int n;
    cin >> n;

    // Map of value locations
    map<int, size_t> locations;

    // array of values
    for (size_t i = 0; i < n; i++)
    {
        int a_i;
        cin >> a_i;
        locations[a_i] = i;
    }

    // number of queries
    int m;
    cin >> m;

    // For each query:
    // Find out how many comparisons are needed for each approach:
    // 1. start with the first element and proceed to the end
    // 2. start with the last element and go to the start
    int forward_sum = 0;
    int backward_sum = 0;

    for (int i = 0; i < m; i++)
    {
        int needle;
        cin >> needle;

        size_t loc = locations[needle];
        forward_sum += loc + 1;
        backward_sum += (n - loc);
    }

    cout << forward_sum << ' ' << backward_sum << endl;
}