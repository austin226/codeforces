// https://codeforces.com/contest/61/problem/C

#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>
#include <memory>
#include <sstream>
#include <set>
#include <vector>

using namespace std;

uint64_t parse_with_base(string str, int a)
{
    uint64_t str_val = 0;
    uint64_t place_value = (int)floor(pow((double)a, str.length() - 1));
    for (char c : str)
    {
        // c is a digit in base a
        // get int value of c on its own
        int c_int_val;
        if (c >= '0' && c <= '9')
        {
            // c is 0-9
            c_int_val = c - '0';
        }
        else
        {
            // c is A-Z
            c_int_val = c - 'A' + 10;
        }
        str_val += c_int_val * place_value;
        place_value /= a;
    }

    return str_val;
}

string convert_to_base(uint64_t n, int base)
{
    if (n == 0)
    {
        return "0";
    }

    stringstream ss;

    bool is_leading_zero = true;
    int place = 1;
    while (pow(base, place) < n)
    {
        place++;
    }
    while (place >= 0)
    {
        uint64_t place_value = floor(pow(base, place));
        uint64_t this_digit = n / place_value;
        if (!(this_digit == 0 && is_leading_zero))
        {
            is_leading_zero = false;
            ss << this_digit;
        }
        n %= place_value;
        place--;
    }
    return ss.str();
}

string convert_to_roman(uint64_t n)
{
    // TODO
    return "C";
}

int main()
{
    // a door has 4 parts
    // 1. int a  - 2 <= a <= 25
    // 2. (int b - 2 <= b <= 25) or (R)
    // 3. int c - written in base-a. c may have leading 0's. len(c) <= 1000.
    //      Need to write it in base-b. If base-b is "R", write it in Roman numerals.

    // If roman numerals, c <= 3000 and won't be 0.
    // Else, c won't be greater than 10^15.

    int a;
    string b, c;
    cin >> a >> b >> c;

    uint64_t a_int = parse_with_base(c, a);
    if (b == "R")
    {
        cout << convert_to_roman(a_int) << endl;
    }
    else
    {
        cout << convert_to_base(a_int, stoi(b)) << endl;
    }
}