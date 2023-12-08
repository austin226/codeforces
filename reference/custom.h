// When updating this, also update [.vscode/snippet.cpp.code-snippets]

#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
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
class Edge {
 public:
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
  set<N> nodes;
  vector<E> edges;
  multimap<N, E> neighbors_map;

 public:
  WeightedGraph() {}
  WeightedGraph(size_t size) { edges.reserve(size); }

  void AddNode(N node) { nodes.insert(node); }

  const set<N>& GetNodes() const { return nodes; }

  void AddEdge(N node_a, N node_b, W weight) {
    E edge = {min(node_a, node_b), max(node_a, node_b), weight};
    edges.push_back(edge);
    neighbors_map.insert({node_a, edge});
    neighbors_map.insert({node_b, edge});
  }

  /// @brief Uses Dijkstra's algorithm to calculate the shortest distance from
  /// the starting node to all other nodes.
  /// @param start
  /// @return map of every node, to the distance it is from the start node.
  map<N, W> Dijkstra(N start) const {
    // TODO use DP to cache previously visited nodes
    // TODO use dijkstra

    // Find neighbors of starting node
    // TODO Implemnt dijkstra

    map<N, W> dist;
    dist[start] = 0;

    priority_queue<pair<W, N>> q;
    for (N node : nodes) {
      if (node != start) {
        dist[node] = numeric_limits<N>::max();
        // prev[node] = undefined
      }
      q.push({dist[node], node});
    }

    while (!q.empty()) {
      N best_vertex = q.top().second;
      q.pop();
      if (neighbors_map.contains(best_vertex)) {
        auto range = neighbors_map.equal_range(best_vertex);
        for (auto it = range.first; it != range.second; it++) {
          // For each neighbor of best_vertex
          E edge = it->second;
          N neighbor = edge.GetOtherEnd(best_vertex);
          W alt_dist = dist[best_vertex] + edge.weight;
          if (alt_dist < dist[neighbor]) {
            dist[neighbor] = alt_dist;
            // prev[neighbor] = best_vertex

            // Decrease priority of neighbor by alt
            // Since STL priority_queue doesn't support decrease by key,
            // we instead just add another instance of neighbor at lower
            // priority.
            // https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/
            q.push({dist[neighbor], neighbor});
          }
        }
      }
    }

    return dist;
  }
};
