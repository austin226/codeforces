#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "custom.h"
#include "doctest.h"

TEST_CASE("graph contains distinct nodes") {
  WeightedGraph<char, uint32_t> g;
  g.AddNode('a');
  g.AddNode('b');
  g.AddNode('c');
  g.AddNode('b');

  set<char> expected_nodes = {'a', 'b', 'c'};
  CHECK_EQ(expected_nodes, g.GetNodes());
}