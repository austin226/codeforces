// https://codeforces.com/blog/entry/123160

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

using namespace std;

#define SORT_VEC(vec) std::sort(vec.begin(), vec.end())

struct TestCase {
  uint16_t n;
  uint32_t k;
  vector<uint64_t> a;
  uint64_t min_element;
};

uint64_t solve(TestCase &tc) {
  if (tc.k >= 3) {
    // After operating on the same pair (i.j) twice, operating on the two new
    // (identical) values results in 0.
    return 0;
  } else if (tc.k == 1) {
    // Sort array and output min(a[i], a[i+1]-a[i])
    SORT_VEC(tc.a);
    uint64_t ans = tc.a[0];
    for (uint16_t i = 0; i < tc.n - 1; i++) {
      uint64_t diff = tc.a[i + 1] - tc.a[i];
      if (diff < ans) {
        ans = diff;
      }
    }
    return ans;
  } else {
    // k == 2
    // Brute force the operation.
    // v = |a[i]-a[j]|
    // If newly created value is v, find smallest
    // a[i] satisfying a[i] >= v and greatest a[i] satisfying a[i] <= v. Relax
    // the answer on |a[i] - v|. Consider cases of no operation or one
    // operation. Runs in O(n^2 log n).

    // TODO unclear how to solve this yet
    return -1;
  }
}

int main() {
  // t in 1..=1000
  uint16_t t;
  cin >> t;

  vector<TestCase> tcs;
  tcs.reserve(t);
  for (uint16_t t_i = 0; t_i < t; t_i++) {
    // n in 2..=2000
    uint16_t n;
    cin >> n;

    // k in 1..=1,000,000,000
    uint32_t k;
    cin >> k;

    // n integers. each in 1..10^18
    vector<uint64_t> a;
    a.reserve(n);
    uint64_t min_element = numeric_limits<uint64_t>::max();
    for (uint16_t n_i = 0; n_i < n; n_i++) {
      uint64_t a_i;
      cin >> a_i;
      if (a_i < min_element) {
        min_element = a_i;
      }
      a.push_back(a_i);
    }

    tcs.push_back({n, k, a, min_element});
  }

  // sum of n^2 over all tcs <= 4,000,000
  for (TestCase tc : tcs) {
    cout << solve(tc) << endl;
  }
}