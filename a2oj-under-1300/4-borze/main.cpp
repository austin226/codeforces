// https://codeforces.com/problemset/problem/32/B
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string borze;
    cin >> borze;
    
    stringstream ss;
    
    int n = borze.length();
    for (int i = 0; i < n; i++) {
        if (borze[i] == '.') {
            ss << "0";
        } else if (borze[i+1] == '-') {
            ss << "2";
            i++;
        } else {
            ss << "1";
            i++;
        }
    }
    
    cout << ss.str() << endl;
}