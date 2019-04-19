#include <catch.hpp>

#include "dist.hpp"

TEST_CASE("dist mean", "[dist][stats]")
{
    Dist dist;

    dist.insert(Outcome(1, Fraction(1, 6)));
    dist.insert(Outcome(2, Fraction(1, 6)));
    dist.insert(Outcome(3, Fraction(1, 6)));
    dist.insert(Outcome(4, Fraction(1, 6)));
    dist.insert(Outcome(5, Fraction(1, 6)));
    dist.insert(Outcome(6, Fraction(1, 6)));


    REQUIRE(mean(dist) == Fraction(7, 2));
}

TEST_CASE("dist variance", "[dist][stats]")
{
    Dist dist;

    dist.insert(Outcome(1, Fraction(1, 6)));
    dist.insert(Outcome(2, Fraction(1, 6)));
    dist.insert(Outcome(3, Fraction(1, 6)));
    dist.insert(Outcome(4, Fraction(1, 6)));
    dist.insert(Outcome(5, Fraction(1, 6)));
    dist.insert(Outcome(6, Fraction(1, 6)));


    REQUIRE(variance(dist) == Fraction(35, 12));
}