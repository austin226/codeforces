#include <iostream>
#include <vector>

using namespace std;

vector<int> years() {
    vector<int> v;

    for (int i = 1000; i <= 9012; i++) {
        const int a = i / 1000;
        const int b = (i % 1000) / 100;
        const int c = (i % 100) / 10;
        const int d = i % 10;
        if (a == b || a == c || a == d || b == c || b == d || c == d) continue;
        v.push_back(i);
    }

    return v;
}
vector<int> yearsV = years();

int nextYear(const int year1) {
    const size_t nYears = yearsV.size();
    if (year1 < yearsV[0]) return yearsV[0];

    for (int i = 0; i < nYears; i++) {
        if (year1 >= yearsV[i] && year1 < yearsV[i+1]) {
            return yearsV[i+1];
        }
    }
    return 0;
}

// https://codeforces.com/problemset/problem/271/A
int main()
{
    int year1;
    cin >> year1;

    cout << nextYear(year1) << endl;
}