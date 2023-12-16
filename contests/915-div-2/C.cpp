#include <algorithm>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
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

vector<int> lex_largest_subseq(string &s, int n) {
  vector<int> subseq;
  F(i, 1, n + 1) {
    while (!subseq.empty() && s[subseq.back()] < s[i]) {
      // subseq ends with a letter smaller than the current letter
      // Remove that letter
      subseq.pop_back();
    }
    // Add the current letter to subseq
    subseq.push_back(i);
  }
  return subseq;
}

// length of the largest prefix of equal values
int eq_prefix_len(string &s, vector<int> &subseq) {
  int ans = 0;
  while (ans < subseq.size() && s[subseq[ans]] == s[subseq[0]]) {
    ans++;
  }
  return subseq.size() - ans;
}

void swap_letters(string &s, vector<int> &subseq) {
  int m = (int)subseq.size() - 1;
  F(i, 0, m + 1) {
    if (i < m - i) {
      swap(s[subseq[i]], s[subseq[m - i]]);
    }
  }
}

bool is_sorted(string &s, int n) {
  F(i, 2, n + 1) {
    if (s[i] < s[i - 1]) {
      return false;
    }
  }
  return true;
}

// https://codeforces.com/contest/1905/problem/C
int main() {
  int t;
  cin >> t;

  F(t_i, 0, t) {
    int n;
    cin >> n;

    string s;
    cin >> s;

    // Shift s right by 1
    s = '$' + s;

    vector<int> subseq = lex_largest_subseq(s, n);
    int ans = eq_prefix_len(s, subseq);
    swap_letters(s, subseq);

    if (is_sorted(s, n)) {
      cout << ans << endl;
    } else {
      cout << -1 << endl;
    }
  }
}