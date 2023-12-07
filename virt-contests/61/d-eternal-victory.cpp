// https://codeforces.com/contest/61/problem/D

#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void remove_leading(string &input, const char char_to_remove) {
  input.erase(
      0, std::min(input.find_first_not_of(char_to_remove), input.size() - 1));
}

void remove_trailing(string &input, const char char_to_remove) {
  input.erase(input.find_last_not_of(char_to_remove) + 1, string::npos);
}

int main() {
  // 1 <= n <= 10^5
  uint16_t n_cities;
  cin >> n_cities;

  for (uint16_t i = 0; i < n_cities - 1; i++) {
    // 1 <= x[i], y[i] <= n, 0 <= w[i] <= 2 × 10^4)
    uint16_t x, y, w;
    cin >> x >> y >> w;
  }
}