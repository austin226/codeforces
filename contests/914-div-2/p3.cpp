
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

struct TestCase {
  uint16_t n;
  uint32_t k;
  vector<uint64_t> a;
};

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
    for (uint16_t n_i = 0; n_i < n; n_i++) {
      uint64_t a_i;
      cin >> a_i;
      a.push_back(a_i);
    }

    tcs.push_back({n, k, a});
  }

  // sum of n^2 over all tcs <= 4,000,000
  for (TestCase tc : tcs) {
    // Print a single int - smallest possitle value of min of tc.a after tc.k
    // operations.
  }
}