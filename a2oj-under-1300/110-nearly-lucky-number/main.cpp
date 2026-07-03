#include <algorithm>
#include <iostream>

using namespace std;

int lucky_digits(const string s) {
    return ranges::count_if(s, [](const char c) { return c == '4' || c == '7'; });
}

bool is_lucky(const string s) {
    return lucky_digits(s) == s.length();
}

// https://codeforces.com/problemset/problem/110/A
int main() {
    string s;
    cin >> s;

    string lucky_digits_s = to_string(lucky_digits(s));
    if (is_lucky(lucky_digits_s)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
