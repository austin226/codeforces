#include <iostream>

using namespace std;

constexpr int primes[] = {
    2,3,5,7,11,13,17,19,23,29,31,37,41,43,47
};
constexpr int n_primes = sizeof(primes) / sizeof(int);

bool check(int n, int m) {
    for (int k = 0; k < n_primes-1; k++) {
        if (primes[k] == n) {
            return primes[k+1] == m;
        }
    }
    return false;
}

// https://codeforces.com/problemset/problem/80/A
int main()
{
    int n, m;
    cin >> n >> m;

    if (check(n,m)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}