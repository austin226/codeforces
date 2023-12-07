// https://codeforces.com/contest/61/problem/E

#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>
#include <memory>
#include <set>
#include <sstream>
#include <vector>

using namespace std;

uint64_t count_larger_is(int j, vector<uint32_t> &powers) {
  uint64_t sum = 0;

  for (size_t i = 0; i < j; i++) {
    if (powers[i] > powers[j]) {
      sum++;
    }
  }

  return sum;
}

uint64_t count_larger_js(int k, vector<uint32_t> &powers) {
  uint64_t sum = 0;

  for (size_t j = 0; j < k; j++) {
    if (powers[j] > powers[k]) {
      sum += count_larger_is(j, powers);
    }
  }

  return sum;
}

int main() {
  // 3 <= n <= 10^6
  size_t n;
  cin >> n;

  // All powers are distinct. Each power is in (0..=10^9)
  auto powers = std::make_unique<vector<uint32_t>>();
  powers->reserve(n);

  uint64_t sum = 0;
  for (size_t k = 0; k < n; k++) {
    uint32_t a;
    cin >> a;

    powers->push_back(a);

    if (k <= 1) {
      continue;
    }

    // Count the number of triplets (i,j,k) to the left of a, such that i < j <
    // k; and a[i] > a[j] > a[k]
    sum += count_larger_js(k, *powers);
  }

  cout << sum << endl;
}