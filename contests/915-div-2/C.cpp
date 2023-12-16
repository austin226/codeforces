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

vector<pair<char, int>> largest_subseq(vector<set<int>> &letter_pos,
                                       int after_pos, char latest_letter) {
  vector<pair<char, int>> subseq;
  int latest_pos = -1;
  for (char g = latest_letter; g >= 'a' && latest_pos == -1; g--) {
    int letter_val = g - 'a';
    set<int> letter_q = letter_pos[letter_val];
    // TODO optimize with binary search
    for (auto it = letter_q.begin(); it != letter_q.end(); it++) {
      if (*it > after_pos) {
        // add to subseq
        subseq.pb({g, *it});
        latest_pos = *it;
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

vector<pair<char, int>> right_shift(vector<pair<char, int>> &subseq) {
  vector<pair<char, int>> new_subseq;
  pair<char, int> rightmost = subseq[subseq.size() - 1];
  new_subseq.pb({rightmost.first, subseq[0].second});

  for (int i = subseq.size() - 1; i > 0; i--) {
    new_subseq.pb({subseq[i - 1].first, subseq[i].second});
  }
  return new_subseq;
}

int first_unsorted_idx(string &s, string &sorted_s, int at_least) {
  F(i, at_least, s.length()) {
    if (s[i] != sorted_s[i]) {
      return i;
    }
  }
  return -1;
}

void update_str(string &s, vector<pair<char, int>> &subseq) {
  for (auto &p : subseq) {
    s[p.second] = p.first;
  }
}

void update_letter_pos(vector<set<int>> &letter_pos,
                       vector<pair<char, int>> &old_subseq,
                       vector<pair<char, int>> &new_subseq) {
  for (auto &p : old_subseq) {
    int letter_val = p.first - 'a';
    set<int> letter_q = letter_pos[letter_val];
    letter_q.erase(p.second);
  }
  for (auto &p : new_subseq) {
    int letter_val = p.first - 'a';
    set<int> letter_q = letter_pos[letter_val];
    letter_q.insert(p.second);
  }
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

    vector<set<int>> letter_pos;
    for (char g = 'a'; g <= 'z'; g++) {
      set<int> pos_q;
      letter_pos.pb(pos_q);
    }

    F(i, 0, s.length()) {
      char c = s[i];
      char letter_index = c - 'a';
      letter_pos[letter_index].insert(i);
      // cout << "Insert " << c << " at " << i << endl;
    }

    string sorted_s = s;
    sort(sorted_s.begin(), sorted_s.end());

    int operations = 0;
    int first_unsorted = first_unsorted_idx(s, sorted_s, 0);

    while (first_unsorted != -1) {
      vector<pair<char, int>> subseq = largest_subseq(letter_pos, -1, 'z');

      vector<pair<char, int>> new_subseq = right_shift(subseq);
      update_letter_pos(letter_pos, subseq, new_subseq);
      update_str(s, new_subseq);
      operations++;
      first_unsorted = first_unsorted_idx(s, sorted_s, 0);
      // if (operations > 5) {
      //   break;
      // }
      // cout << "old" << endl;
      // for (auto &p : subseq) {
      //   cout << "(" << p.first << "," << p.second << ") ";
      // }
      // cout << endl;
      // cout << "new" << endl;
      // for (auto &p : new_subseq) {
      //   cout << "(" << p.first << "," << p.second << ") ";
      // }
      // cout << endl;
    }
    cout << operations << endl;

    // TODO handle not possible
  }
}