#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "custom.h"
#include "doctest.h"

TEST_CASE("WeightedGraph") {
  WeightedGraph<char, int32_t> g;
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

  SUBCASE("Dijkstra returns distances to neighbors") {
    using M = map<char, optional<int32_t>>;
    SUBCASE("distance from a") {
      M dist_a = g.Dijkstra('a');
      CHECK_EQ(3, dist_a.size());
      CHECK_EQ(0, dist_a['a'].value_or(-1));
      CHECK_EQ(3, dist_a['b'].value_or(-1));
      CHECK_EQ(4, dist_a['c'].value_or(-1));
    }

    SUBCASE("distance from b") {
      M dist_b = g.Dijkstra('b');
      CHECK_EQ(3, dist_b.size());
      CHECK_EQ(3, dist_b['a'].value_or(-1));
      CHECK_EQ(0, dist_b['b'].value_or(-1));
      CHECK_EQ(7, dist_b['c'].value_or(-1));
    }

    SUBCASE("distance from c") {
      M dist_c = g.Dijkstra('c');
      CHECK_EQ(3, dist_c.size());
      CHECK_EQ(4, dist_c['a'].value_or(-1));
      CHECK_EQ(7, dist_c['b'].value_or(-1));
      CHECK_EQ(0, dist_c['c'].value_or(-1));
    }
  }
}

TEST_CASE("Numeric weighted graph") {
  WeightedGraph<uint16_t, uint16_t> g;
  g.AddNode(1);
  g.AddNode(2);
  g.AddNode(3);

  g.AddEdge(1, 2, 3);
  g.AddEdge(1, 3, 3);

  SUBCASE("Dijkstra returns distances to neighbors") {
    using M = map<uint16_t, optional<uint16_t>>;
    SUBCASE("distance from 1") {
      M dist_1 = g.Dijkstra(1);
      CHECK_EQ(3, dist_1.size());
      CHECK_EQ(0, dist_1[1].value_or(-1));
      CHECK_EQ(3, dist_1[2].value_or(-1));
      CHECK_EQ(3, dist_1[3].value_or(-1));
    }

    SUBCASE("distance from 2") {
      M dist_2 = g.Dijkstra(2);
      CHECK_EQ(3, dist_2.size());
      CHECK_EQ(3, dist_2[1].value_or(-1));
      CHECK_EQ(0, dist_2[2].value_or(-1));
      CHECK_EQ(6, dist_2[3].value_or(-1));
    }

    SUBCASE("distance from 3") {
      M dist_3 = g.Dijkstra(3);
      CHECK_EQ(3, dist_3.size());
      CHECK_EQ(3, dist_3[1].value_or(-1));
      CHECK_EQ(6, dist_3[2].value_or(-1));
      CHECK_EQ(0, dist_3[3].value_or(-1));
    }
  }
}