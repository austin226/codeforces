#include <iostream>

using namespace std;


// https://codeforces.com/problemset/problem/266/A
int main()
{
    int n;
    string s;
    cin >> n >> s;

    int i = 0;
    int res = 0;
    while (i < n) {
        int j = i + 1;
        for (; j < n; j++) {
            if (s[i] != s[j]) {
                break;
            }
            res++;
        }
        i = j;
    }

    cout << res << endl;
}