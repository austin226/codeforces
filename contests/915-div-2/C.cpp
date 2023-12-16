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

// https://codeforces.com/contest/1905/problem/C
int main() {
  int t;
  cin >> t;

  F(t_i, 0, t) {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<queue<int>> letter_pos;
    for (char g = 'a'; g <= 'z'; g++) {
      queue<int> pos_q;
      letter_pos.push_back(pos_q);
    }

    F(i, 0, s.length()) {
      char c = s[i];
      char letter_index = c - 'a';
      letter_pos[letter_index].push(i);
      // cout << "Insert " << c << " at " << i << endl;
    }

    // Get last letter's first position
    vector<pair<char, int>> subseq;
    for (char g = 'z'; g >= 'a'; g--) {
      int letter_index = g - 'a';
      queue<int> letter_q = letter_pos[letter_index];
      while (letter_q.size() > 0) {
        int pos = letter_q.front();
        subseq.push_back({g, pos});
        letter_q.pop();
      }
      // TODO i don't want a q, i want a bst of positions
    }

    cout << subseq << endl;
  }
}