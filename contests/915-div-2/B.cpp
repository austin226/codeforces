#include <algorithm>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <optional>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <string_view>
#include <type_traits>
#include <vector>

using namespace std;

#define F(i, L, R) for (int i = L; i < R; i++)
#define STR_CONTAINS(s1, s2) s1.find(s2) != std::string::npos

#define SZ(x) ((int)((x).size()))
#define SORT_VEC(vec) std::sort(vec.begin(), vec.end())
#define VEC_MIN(vec) std::min_element(vec.begin(), vec.end())
#define VEC_MAX(vec) std::max_element(vec.begin(), vec.end())
#define COPY_VEC(vec1, vec2) \
  std::copy(vec1.begin(), vec1.end(), vec2.begin(), vec2.end())
#define pb push_back

#define MIN_MAX(a, b) std::tuple(std::min(a, b), std::max(a, b))
#define PI 3.1415926535897932384626

#define _N_TYPE_MIN(T) std::numeric_limits<T>::min()
#define _N_TYPE_MAX(T) std::numeric_limits<T>::max()

#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define us unsigned short

class Node {
 public:
  int index;

  Node(int i) : index(i) {}
};

// https://codeforces.com/contest/1905/problem/B
int main() {
  int t;
  cin >> t;

  F(t_i, 0, t) {
    int n;
    cin >> n;

    map<int, shared_ptr<Node>> nodes;
    // F(i, 0, n) {
    //   Node node;
    //   nodes[i] = node;
    // }

    F(i, 0, n - 1) {
      int u, v;
      cin >> u >> v;

      if (!nodes.contains(u)) {
        nodes[v] = make_shared<Node>(u);
      }
      if (!nodes.contains(v)) {
        nodes[v] = make_shared<Node>(v);
      }
    }
  }
}