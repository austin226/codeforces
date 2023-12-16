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

vector<pair<char, int>> largest_subseq(vector<vector<int>> &letter_pos,
                                       int after_pos, char latest_letter) {
  vector<pair<char, int>> subseq;
  int latest_pos = -1;
  for (char g = latest_letter; g >= 'a' && latest_pos == -1; g--) {
    int letter_val = g - 'a';
    vector<int> letter_q = letter_pos[letter_val];
    F(i, 0, letter_q.size()) {
      // TODO optimize with binary search
      if (letter_q[i] > after_pos) {
        // add to subseq
        subseq.pb({g, letter_q[i]});
        latest_pos = letter_q[i];
      }
    }
  }
  if (latest_pos != -1) {
    vector<pair<char, int>> subseq2 =
        largest_subseq(letter_pos, latest_pos, latest_letter - 1);
    for (auto &a : subseq2) {
      subseq.pb(a);
    }
  }
  return subseq;
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

    vector<vector<int>> letter_pos;
    for (char g = 'a'; g <= 'z'; g++) {
      vector<int> pos_q;
      letter_pos.push_back(pos_q);
    }

    F(i, 0, s.length()) {
      char c = s[i];
      char letter_index = c - 'a';
      letter_pos[letter_index].pb(i);
      // cout << "Insert " << c << " at " << i << endl;
    }

    // Get last letter's first position
    vector<pair<char, int>> subseq = largest_subseq(letter_pos, -1, 'z');

    for (auto &p : subseq) {
      cout << "(" << p.first << "," << p.second << ")" << endl;
    }
  }
}