#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int N_ROWS = 5;
const int N_COLS = 5;

const int CENTER_R = N_ROWS / 2;
const int CENTER_C = N_COLS / 2;

// https://codeforces.com/problemset/problem/263/A
int main()
{
    for (int r = 0; r < N_ROWS; r++)
    {
        for (int c = 0; c < N_COLS; c++)
        {
            char cell;
            cin >> cell;
            if (cell == '1')
            {
                int answer = abs(r - CENTER_R) + abs(c - CENTER_C);
                cout << answer << endl;
            }
        }
    }
}