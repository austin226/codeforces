// https://codeforces.com/problemset/problem/136/A
#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <optional>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define us unsigned short

#define pb push_back

#define F(i, L, R) for (int i = L; i < R; i++)
#define SZ(x) ((int)((x).size()))

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

template <typename T, typename TT>
ostream& operator<<(ostream& s, pair<T, TT> t) {
  return s << "(" << t.first << "," << t.second << ")";
}
template <typename T>
ostream& operator<<(ostream& s, vector<T> t) {
  F(i, 0, SZ(t)) s << t[i] << " ";
  return s;
}

int main() {
  us n;
  cin >> n;

  vi p(n);
  F(i, 0, n) {
    us p_i;
    cin >> p_i;
    p[p_i - 1] = i + 1;
  }

  cout << p << endl;
}