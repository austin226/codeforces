// https://codeforces.com/problemset/problem/287/A
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    bool grid[4][4];
    bool result;
    
    for (int i = 0; i < 4; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < 4; j++) {
            grid[i][j] = line[j] == '#';
        }
    }
    
    for (int r = 0; r < 3; r++) {
        for (int c= 0; c < 3; c++) {
           int sum = grid[r][c] + grid[r+1][c] + grid[r][c+1] + grid[r+1][c+1];
           if (sum != 2) {
               cout << "YES" << endl;
               return 0;
           }
        }
    }
    
    cout << "NO" << endl;
}