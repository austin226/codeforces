#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// https://codeforces.com/problemset/problem/69/A
int main()
{
    int nLines;
    cin >> nLines;

    int total_x = 0;
    int total_y = 0;
    int total_z = 0;

    for (int i = 0; i < nLines; i++)
    {
        int x, y, z;
        cin >> x;
        cin >> y;
        cin >> z;

        total_x += x;
        total_y += y;
        total_z += z;
    }

    if (total_x == 0 && total_y == 0 && total_z == 0) {
        // Equilibrium
        cout << "YES" << endl;
    } else {
        // Not equilibrium
        cout << "NO" << endl;
    }
}