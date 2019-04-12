#include <catch.hpp>

#include "fraction.hpp"

TEST_CASE("fraction creation", "[fraction]")
{
    SECTION("from void")
    {
        Fraction f;

        REQUIRE(f.as_string() == "1");
    }

    SECTION("from integer")
    {
        Fraction f1(1), f2(2), f3(3), fm4(-4), fm5(-5);

        REQUIRE(f1.get_numerator() == 1);
        REQUIRE(f1.get_denomenator() == 1);
        REQUIRE(f2.get_numerator() == 2);
        REQUIRE(f2.get_denomenator() == 1);
        REQUIRE(f3.get_numerator() == 3);
        REQUIRE(f3.get_denomenator() == 1);
        REQUIRE(fm4.get_numerator() == -4);
        REQUIRE(fm4.get_denomenator() == 1);
        REQUIRE(fm5.get_numerator() == -5);
        REQUIRE(fm5.get_denomenator() == 1);
    }

    SECTION("from double")
    {
        FAIL("unimplemented test");
    }

    SECTION("from fraction")
    {
        Fraction f1(5, 1), f2(6, 5), f3(5, 6);
        Fraction f1c(f1), f2c(f2), f3c(f3);

        REQUIRE(f1c.get_numerator() == 5);
        REQUIRE(f1c.get_denomenator() == 1);
        REQUIRE(f2c.get_numerator() == 6);
        REQUIRE(f2c.get_denomenator() == 5);
        REQUIRE(f3c.get_numerator() == 5);
        REQUIRE(f3c.get_denomenator() == 6);
    }

    SECTION("from numerator & denominator")
    {
        Fraction f1(2, 2), f2(2, 4), f3(512, 1024), f4(3, 5);

        REQUIRE(f1.get_numerator() == 1);
        REQUIRE(f1.get_denomenator() == 1);
        REQUIRE(f2.get_numerator() == 1);
        REQUIRE(f2.get_denomenator() == 2);
        REQUIRE(f3.get_numerator() == 1);
        REQUIRE(f3.get_denomenator() == 2);
        REQUIRE(f4.get_numerator() == 3);
        REQUIRE(f4.get_denomenator() == 5);
    }
}

TEST_CASE("fraction displaying", "[fraction]")
{
    Fraction f1, f2(4), f3(5, 6);

    REQUIRE(f1.as_string() == "1");
    REQUIRE(f2.as_string() == "4");
    REQUIRE(f3.as_string() == "5 / 6");
}