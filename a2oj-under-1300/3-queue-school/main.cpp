// https://codeforces.com/problemset/problem/266/B
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n, t;
    string queue;
    cin >> n >> t >> queue;
    
    for (int x = 0; x < t; x++) {
        std::vector<int> swaps;
        for (int i = 0; i < n-1; i++) {
            if (queue[i] == 'B' && queue[i+1] == 'G') {
                swaps.push_back(i);
            }
        }
        for (auto i : swaps) {
            queue[i] = 'G';
            queue[i+1] = 'B';
        }
    }
    
    cout << queue << endl;
}
