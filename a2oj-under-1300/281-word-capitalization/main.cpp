#include <iostream>

using namespace std;


// https://codeforces.com/problemset/problem/281/A
int main()
{
    string orig;
    cin >> orig;

    char head = std::toupper(orig[0]);
    string tail = orig.substr(1);

    cout << head << tail << endl;
}