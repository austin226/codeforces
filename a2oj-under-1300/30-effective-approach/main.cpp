#include <iostream>
#include <map>

using namespace std;

// https://codeforces.com/problemset/problem/227/B
int main()
{
    // number of elements in the array
    // 1 <= n <= 10^5
    int n;
    cin >> n;

    // Map of value locations in the array
    map<int, size_t> locations;

    // Read in the array of values and store their locations
    // Array contains n distinct integers, where 1 <= a[i] <= n
    for (size_t i = 0; i < n; i++)
    {
        int a_i;
        cin >> a_i;
        locations[a_i] = i;
    }

    // Number of queries
    // 1 <= m <= 10^5
    // Queries can repeat
    int m;
    cin >> m;

    long long int forward_sum = 0;
    long long int backward_sum = 0;

    // Read in m queries.
    // For each query:
    // Find out how many comparisons are needed for each approach:
    // 1. start with the first element and proceed to the end
    // 2. start with the last element and go to the start
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