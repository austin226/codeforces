// https://codeforces.com/contest/61/problem/A

#include <iostream>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;

    for (int i = 0; i < a.length(); i++)
    {
        int n1 = (a[i] == '0' ? 0 : 1);
        int n2 = (b[i] == '0' ? 0 : 1);
        cout << (n1 ^ n2);
    }

    cout << endl;
}