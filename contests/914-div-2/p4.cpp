
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

int main() {
  // 
}