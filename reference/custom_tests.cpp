#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "custom.h"
#include "doctest.h"

TEST_CASE("WeightedGraph") {
  WeightedGraph<char, uint32_t> g;
  g.AddNode('a');
  g.AddNode('b');
  g.AddNode('c');
  g.AddNode('b');

  g.AddEdge('a', 'b', 3);
  g.AddEdge('a', 'c', 4);

  SUBCASE("graph contains distinct nodes") {
    set<char> expected_nodes = {'a', 'b', 'c'};
    CHECK_EQ(expected_nodes, g.GetNodes());
  }

  SUBCASE("adding invalid edge throws exception") {
    CHECK_THROWS(g.AddEdge('z', 'a', 4));
  }
}