// https://codeforces.com/contest/144/problem/A

#include <algorithm>
#include <iostream>
#include <limits>

using namespace std;

int main()
{
    // A correct line-up is where the first item is max and last is min
    // Count the number of swaps needed to make a line match this rule

    // 2 <= n <= 100
    int n_soldiers = 3;
    cin >> n_soldiers;

    int min_index = -1;
    int min_height = numeric_limits<int>::max();
    int max_index = -1;
    int max_height = numeric_limits<int>::min();
    for (int i = 0; i < n_soldiers; i++)
    {
        // Each input is a soldier's height , in [1..=100]. Heights may repeat.
        int height;
        cin >> height;

        // We want the leftmost max - use strict >
        if (height > max_height)
        {
            max_height = height;
            max_index = i;
        }

        // We want the rightmost min - use <=
        if (height <= min_height)
        {
            min_height = height;
            min_index = i;
        }
    }

    // Number of swaps
    int n_swaps = max_index + (n_soldiers - 1 - min_index);
    if (max_index > min_index)
    {
        // We get one move for free if max is to the right of min
        n_swaps--;
    }
    cout << n_swaps << endl;
}