#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int countUpper(string s) {
    return std::count_if(s.begin(), s.end(), [](unsigned char c) { return std::isupper(c); });
}

std::string str_toupper(std::string s) {
    ranges::transform(s, s.begin(),
                      [](const unsigned char c) { return std::toupper(c); }
    );
    return s;
}

std::string str_tolower(std::string s) {
    ranges::transform(s, s.begin(),
                      [](const unsigned char c) { return std::tolower(c); }
    );
    return s;
}

// https://codeforces.com/problemset/problem/59/A
int main() {
    string orig;
    cin >> orig;

    int n = orig.size();
    int uppers = countUpper(orig);
    int lowers = n - uppers;
    if (uppers > lowers) {
        cout << str_toupper(orig) << endl;
    } else {
        cout << str_tolower(orig) << endl;
    }
}
