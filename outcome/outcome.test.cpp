#include <catch.hpp>

#include "outcome.hpp"

TEST_CASE("outcome creation from void", "[outcome]")
{
    Outcome o;

    REQUIRE(o.value == Fraction(1, 1));
    REQUIRE(o.probability == Fraction(1, 1));
}

TEST_CASE("outcome creation from other", "[outcome]")
{
    Outcome other(Fraction(1, 2), Fraction(1, 3));
    Outcome o(other);

    REQUIRE(o.value == Fraction(1, 2));
    REQUIRE(o.probability == Fraction(1, 3));
}

TEST_CASE("outcome creation from integer value", "[outcome]")
{
    Outcome o(4);

    REQUIRE(o.value == Fraction(4, 1));
    REQUIRE(o.probability == Fraction(1, 1));
}

TEST_CASE("outcome creation from fraction value", "[outcome]")
{
    Outcome o(Fraction(1, 2));

    REQUIRE(o.value == Fraction(1, 2));
    REQUIRE(o.probability == Fraction(1, 1));
}

TEST_CASE("outcome creation from integer value and integer probability", "[outcome]")
{
    Outcome o(4, 3);

    REQUIRE(o.value == Fraction(4, 1));
    REQUIRE(o.probability == Fraction(3, 1));
}

TEST_CASE("outcome creation from fraction value and integer probability", "[outcome]")
{
    Outcome o(Fraction(1, 3), 5);

    REQUIRE(o.value == Fraction(1, 3));
    REQUIRE(o.probability == Fraction(5, 1));
}

TEST_CASE("outcome creation from integer value and fraction probability", "[outcome]")
{
    Outcome o(5, Fraction(1, 3));

    REQUIRE(o.value == Fraction(5, 1));
    REQUIRE(o.probability == Fraction(1, 3));
}

TEST_CASE("outcome creation from fraction value and fraction probability", "[outcome]")
{
    Outcome o(Fraction(1, 3), Fraction(5, 6));

    REQUIRE(o.value == Fraction(1, 3));
    REQUIRE(o.probability == Fraction(5, 6));
}

TEST_CASE("outcome equality", "[outcome]")
{
    Outcome o1(Fraction(1, 3), Fraction(2, 3)), o2(Fraction(1, 3), Fraction(3, 4)), o3(Fraction(2, 3), Fraction(2, 3));

    REQUIRE(o1 == o2);
    REQUIRE(!(o2 == o3));
}

TEST_CASE("outcome inequality", "[outcome]")
{
    Outcome o1(Fraction(1, 3), Fraction(2, 3)), o2(Fraction(1, 3), Fraction(3, 4)), o3(Fraction(2, 3), Fraction(2, 3));

    REQUIRE(!(o1 != o2));
    REQUIRE(o2 != o3);
}

TEST_CASE("outcome less than", "[outcome]")
{
    Outcome o1(Fraction(1, 3), Fraction(2, 3)), o2(Fraction(1, 3), Fraction(3, 4)), o3(Fraction(2, 3), Fraction(2, 3));

    REQUIRE(!(o1 < o2));
    REQUIRE((o2 < o3));
}

TEST_CASE("outcome greater than", "[outcome]")
{
    Outcome o1(Fraction(1, 3), Fraction(2, 3)), o2(Fraction(1, 3), Fraction(3, 4)), o3(Fraction(2, 3), Fraction(2, 3));

    REQUIRE(!(o1 > o2));
    REQUIRE(!(o2 > o3));
}

TEST_CASE("outcome less than equal", "[outcome]")
{
    Outcome o1(Fraction(1, 3), Fraction(2, 3)), o2(Fraction(1, 3), Fraction(3, 4)), o3(Fraction(2, 3), Fraction(2, 3));

    REQUIRE((o1 <= o2));
    REQUIRE((o2 <= o3));
}

TEST_CASE("outcome greater than equal", "[outcome]")
{
    Outcome o1(Fraction(1, 3), Fraction(2, 3)), o2(Fraction(1, 3), Fraction(3, 4)), o3(Fraction(2, 3), Fraction(2, 3));

    REQUIRE((o1 >= o2));
    REQUIRE(!(o2 >= o3));
}
