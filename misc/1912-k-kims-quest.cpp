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

#pragma endregion

#define M 998244353
typedef std::unordered_map<std::string, std::vector<std::string>> SubseqMem;
typedef unordered_map<string, ull> FMem;

// (O(n^2))
// Returns a vector, size n-1
// Subsequences will always be at least 3 chars
vector<string> subsequences_one_shorter(string s, int n, SubseqMem& mem) {
  if (n == 3) {
    return vector<string>();
  }

  if (mem.contains(s)) {
    return mem[s];
  }

  vector<string> res(n);
  F(i, 0, n) {
    stringstream ss;
    F(j, 0, n) {
      if (i != j) {
        ss << s[j];
      }
    }
    res[i] = ss.str();
  }
  mem[s] = res;
  return res;
}

ull f(string& s, SubseqMem& subseq_mem, FMem& f_mem) {
  if (s.length() < 3) {
    return 0;
  } else if (s.length() == 3) {
    return s != "111";
  }
  if (f_mem.contains(s)) {
    return f_mem[s];
  }

  ull result = 0;

  // Check each subsequence
  for (auto& subseq : subsequences_one_shorter(s, s.length(), subseq_mem)) {
    if (subseq.length() < 3) {
      continue;
    }
    ull subseq_f = f(subseq, subseq_mem, f_mem);
    cout << "f(" << subseq << ")=" << subseq_f << endl;
    result = (result + subseq_f) % M;
  }

  f_mem[s] = result;
  return result;
}

// https://codeforces.com/problemset/problem/1912/K
int main() {
  int n;
  cin >> n;

  stringstream ss;
  F(i, 0, n) {
    int b;
    cin >> b;
    ss << (b & 1) ? '1' : '0';
  }
  string a = ss.str();

  SubseqMem subseq_mem;
  FMem f_mem;
  ull ans = f(a, subseq_mem, f_mem);

  cout << ans << endl;
}