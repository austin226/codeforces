
#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <optional>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void remove_leading(string& input, const char char_to_remove) {
  input.erase(
      0, std::min(input.find_first_not_of(char_to_remove), input.size() - 1));
}

void remove_trailing(string& input, const char char_to_remove) {
  input.erase(input.find_last_not_of(char_to_remove) + 1, string::npos);
}

/// @brief  A weighted edge in a graph.
/// @tparam N Identifier to use for each node.
/// @tparam W Weight of each edge between nodes.
template <typename N, typename W>
struct Edge {
  N a;
  N b;
  W weight;

  N GetOtherEnd(N start) { return a == start ? b : a; }

  friend std::ostream& operator<<(std::ostream& os, const Edge& obj) {
    os << "[Edge " << obj.a << " <-> " << obj.b << " (" << obj.weight << ")]";
    return os;
  }
};

/// @brief A weighted, undirected graph.
/// @tparam N Identifier to use for each node.
/// @tparam W Weight of each edge between nodes.
template <typename N, typename W>
class WeightedGraph {
 private:
  using E = Edge<N, W>;
  std::set<N> nodes;
  std::vector<E> edges;
  std::multimap<N, E> neighbors_map;

 public:
  WeightedGraph() {}
  WeightedGraph(size_t size) { edges.reserve(size); }

  void AddNode(N node) { nodes.insert(node); }

  const set<N>& GetNodes() const { return nodes; }

  void AddEdge(N node_a, N node_b, W weight) {
    if (!nodes.contains(node_a) || !nodes.contains(node_b)) {
      throw runtime_error("Cannot connect edge - node not found");
    }
    E edge = {min(node_a, node_b), max(node_a, node_b), weight};
    edges.push_back(edge);
    neighbors_map.insert({node_a, edge});
    neighbors_map.insert({node_b, edge});
  }

  /// @brief Uses Dijkstra's algorithm to calculate the shortest distance from
  /// the starting node to all other nodes.
  /// @param start
  /// @return map of every node, to the distance it is from the start node. If
  /// the distance is not present, there is no path to that node.
  std::map<N, std::optional<W>> Dijkstra(N start) const {
    std::map<N, std::optional<W>> dist;
    dist[start] = std::optional(0);

    using PWN = std::pair<W, N>;
    std::priority_queue<PWN, std::vector<PWN>, std::greater<PWN>> q;
    for (N node : nodes) {
      if (node != start) {
        dist[node] = nullopt;
        // prev[node] = undefined
      }

      W priority = dist[node].value_or(std::numeric_limits<W>::max());
      q.push({priority, node});
    }

    while (!q.empty()) {
      N u = q.top().second;
      q.pop();
      if (!neighbors_map.contains(u)) {
        continue;
      }
      auto range = neighbors_map.equal_range(u);
      for (auto it = range.first; it != range.second; it++) {
        // For each neighbor v of u
        E edge = it->second;
        N v = edge.GetOtherEnd(u);
        W alt_dist = edge.weight + dist[u].value();

        if (!dist[v].has_value() || alt_dist < dist[v]) {
          dist[v] = alt_dist;
          // prev[v] = u

          // Decrease priority of v by alt
          // Since STL priority_queue doesn't support decrease by key,
          // we instead just add another instance of v at lower
          // priority.
          // https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/
          q.push({alt_dist, v});
        }
      }
    }

    return dist;
  }

  void DebugPrintDijkstra() {
    for (N start : this->GetNodes()) {
      std::cout << start << " distances:" << std::endl;
      std::map<N, std::optional<W>> distances = this->Dijkstra(start);
      for (N other_node : this->GetNodes()) {
        string d;
        if (distances[other_node].has_value()) {
          d = std::to_string(distances[other_node].value());
        } else {
          d = "unknown";
        }
        std::cout << "to " << other_node << ": " << d << std::endl;
      }
    }
  }
};

struct TestCase {
  // n in 1..100,000
  // length of arr
  uint32_t n;

  // each element in 1..1,000,000,000
  vector<uint32_t> arr;
};

// https://codeforces.com/contest/1904/problem/B
int main() {
  // t test cases 1..=5000
  // sum of all t.n <= 100,000
  uint16_t t;
  cin >> t;

  vector<TestCase> cases;
  cases.reserve(t);
  for (uint16_t case_i = 0; case_i < t; case_i++) {
    uint32_t n;
    cin >> n;

    vector<uint32_t> arr;
    arr.reserve(n);
    for (uint32_t i = 0; i < n; i++) {
      int32_t k;
      cin >> k;
      arr.push_back(k);
    }

    cases.push_back({n, arr});
  }

  for (TestCase tc : cases) {
    // for each index i in arr, output max # of addl array element
    // that you can remove if you remove a_i, and then set score to a_i.

    for (uint32_t i = 0; i < tc.n; i++) {
      // Copy arr
      vector<uint32_t> arr;
      copy(tc.arr.begin(), tc.arr.end(), back_inserter(arr));

      // Start score at i and remove item i
      uint64_t score = (uint64_t)(arr[i]);
      arr.erase(arr.begin() + i);

      // Sort arr
      sort(arr.begin(), arr.end());

      // Iterate through remaining elements
      uint32_t k;
      for (k = 0; k < tc.n - 1; k++) {
        if (score >= arr[k]) {
          score += arr[k];
        } else {
          break;
        }
      }

      // Print k
      cout << k;
      if (i < tc.n - 1) {
        cout << " ";
      }
    }
    cout << endl;
  }
}