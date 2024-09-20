// https://codeforces.com/contest/2009/problem/B

#include <iostream>
#include <stack>

using namespace std;

int parse_line(string line) {
    if (line == "#...") return 1;
    if (line == ".#..") return 2;
    if (line == "..#.") return 3;
    if (line == "...#") return 4;
    return -1;
}

void solve() {
    int n;
    cin >> n;

    stack<int> st;
    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        st.push(parse_line(line));
    }

    for (int i = 0; i < n; i++) {
        cout << st.top();
        st.pop();
        if (i < n - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }
}