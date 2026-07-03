#include <iostream>

using namespace std;

int state(const int pressSum) {
    return (pressSum + 1) % 2;
}

// https://codeforces.com/problemset/problem/275/A
int main()
{
    int top0, top1, top2, mid0, mid1, mid2, bot0, bot1, bot2;
    cin >> top0 >> top1 >> top2 >> mid0 >> mid1 >> mid2 >> bot0 >> bot1 >> bot2;

    cout << state(top0 + top1 + mid0)
        << state(top1 + top0 + top2 + mid1)
        << state(top2 + top1 + mid2)
        << endl
        << state(mid0 + top0 + mid1 + bot0)
        << state(mid1 + top1 + mid0 + mid2 + bot1)
        << state(mid2 + mid1 + top2 + bot2)
        << endl
        << state(bot0 + mid0 + bot1)
        << state(bot1 + bot0 + bot2 + mid1)
        << state(bot2 + bot1 + mid2)
        << endl;
}