
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
  uint64_t min_element;
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
    vector<uint64_t> arr = tc.a;
    // Sort arr
    sort(arr.begin(), arr.end());

    // Sort arr by diff between elements
    vector<uint64_t> arr2(tc.n, 0);
    uint16_t l = 0;
    uint16_t r = tc.n - 1;

    for (uint16_t i = tc.n - 1; i >= 0; i--) {
      if (i % 2 == 1) {
        // TODO doesn't work...
        arr2[i] = arr[l];
        l++;
      } else {
        arr2[i] = arr[r];
        r--;
      }
    }

    // Print a single int - smallest possible value of min of tc.a after tc.k
    // operations.
  }
}