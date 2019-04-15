#include <catch.hpp>

#include "tree.hpp"

TEST_CASE("tree iterator", "[tree]")
{
    Tree t;
    Outcome o1(1), o2(2), o3(3), o4(4), o5(5), o6(6);

    t.insert(o3);
    t.insert(o6);
    t.insert(o4);
    t.insert(o1);
    t.insert(o2);
    t.insert(o5);

    auto pre_iter = t.begin();
    auto post_iter = t.begin();

    REQUIRE((*pre_iter).value == 1);
    REQUIRE(pre_iter->value == 1);
    REQUIRE(post_iter->value == 1);

    REQUIRE((++pre_iter)->value == 2);
    REQUIRE((post_iter++)->value == 1);
    REQUIRE(post_iter->value == 2);

    ++pre_iter;
    post_iter++;
    REQUIRE(pre_iter->value == 3);
    REQUIRE(post_iter->value == 3);
    ++pre_iter;
    post_iter++;
    REQUIRE(pre_iter->value == 4);
    REQUIRE(post_iter->value == 4);

    ++pre_iter;
    post_iter++;
    REQUIRE(pre_iter->value == 5);
    REQUIRE(post_iter->value == 5);

    ++pre_iter;
    post_iter++;
    REQUIRE(pre_iter->value == 6);
    REQUIRE(post_iter->value == 6);

    ++pre_iter;
    post_iter++;
    REQUIRE(pre_iter == t.end());
    REQUIRE(post_iter == t.end());
}

TEST_CASE("tree insertion", "[tree]")
{
}

TEST_CASE("tree probability lookup", "[tree]")
{
}