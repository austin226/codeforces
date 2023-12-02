#include <iostream>
#include <map>

using namespace std;

// https://codeforces.com/problemset/problem/237/A
int main()
{
    // Speed up iostream since we don't use stdio
    std::ios::sync_with_stdio(false);

    // number of cafe visitors
    // 1 <= n <= 10^5
    int n_visitors;
    cin >> n_visitors;

    // Get the time each visitor will arrive
    int registers = 1;
    map<int, int> time_frequencies;
    for (int i = 0; i < n_visitors; i++)
    {
        // Each line has h_i and m_i
        // 0 <= h_i <= 23
        int h_i;
        cin >> h_i;

        // 0 <= m_i <= 59
        int m_i;
        cin >> m_i;

        // 0 <= minutes <= 1439
        int minutes = 60 * h_i + m_i;

        auto freq = time_frequencies.find(minutes);
        if (freq == time_frequencies.end())
        {
            // First client with this time
            time_frequencies[minutes] = 1;
        }
        else
        {
            // Multiple clients have this time
            int new_freq = freq->second + 1;
            if (new_freq > registers)
            {
                // This is the most popular time - add a cash register
                registers = new_freq;
            }
            freq->second = new_freq;
        }
    }

    // Return the number of cash registers needed to ensure no client ever has to wait
    cout << registers << endl;
}
