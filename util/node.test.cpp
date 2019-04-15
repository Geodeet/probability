#include <catch.hpp>

#include "node.src.hpp"

TEST_CASE("node creation", "[tree][node]")
{
    Node node;

    REQUIRE(node.is_leaf() == true);
    REQUIRE(node.left == nullptr);
    REQUIRE(node.right == nullptr);
}

TEST_CASE("unique node insertion", "[tree][node]")
{
    Node *node = new Node();
    Outcome o1(1, 1), o2(2, 2), o3(3, 3), o4(4, 4);

    node = node->insert(o1);
    node = node->insert(o2);
    node = node->insert(o3);
    node = node->insert(o4);

    REQUIRE(node->find(1) == 1);
    REQUIRE(node->find(2) == 2);
    REQUIRE(node->find(3) == 3);
    REQUIRE(node->find(4) == 4);
}

TEST_CASE("duplicate node insertion", "[tree][node]")
{
    Node *node = new Node();
    Outcome o1(2), o2(2), o3(3);

    node = node->insert(o1);
    node = node->insert(o2);
    node = node->insert(o3);

    REQUIRE(node->outcome.value == 2);
    REQUIRE(node->outcome.probability == 2);
    REQUIRE(node->left->is_leaf());
    REQUIRE(node->right->outcome.value == 3);
    REQUIRE(node->right->outcome.probability == 1);
}
