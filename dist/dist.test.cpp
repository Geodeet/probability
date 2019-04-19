#include <catch.hpp>

#include "dist.hpp"

TEST_CASE("dist assignment", "[dist]")
{
    Dist dist, other;

    dist.insert(Outcome(1, Fraction(1, 6)));
    dist.insert(Outcome(2, Fraction(1, 6)));
    dist.insert(Outcome(3, Fraction(1, 6)));
    dist.insert(Outcome(4, Fraction(1, 6)));
    dist.insert(Outcome(5, Fraction(1, 6)));
    dist.insert(Outcome(6, Fraction(1, 6)));

    other = dist;

    auto iter = other.begin();

    REQUIRE(*iter++ == Outcome(1, Fraction(1, 6)));
    REQUIRE(*iter++ == Outcome(2, Fraction(1, 6)));
    REQUIRE(*iter++ == Outcome(3, Fraction(1, 6)));
    REQUIRE(*iter++ == Outcome(4, Fraction(1, 6)));
    REQUIRE(*iter++ == Outcome(5, Fraction(1, 6)));
    REQUIRE(*iter++ == Outcome(6, Fraction(1, 6)));
}

TEST_CASE("dist assignment addition", "[dist]")
{
    Dist dist, other;

    dist.insert(Outcome(1, Fraction(1, 6)));
    dist.insert(Outcome(2, Fraction(1, 6)));
    dist.insert(Outcome(3, Fraction(1, 6)));
    dist.insert(Outcome(4, Fraction(1, 6)));
    dist.insert(Outcome(5, Fraction(1, 6)));
    dist.insert(Outcome(6, Fraction(1, 6)));

    other = dist;

    dist += other;

    auto iter = dist.begin();

    REQUIRE(*iter++ == Outcome(2, Fraction(1, 36)));
    REQUIRE(*iter++ == Outcome(3, Fraction(2, 36)));
    REQUIRE(*iter++ == Outcome(4, Fraction(3, 36)));
    REQUIRE(*iter++ == Outcome(5, Fraction(4, 36)));
    REQUIRE(*iter++ == Outcome(6, Fraction(5, 36)));
    REQUIRE(*iter++ == Outcome(7, Fraction(6, 36)));
    REQUIRE(*iter++ == Outcome(8, Fraction(5, 36)));
    REQUIRE(*iter++ == Outcome(9, Fraction(4, 36)));
    REQUIRE(*iter++ == Outcome(10, Fraction(3, 36)));
    REQUIRE(*iter++ == Outcome(11, Fraction(2, 36)));
    REQUIRE(*iter++ == Outcome(12, Fraction(1, 36)));
}

TEST_CASE("dist assignment subtraction", "[dist]")
{
    Dist dist, other;

    dist.insert(Outcome(1, Fraction(1, 6)));
    dist.insert(Outcome(2, Fraction(1, 6)));
    dist.insert(Outcome(3, Fraction(1, 6)));
    dist.insert(Outcome(4, Fraction(1, 6)));
    dist.insert(Outcome(5, Fraction(1, 6)));
    dist.insert(Outcome(6, Fraction(1, 6)));

    other = dist;

    dist -= other;

    auto iter = dist.begin();

    REQUIRE(*iter++ == Outcome(-5, Fraction(1, 36)));
    REQUIRE(*iter++ == Outcome(-4, Fraction(2, 36)));
    REQUIRE(*iter++ == Outcome(-3, Fraction(3, 36)));
    REQUIRE(*iter++ == Outcome(-2, Fraction(4, 36)));
    REQUIRE(*iter++ == Outcome(-1, Fraction(5, 36)));
    REQUIRE(*iter++ == Outcome(0, Fraction(6, 36)));
    REQUIRE(*iter++ == Outcome(1, Fraction(5, 36)));
    REQUIRE(*iter++ == Outcome(2, Fraction(4, 36)));
    REQUIRE(*iter++ == Outcome(3, Fraction(3, 36)));
    REQUIRE(*iter++ == Outcome(4, Fraction(2, 36)));
    REQUIRE(*iter++ == Outcome(5, Fraction(1, 36)));
}

TEST_CASE("dist assignment multiplication", "[dist]")
{
    Dist dist, other;

    dist.insert(Outcome(1, Fraction(1, 6)));
    dist.insert(Outcome(2, Fraction(1, 6)));
    dist.insert(Outcome(3, Fraction(1, 6)));
    dist.insert(Outcome(4, Fraction(1, 6)));
    dist.insert(Outcome(5, Fraction(1, 6)));
    dist.insert(Outcome(6, Fraction(1, 6)));

    other = dist;

    dist *= other;

    auto iter = dist.begin();

    REQUIRE(*iter++ == Outcome(1, Fraction(1, 36)));
    REQUIRE(*iter++ == Outcome(2, Fraction(2, 36)));
    REQUIRE(*iter++ == Outcome(3, Fraction(2, 36)));
    REQUIRE(*iter++ == Outcome(4, Fraction(3, 36)));
    REQUIRE(*iter++ == Outcome(5, Fraction(2, 36)));
    REQUIRE(*iter++ == Outcome(6, Fraction(4, 36)));
    REQUIRE(*iter++ == Outcome(8, Fraction(2, 36)));
    REQUIRE(*iter++ == Outcome(9, Fraction(1, 36)));
    REQUIRE(*iter++ == Outcome(10, Fraction(2, 36)));
    REQUIRE(*iter++ == Outcome(12, Fraction(4, 36)));
    REQUIRE(*iter++ == Outcome(15, Fraction(2, 36)));
    REQUIRE(*iter++ == Outcome(16, Fraction(1, 36)));
    REQUIRE(*iter++ == Outcome(18, Fraction(2, 36)));
    REQUIRE(*iter++ == Outcome(20, Fraction(2, 36)));
    REQUIRE(*iter++ == Outcome(24, Fraction(2, 36)));
    REQUIRE(*iter++ == Outcome(25, Fraction(1, 36)));
    REQUIRE(*iter++ == Outcome(30, Fraction(2, 36)));
    REQUIRE(*iter++ == Outcome(36, Fraction(1, 36)));
}

TEST_CASE("dist assignment division", "[dist]")
{
    Dist dist, other;

    dist.insert(Outcome(1, Fraction(1, 6)));
    dist.insert(Outcome(2, Fraction(1, 6)));
    dist.insert(Outcome(3, Fraction(1, 6)));
    dist.insert(Outcome(4, Fraction(1, 6)));
    dist.insert(Outcome(5, Fraction(1, 6)));
    dist.insert(Outcome(6, Fraction(1, 6)));

    other = dist;

    dist /= other;

    auto iter = dist.begin();

    REQUIRE(*iter++ == Outcome(Fraction(1, 6), Fraction(1, 36)));
    REQUIRE(*iter++ == Outcome(Fraction(1, 5), Fraction(1, 36)));
    REQUIRE(*iter++ == Outcome(Fraction(1, 4), Fraction(1, 36)));
    REQUIRE(*iter++ == Outcome(Fraction(1, 3), Fraction(2, 36)));
    REQUIRE(*iter++ == Outcome(Fraction(2, 5), Fraction(1, 36)));
    REQUIRE(*iter++ == Outcome(Fraction(1, 2), Fraction(3, 36)));
    REQUIRE(*iter++ == Outcome(Fraction(3, 5), Fraction(1, 36)));
    REQUIRE(*iter++ == Outcome(Fraction(2, 3), Fraction(2, 36)));
    REQUIRE(*iter++ == Outcome(Fraction(3, 4), Fraction(1, 36)));
    REQUIRE(*iter++ == Outcome(Fraction(4, 5), Fraction(1, 36)));
    REQUIRE(*iter++ == Outcome(Fraction(5, 6), Fraction(1, 36)));
    REQUIRE(*iter++ == Outcome(Fraction(1, 1), Fraction(6, 36)));
    REQUIRE(*iter++ == Outcome(Fraction(6, 5), Fraction(1, 36)));
    REQUIRE(*iter++ == Outcome(Fraction(5, 4), Fraction(1, 36)));
    REQUIRE(*iter++ == Outcome(Fraction(4, 3), Fraction(1, 36)));
    REQUIRE(*iter++ == Outcome(Fraction(3, 2), Fraction(2, 36)));
    REQUIRE(*iter++ == Outcome(Fraction(5, 3), Fraction(1, 36)));
    REQUIRE(*iter++ == Outcome(Fraction(2, 1), Fraction(3, 36)));
    REQUIRE(*iter++ == Outcome(Fraction(5, 2), Fraction(1, 36)));
    REQUIRE(*iter++ == Outcome(Fraction(3, 1), Fraction(2, 36)));
    REQUIRE(*iter++ == Outcome(Fraction(4, 1), Fraction(1, 36)));
    REQUIRE(*iter++ == Outcome(Fraction(5, 1), Fraction(1, 36)));
    REQUIRE(*iter++ == Outcome(Fraction(6, 1), Fraction(1, 36)));
}

TEST_CASE("dist assignment modulo", "[dist]")
{
    Dist dist, other;

    dist.insert(Outcome(1, Fraction(1, 6)));
    dist.insert(Outcome(2, Fraction(1, 6)));
    dist.insert(Outcome(3, Fraction(1, 6)));
    dist.insert(Outcome(4, Fraction(1, 6)));
    dist.insert(Outcome(5, Fraction(1, 6)));
    dist.insert(Outcome(6, Fraction(1, 6)));

    other = dist;

    dist %= other;

    auto iter = dist.begin();

    REQUIRE(*iter++ == Outcome(0, Fraction(14, 36)));
    REQUIRE(*iter++ == Outcome(1, Fraction(10, 36)));
    REQUIRE(*iter++ == Outcome(2, Fraction(6, 36)));
    REQUIRE(*iter++ == Outcome(3, Fraction(3, 36)));
    REQUIRE(*iter++ == Outcome(4, Fraction(2, 36)));
    REQUIRE(*iter++ == Outcome(5, Fraction(1, 36)));
}

TEST_CASE("dist addition", "[dist]")
{
    Dist lhs, rhs;

    lhs.insert(Outcome(1, Fraction(1, 6)));
    lhs.insert(Outcome(2, Fraction(1, 6)));
    lhs.insert(Outcome(3, Fraction(1, 6)));
    lhs.insert(Outcome(4, Fraction(1, 6)));
    lhs.insert(Outcome(5, Fraction(1, 6)));
    lhs.insert(Outcome(6, Fraction(1, 6)));

    rhs = lhs;

    Dist result = lhs + rhs;

    auto iter = result.begin();

    REQUIRE(*iter++ == Outcome(2, Fraction(1, 36)));
    REQUIRE(*iter++ == Outcome(3, Fraction(2, 36)));
    REQUIRE(*iter++ == Outcome(4, Fraction(3, 36)));
    REQUIRE(*iter++ == Outcome(5, Fraction(4, 36)));
    REQUIRE(*iter++ == Outcome(6, Fraction(5, 36)));
    REQUIRE(*iter++ == Outcome(7, Fraction(6, 36)));
    REQUIRE(*iter++ == Outcome(8, Fraction(5, 36)));
    REQUIRE(*iter++ == Outcome(9, Fraction(4, 36)));
    REQUIRE(*iter++ == Outcome(10, Fraction(3, 36)));
    REQUIRE(*iter++ == Outcome(11, Fraction(2, 36)));
    REQUIRE(*iter++ == Outcome(12, Fraction(1, 36)));
}

TEST_CASE("dist subtraction", "[dist]")
{
    Dist lhs, rhs;

    lhs.insert(Outcome(1, Fraction(1, 6)));
    lhs.insert(Outcome(2, Fraction(1, 6)));
    lhs.insert(Outcome(3, Fraction(1, 6)));
    lhs.insert(Outcome(4, Fraction(1, 6)));
    lhs.insert(Outcome(5, Fraction(1, 6)));
    lhs.insert(Outcome(6, Fraction(1, 6)));

    rhs = lhs;

    Dist result = lhs - rhs;

    auto iter = result.begin();

    REQUIRE(*iter++ == Outcome(-5, Fraction(1, 36)));
    REQUIRE(*iter++ == Outcome(-4, Fraction(2, 36)));
    REQUIRE(*iter++ == Outcome(-3, Fraction(3, 36)));
    REQUIRE(*iter++ == Outcome(-2, Fraction(4, 36)));
    REQUIRE(*iter++ == Outcome(-1, Fraction(5, 36)));
    REQUIRE(*iter++ == Outcome(0, Fraction(6, 36)));
    REQUIRE(*iter++ == Outcome(1, Fraction(5, 36)));
    REQUIRE(*iter++ == Outcome(2, Fraction(4, 36)));
    REQUIRE(*iter++ == Outcome(3, Fraction(3, 36)));
    REQUIRE(*iter++ == Outcome(4, Fraction(2, 36)));
    REQUIRE(*iter++ == Outcome(5, Fraction(1, 36)));
}

TEST_CASE("dist multiplication", "[dist]")
{
    Dist lhs, rhs;

    lhs.insert(Outcome(1, Fraction(1, 6)));
    lhs.insert(Outcome(2, Fraction(1, 6)));
    lhs.insert(Outcome(3, Fraction(1, 6)));
    lhs.insert(Outcome(4, Fraction(1, 6)));
    lhs.insert(Outcome(5, Fraction(1, 6)));
    lhs.insert(Outcome(6, Fraction(1, 6)));

    rhs = lhs;

    Dist result = lhs * rhs;

    auto iter = result.begin();

    REQUIRE(*iter++ == Outcome(1, Fraction(1, 36)));
    REQUIRE(*iter++ == Outcome(2, Fraction(2, 36)));
    REQUIRE(*iter++ == Outcome(3, Fraction(2, 36)));
    REQUIRE(*iter++ == Outcome(4, Fraction(3, 36)));
    REQUIRE(*iter++ == Outcome(5, Fraction(2, 36)));
    REQUIRE(*iter++ == Outcome(6, Fraction(4, 36)));
    REQUIRE(*iter++ == Outcome(8, Fraction(2, 36)));
    REQUIRE(*iter++ == Outcome(9, Fraction(1, 36)));
    REQUIRE(*iter++ == Outcome(10, Fraction(2, 36)));
    REQUIRE(*iter++ == Outcome(12, Fraction(4, 36)));
    REQUIRE(*iter++ == Outcome(15, Fraction(2, 36)));
    REQUIRE(*iter++ == Outcome(16, Fraction(1, 36)));
    REQUIRE(*iter++ == Outcome(18, Fraction(2, 36)));
    REQUIRE(*iter++ == Outcome(20, Fraction(2, 36)));
    REQUIRE(*iter++ == Outcome(24, Fraction(2, 36)));
    REQUIRE(*iter++ == Outcome(25, Fraction(1, 36)));
    REQUIRE(*iter++ == Outcome(30, Fraction(2, 36)));
    REQUIRE(*iter++ == Outcome(36, Fraction(1, 36)));
}

TEST_CASE("dist division", "[dist]")
{
    Dist lhs, rhs;

    lhs.insert(Outcome(1, Fraction(1, 6)));
    lhs.insert(Outcome(2, Fraction(1, 6)));
    lhs.insert(Outcome(3, Fraction(1, 6)));
    lhs.insert(Outcome(4, Fraction(1, 6)));
    lhs.insert(Outcome(5, Fraction(1, 6)));
    lhs.insert(Outcome(6, Fraction(1, 6)));

    rhs = lhs;

    Dist result = lhs / rhs;

    auto iter = result.begin();

    REQUIRE(*iter++ == Outcome(Fraction(1, 6), Fraction(1, 36)));
    REQUIRE(*iter++ == Outcome(Fraction(1, 5), Fraction(1, 36)));
    REQUIRE(*iter++ == Outcome(Fraction(1, 4), Fraction(1, 36)));
    REQUIRE(*iter++ == Outcome(Fraction(1, 3), Fraction(2, 36)));
    REQUIRE(*iter++ == Outcome(Fraction(2, 5), Fraction(1, 36)));
    REQUIRE(*iter++ == Outcome(Fraction(1, 2), Fraction(3, 36)));
    REQUIRE(*iter++ == Outcome(Fraction(3, 5), Fraction(1, 36)));
    REQUIRE(*iter++ == Outcome(Fraction(2, 3), Fraction(2, 36)));
    REQUIRE(*iter++ == Outcome(Fraction(3, 4), Fraction(1, 36)));
    REQUIRE(*iter++ == Outcome(Fraction(4, 5), Fraction(1, 36)));
    REQUIRE(*iter++ == Outcome(Fraction(5, 6), Fraction(1, 36)));
    REQUIRE(*iter++ == Outcome(Fraction(1, 1), Fraction(6, 36)));
    REQUIRE(*iter++ == Outcome(Fraction(6, 5), Fraction(1, 36)));
    REQUIRE(*iter++ == Outcome(Fraction(5, 4), Fraction(1, 36)));
    REQUIRE(*iter++ == Outcome(Fraction(4, 3), Fraction(1, 36)));
    REQUIRE(*iter++ == Outcome(Fraction(3, 2), Fraction(2, 36)));
    REQUIRE(*iter++ == Outcome(Fraction(5, 3), Fraction(1, 36)));
    REQUIRE(*iter++ == Outcome(Fraction(2, 1), Fraction(3, 36)));
    REQUIRE(*iter++ == Outcome(Fraction(5, 2), Fraction(1, 36)));
    REQUIRE(*iter++ == Outcome(Fraction(3, 1), Fraction(2, 36)));
    REQUIRE(*iter++ == Outcome(Fraction(4, 1), Fraction(1, 36)));
    REQUIRE(*iter++ == Outcome(Fraction(5, 1), Fraction(1, 36)));
    REQUIRE(*iter++ == Outcome(Fraction(6, 1), Fraction(1, 36)));
}

TEST_CASE("dist modulo", "[dist]")
{
    Dist lhs, rhs;

    lhs.insert(Outcome(1, Fraction(1, 6)));
    lhs.insert(Outcome(2, Fraction(1, 6)));
    lhs.insert(Outcome(3, Fraction(1, 6)));
    lhs.insert(Outcome(4, Fraction(1, 6)));
    lhs.insert(Outcome(5, Fraction(1, 6)));
    lhs.insert(Outcome(6, Fraction(1, 6)));

    rhs = lhs;

    Dist result = lhs % rhs;

    auto iter = result.begin();

    REQUIRE(*iter++ == Outcome(0, Fraction(14, 36)));
    REQUIRE(*iter++ == Outcome(1, Fraction(10, 36)));
    REQUIRE(*iter++ == Outcome(2, Fraction(6, 36)));
    REQUIRE(*iter++ == Outcome(3, Fraction(3, 36)));
    REQUIRE(*iter++ == Outcome(4, Fraction(2, 36)));
    REQUIRE(*iter++ == Outcome(5, Fraction(1, 36)));
}