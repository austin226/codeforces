// https://codeforces.com/problemset/problem/1912/L

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

int main() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  auto is_onion = [](char c) { return c == 'O' ? 1 : 0; };
  vector<int> onion_prefix_sum(n);
  vector<int> onion_suffix_sum(n);
  transform_inclusive_scan(s.begin(), s.end(), onion_prefix_sum.begin(),
                           std::plus<int>{}, is_onion);
  transform_inclusive_scan(s.rbegin(), s.rend(), onion_suffix_sum.rbegin(),
                           std::plus<int>{}, is_onion);

  F(k, 1, n) {
    int my_onions = onion_prefix_sum[k - 1];
    int your_onions = onion_suffix_sum[k];
    int my_loaves = k - my_onions;
    int your_loaves = (n - k) - your_onions;
    // cout << "k=" << k << ", my_o=" << my_onions << ",your_o=" << your_onions
        //  << ",my_l=" << my_loaves << ",your_l=" << your_loaves << endl;
    if ((my_onions != your_onions) && (my_loaves != your_loaves)) {
      cout << k << endl;
      return 0;
    }
  }

  cout << -1 << endl;
}