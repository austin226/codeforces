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