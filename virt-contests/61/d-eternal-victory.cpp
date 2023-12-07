// https://codeforces.com/contest/61/problem/D

#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void remove_leading(string &input, const char char_to_remove) {
  input.erase(
      0, std::min(input.find_first_not_of(char_to_remove), input.size() - 1));
}

void remove_trailing(string &input, const char char_to_remove) {
  input.erase(input.find_last_not_of(char_to_remove) + 1, string::npos);
}

template <typename N, typename W>
struct Edge {
  N a;
  N b;
  W weight;
};

/// A weighted, undirected graph.
template <typename N, typename W, typename S>
class Network {
 private:
  vector<Edge<N, W>> edges;

 public:
  Network(S size) {}

  void AddEdge(N node_a, N node_b, W weight) {
    Edge edge = {node_a, node_b, weight};
  }
};

int main() {
  // Similar to traveling salesman problem, but can finish in any city.
  // We want to visit every city at least once.
  // 1 <= n <= 10^5
  uint16_t n_cities;
  cin >> n_cities;

  Network<uint16_t, uint16_t, uint16_t> g(n_cities);
  for (uint16_t i = 0; i < n_cities - 1; i++) {
    // 1 <= x[i], y[i] <= n, 0 <= w[i] <= 2 × 10^4)
    // x and y are node indexes.
    // w is the weight of the edge connecting x and y.
    uint16_t x, y, w;
    cin >> x >> y >> w;

    g.AddEdge(x, y, w);
  }

  // calculate the minimum length to visit every node.
}