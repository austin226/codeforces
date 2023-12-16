// When updating this, also update [.vscode/snippet.cpp.code-snippets]

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

#pragma region Loops

#define F(i, L, R) for (int i = L; i < R; i++)

#pragma endregion

#pragma region Strings

void remove_leading(string& input, const char char_to_remove) {
  input.erase(
      0, std::min(input.find_first_not_of(char_to_remove), input.size() - 1));
}

void remove_trailing(string& input, const char char_to_remove) {
  input.erase(input.find_last_not_of(char_to_remove) + 1, string::npos);
}

/**
 * Prefix function: Knuth–Morris–Pratt algorithm
 * The prefix function for a n-length string is defined as an array p of length
 * n, where p[i] is the length of the longest proper prefix of the substring
 * s[0..i] which is also a suffix of this substring.
 * 
 * Example: 
 * s = fixprefixsuffix
 * p = 000000123001123
 * 
 * @see https://cp-algorithms.com/string/prefix-function.html
 */
std::vector<int> kmp_prefix(std::string s) {
  int n = s.length();
  std::vector<int> p(n);
  for (int i = 1; i < n; i++) {
    int j = p[i - 1];
    while (j > 0 && s[i] != s[j]) {
      j = p[j - 1];
    }
    if (s[i] == s[j]) {
      j++;
    }
    p[i] = j;
  }
  return p;
}

#define STR_CONTAINS(s1, s2) s1.find(s2) != std::string::npos

#pragma endregion

#pragma region Graphs

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

#pragma endregion

#pragma region Int Types

#define _N_TYPE_MIN(T) std::numeric_limits<T>::min()
#define _N_TYPE_MAX(T) std::numeric_limits<T>::max()

#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define us unsigned short

#pragma endregion

#pragma region Vectors

#define F(i, L, R) for (int i = L; i < R; i++)
#define SZ(x) ((int)((x).size()))
#define SORT_VEC(vec) std::sort(vec.begin(), vec.end())
#define VEC_MIN(vec) std::min_element(vec.begin(), vec.end())
#define VEC_MAX(vec) std::max_element(vec.begin(), vec.end())
#define COPY_VEC(vec1, vec2) \
  std::copy(vec1.begin(), vec1.end(), vec2.begin(), vec2.end())
#define pb push_back
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;

#pragma endregion

#pragma region Math

#define MIN_MAX(a, b) std::tuple(std::min(a, b), std::max(a, b))
#define PI 3.1415926535897932384626

#pragma endregion

#pragma region IO

template <typename T, typename TT>
ostream& operator<<(ostream& s, pair<T, TT> t) {
  return s << "(" << t.first << "," << t.second << ")";
}
template <typename T>
ostream& operator<<(ostream& s, vector<T> t) {
  F(i, 0, SZ(t)) s << t[i] << " ";
  return s;
}

#pragma endregion

int main() {
  // $0
}