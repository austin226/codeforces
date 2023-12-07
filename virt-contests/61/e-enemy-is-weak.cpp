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
  // TODO
  return 1;
}

uint64_t count_larger_js(int k, vector<uint32_t> &powers) {
  // TODO
  return 1;
}

int main() {
  cout << " Hello";
  return 0;
  // 3 <= n <= 10^6
  int n;
  cin >> n;

  // All powers are distinct. Each power is in (0..=10^9)
  auto powers = std::make_unique<vector<uint32_t>>();
  powers->reserve(n);

  uint64_t sum = 0;
  for (int soldier = 0; soldier < n; soldier++) {
    uint32_t a;
    cin >> a;

    powers->push_back(a);

    if (soldier <= 1) {
      continue;
    }

    // Count the number of triplets (i,j,k) to the left of a, such that i < j <
    // k; and a[i] > a[j] > a[k]
    sum += count_larger_js(soldier, *powers);
  }

  cout << sum << endl;
}