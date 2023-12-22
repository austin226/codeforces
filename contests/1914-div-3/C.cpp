// https://codeforces.com/contest/1914/problem/c

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

#pragma region IO

template <typename T, typename TT>
ostream& operator<<(ostream& s, pair<T, TT> t) {
  return s << "(" << t.first << "," << t.second << ")";
}
template <typename T>
ostream& operator<<(ostream& s, vector<T> t) {
  F(i, 0, SZ(t)) s << t[i] << " ";
  return s;
}

#pragma endregion

void testcase() {
  int n, k;
  cin >> n >> k;

  vi a(n), b(n);
  F(i, 0, n) { cin >> a[i]; }
  F(i, 0, n) { cin >> b[i]; }

  int always_took_a = 0;
  int greedy = 0;
  int max_b = 0;
  int max_b_unlocked = 0;
  int greedy_last_quest = 0;
  F(i, 0, k) {
    if (i > 0 && i <= n) {
      max_b = max(max_b, b[i - 1]);
      if (greedy_last_quest >= i - 1) {
        max_b_unlocked = max_b;
      }
    }
    greedy += max_b_unlocked;

    if (i < n) {
      always_took_a += a[i];
    } else {
      always_took_a += max_b;
    }

    if (always_took_a > greedy) {
      greedy = always_took_a;
      greedy_last_quest = i;
    }
  }

  std::cout << greedy << endl;
}

int main() {
  int t;
  cin >> t;
  F(i, 0, t) testcase();
}