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

// TEST_CASE("dist skewness squared with symmetric distribution", "[dist][stats]")
// {
//     Dist dist;

//     dist.insert(Outcome(1, Fraction(1, 6)));
//     dist.insert(Outcome(2, Fraction(1, 6)));
//     dist.insert(Outcome(3, Fraction(1, 6)));
//     dist.insert(Outcome(4, Fraction(1, 6)));
//     dist.insert(Outcome(5, Fraction(1, 6)));
//     dist.insert(Outcome(6, Fraction(1, 6)));

//     REQUIRE(skewness_squared(dist) == 0);
// }

// TEST_CASE("dist skewness squared with asymmetric distribution", "[dist][stats]")
// {
//     Dist dist;

//     dist.insert(Outcome(0, Fraction(1, 3)));
//     dist.insert(Outcome(1, Fraction(2, 3)));

//     REQUIRE(skewness_squared(dist) == Fraction(1, 2));
// }

TEST_CASE("dist kurtosis", "[dist][stats]")
{
    Dist dist;

    dist.insert(Outcome(1, Fraction(1, 6)));
    dist.insert(Outcome(2, Fraction(1, 6)));
    dist.insert(Outcome(3, Fraction(1, 6)));
    dist.insert(Outcome(4, Fraction(1, 6)));
    dist.insert(Outcome(5, Fraction(1, 6)));
    dist.insert(Outcome(6, Fraction(1, 6)));

    REQUIRE(kurtosis(dist) == Fraction(303, 175));
}

TEST_CASE("dist moments", "[dist][stats]")
{
    Dist dist;

    dist.insert(Outcome(1, Fraction(1, 6)));
    dist.insert(Outcome(2, Fraction(1, 6)));
    dist.insert(Outcome(3, Fraction(1, 6)));
    dist.insert(Outcome(4, Fraction(1, 6)));
    dist.insert(Outcome(5, Fraction(1, 6)));
    dist.insert(Outcome(6, Fraction(1, 6)));

    REQUIRE(moment(0, dist) == 1);
    REQUIRE(moment(1, dist) == Fraction(7, 2));
    REQUIRE(moment(2, dist) == Fraction(91, 6));
    REQUIRE(moment(3, dist) == Fraction(147, 2));
    REQUIRE(moment(4, dist) == Fraction(2275, 6));
}

TEST_CASE("dist mode", "[dist][stats]")
{
    Dist dist;

    dist.insert(Outcome(1, Fraction(1, 6)));
    dist.insert(Outcome(2, Fraction(1, 6)));
    dist.insert(Outcome(3, Fraction(1, 2)));
    dist.insert(Outcome(4, Fraction(1, 6)));

    REQUIRE(mode(dist) == 3);
}

TEST_CASE("dist median", "[dist][stats]")
{
    Dist dist;

    dist.insert(Outcome(1, Fraction(1, 6)));
    dist.insert(Outcome(2, Fraction(1, 6)));
    dist.insert(Outcome(3, Fraction(1, 2)));
    dist.insert(Outcome(4, Fraction(1, 6)));

    REQUIRE(median(dist) == 3);
}

TEST_CASE("dist median dice", "[dist][stats]")
{
    Dist dist;

    dist.insert(Outcome(1, Fraction(1, 6)));
    dist.insert(Outcome(2, Fraction(1, 6)));
    dist.insert(Outcome(3, Fraction(1, 6)));
    dist.insert(Outcome(4, Fraction(1, 6)));
    dist.insert(Outcome(5, Fraction(1, 6)));
    dist.insert(Outcome(6, Fraction(1, 6)));

    REQUIRE(median(dist) == 4);
}

TEST_CASE("dist percentile", "[dist][stats]")
{
    Dist dist;

    dist.insert(Outcome(1, Fraction(1, 6)));
    dist.insert(Outcome(2, Fraction(1, 6)));
    dist.insert(Outcome(3, Fraction(1, 6)));
    dist.insert(Outcome(4, Fraction(1, 6)));
    dist.insert(Outcome(5, Fraction(1, 6)));
    dist.insert(Outcome(6, Fraction(1, 6)));

    REQUIRE(percentile(0, dist) == 1);
    REQUIRE(percentile(49, dist) == 3);
    REQUIRE(percentile(100,dist) == 6);
}
