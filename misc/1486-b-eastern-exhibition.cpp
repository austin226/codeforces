#include <algorithm>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <optional>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <string_view>
#include <type_traits>
#include <unordered_map>
#include <vector>

using namespace std;

#define F(i, L, R) for (int i = L; i < R; i++)
#define STR_CONTAINS(s1, s2) s1.find(s2) != std::string::npos

#define SZ(x) ((int)((x).size()))
#define SORT_VEC(vec) std::sort(vec.begin(), vec.end())
#define VEC_MIN(vec) std::min_element(vec.begin(), vec.end())
#define VEC_MAX(vec) std::max_element(vec.begin(), vec.end())
#define COPY_VEC(vec1, vec2) \
  std::copy(vec1.begin(), vec1.end(), vec2.begin(), vec2.end())
#define pb push_back

#define MIN_MAX(a, b) std::tuple(std::min(a, b), std::max(a, b))
#define PI 3.1415926535897932384626

#define _N_TYPE_MIN(T) std::numeric_limits<T>::min()
#define _N_TYPE_MAX(T) std::numeric_limits<T>::max()

#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define us unsigned short

typedef pair<int, int> ii;
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

// https://codeforces.com/problemset/problem/1486/B

ull testcase() {
  int n;
  cin >> n;

  vector<ull> x(n);
  vector<ull> y(n);
  F(i, 0, n) { cin >> x[i] >> y[i]; }

  if (n <= 1) {
    return 1;
  }

  // According to https://codeforces.com/blog/entry/87849, we should already
  // know: Every point with the smallest summary distance is between left and
  // right median. So we sort the array, then find elements on positions
  // floor((n+1)/2) and floor((n+2)/2), then return their difference plus one.
  SORT_VEC(x);
  ull factor_x = (ull)x[(n + 2) / 2 - 1] - (ull)x[(n + 1) / 2 - 1] + 1;

  SORT_VEC(y);
  ull factor_y = (ull)y[(n + 2) / 2 - 1] - (ull)y[(n + 1) / 2 - 1] + 1;
  return factor_x * factor_y;
}

int main() {
  int t;
  cin >> t;

  F(t_i, 0, t) {
    ull ans = testcase();
    cout << ans << endl;
  }
}