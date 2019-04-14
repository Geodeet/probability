#include <catch.hpp>

#include "node.src.hpp"

TEST_CASE("node creation", "[tree][node]")
{
    Node parent(nullptr);
    Node node(&parent);

    REQUIRE(node.parent == &parent);
    REQUIRE(node.is_leaf() == true);
    REQUIRE(node.left == nullptr);
    REQUIRE(node.right == nullptr);
}

TEST_CASE("node insertion", "[tree][node]")
{
    Node node(nullptr);
    Outcome o1(1), o2(2), o3(3), o4(4);

    unsigned int depth2 = node.insert(o2);
    unsigned int depth1 = node.insert(o1);
    unsigned int depth3 = node.insert(o3);
    unsigned int depth4 = node.insert(o4);

    REQUIRE(depth1 == 2);
    REQUIRE(depth2 == 1);
    REQUIRE(depth3 == 2);
    REQUIRE(depth4 == 3);
}
