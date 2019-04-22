#include <catch.hpp>

#include "fraction.hpp"

TEST_CASE("fraction creation from void", "[fraction]")
{
    Fraction f;

    REQUIRE(f.as_string() == "1");
}

TEST_CASE("fraction creation from integer", "[fraction]")
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

TEST_CASE("fraction creation from fraction", "[fraction]")
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

TEST_CASE("fraction creation from numerator & denominator", "[fraction]")
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

TEST_CASE("fraction displaying", "[fraction]")
{
    Fraction f1, f2(4), f3(5, 6);

    REQUIRE(f1.as_string() == "1");
    REQUIRE(f2.as_string() == "4");
    REQUIRE(f3.as_string() == "5 / 6");
}

TEST_CASE("fraction as double", "[fraction]")
{
    Fraction f1(4), f2(4, 5), f3(6, 5), f4(8, 5), f5(11, 5);

    REQUIRE(f1.as_double() == 4.0);
    REQUIRE(f2.as_double() == 0.8);
    REQUIRE(f3.as_double() == 1.2);
    REQUIRE(f4.as_double() == 1.6);
    REQUIRE(f5.as_double() == 2.2);
}

TEST_CASE("fraction assignment addition", "[fraction]")
{
    Fraction f1(2), f2(1, 3), f3(5, 3);
    Fraction other(1, 3);

    f1 += other;
    f2 += other;
    f3 += other;

    REQUIRE(f1.get_numerator() == 7);
    REQUIRE(f1.get_denomenator() == 3);
    REQUIRE(f2.get_numerator() == 2);
    REQUIRE(f2.get_denomenator() == 3);
    REQUIRE(f3.get_numerator() == 2);
    REQUIRE(f3.get_denomenator() == 1);
}

TEST_CASE("fraction assignment subtraction", "[fraction]")
{
    Fraction f1(2), f2(1, 3), f3(5, 3);
    Fraction other(1, 3);

    f1 -= other;
    f2 -= other;
    f3 -= other;

    REQUIRE(f1.get_numerator() == 5);
    REQUIRE(f1.get_denomenator() == 3);
    REQUIRE(f2.get_numerator() == 0);
    REQUIRE(f2.get_denomenator() == 1);
    REQUIRE(f3.get_numerator() == 4);
    REQUIRE(f3.get_denomenator() == 3);
}

TEST_CASE("fraction assignment multiplication", "[fraction]")
{
    Fraction f1(2), f2(1, 3), f3(5, 3);
    Fraction other(1, 3);

    f1 *= other;
    f2 *= other;
    f3 *= other;

    REQUIRE(f1.get_numerator() == 2);
    REQUIRE(f1.get_denomenator() == 3);
    REQUIRE(f2.get_numerator() == 1);
    REQUIRE(f2.get_denomenator() == 9);
    REQUIRE(f3.get_numerator() == 5);
    REQUIRE(f3.get_denomenator() == 9);
}

TEST_CASE("fraction assignment division", "[fraction]")
{
    Fraction f1(2), f2(1, 3), f3(5, 3);
    Fraction other(1, 3);

    f1 /= other;
    f2 /= other;
    f3 /= other;

    REQUIRE(f1.get_numerator() == 6);
    REQUIRE(f1.get_denomenator() == 1);
    REQUIRE(f2.get_numerator() == 1);
    REQUIRE(f2.get_denomenator() == 1);
    REQUIRE(f3.get_numerator() == 5);
    REQUIRE(f3.get_denomenator() == 1);
}

TEST_CASE("fraction assignment modulo", "[fraction]")
{
    Fraction f1(2), f2(1, 3), f3(5, 3), f4(1, 2);
    Fraction other(1, 3);

    f1 %= other;
    f2 %= other;
    f3 %= other;
    f4 %= other;

    REQUIRE(f1.get_numerator() == 0);
    REQUIRE(f1.get_denomenator() == 1);
    REQUIRE(f2.get_numerator() == 0);
    REQUIRE(f2.get_denomenator() == 1);
    REQUIRE(f3.get_numerator() == 0);
    REQUIRE(f3.get_denomenator() == 1);
    REQUIRE(f4.get_numerator() == 1);
    REQUIRE(f4.get_denomenator() == 6);
}

TEST_CASE("fraction integer assignment addition", "[fraction]")
{
    Fraction f1(2), f2(1, 3), f3(5, 3);
    int other(3);

    f1 += other;
    f2 += other;
    f3 += other;

    REQUIRE(f1.get_numerator() == 5);
    REQUIRE(f1.get_denomenator() == 1);
    REQUIRE(f2.get_numerator() == 10);
    REQUIRE(f2.get_denomenator() == 3);
    REQUIRE(f3.get_numerator() == 14);
    REQUIRE(f3.get_denomenator() == 3);
}

TEST_CASE("fraction integer assignment subtraction", "[fraction]")
{
    Fraction f1(2), f2(1, 3), f3(5, 3);
    int other(3);

    f1 -= other;
    f2 -= other;
    f3 -= other;

    REQUIRE(f1.get_numerator() == -1);
    REQUIRE(f1.get_denomenator() == 1);
    REQUIRE(f2.get_numerator() == -8);
    REQUIRE(f2.get_denomenator() == 3);
    REQUIRE(f3.get_numerator() == -4);
    REQUIRE(f3.get_denomenator() == 3);
}

TEST_CASE("fraction integer assignment multiplication", "[fraction]")
{
    Fraction f1(2), f2(1, 3), f3(5, 3);
    int other(3);

    f1 *= other;
    f2 *= other;
    f3 *= other;

    REQUIRE(f1.get_numerator() == 6);
    REQUIRE(f1.get_denomenator() == 1);
    REQUIRE(f2.get_numerator() == 1);
    REQUIRE(f2.get_denomenator() == 1);
    REQUIRE(f3.get_numerator() == 5);
    REQUIRE(f3.get_denomenator() == 1);
}

TEST_CASE("fraction integer assignment division", "[fraction]")
{
    Fraction f1(2), f2(1, 3), f3(5, 3);
    Fraction other(3);

    f1 /= other;
    f2 /= other;
    f3 /= other;

    REQUIRE(f1.get_numerator() == 2);
    REQUIRE(f1.get_denomenator() == 3);
    REQUIRE(f2.get_numerator() == 1);
    REQUIRE(f2.get_denomenator() == 9);
    REQUIRE(f3.get_numerator() == 5);
    REQUIRE(f3.get_denomenator() == 9);
}

TEST_CASE("fraction integer assignment modulo", "[fraction]")
{
    Fraction f1(2), f2(1, 3), f3(5, 3), f4(1, 2);
    Fraction other(1);

    f1 %= other;
    f2 %= other;
    f3 %= other;
    f4 %= other;

    REQUIRE(f1.get_numerator() == 0);
    REQUIRE(f1.get_denomenator() == 1);
    REQUIRE(f2.get_numerator() == 1);
    REQUIRE(f2.get_denomenator() == 3);
    REQUIRE(f3.get_numerator() == 2);
    REQUIRE(f3.get_denomenator() == 3);
    REQUIRE(f4.get_numerator() == 1);
    REQUIRE(f4.get_denomenator() == 2);
}

TEST_CASE("fraction unary operator", "[fraction]")
{
    Fraction f(3, 4);

    REQUIRE((-f).get_numerator() == -3);
    REQUIRE((-f).get_denomenator() == 4);
}

TEST_CASE("fraction assignment", "[fraction]")
{
    Fraction f(1, 3);

    f = Fraction(2, 5);

    REQUIRE(f.get_numerator() == 2);
    REQUIRE(f.get_denomenator() == 5);
}

TEST_CASE("fraction integer assignment", "[fraction]")
{
    Fraction f(1, 3);

    f = 4;

    REQUIRE(f.get_numerator() == 4);
    REQUIRE(f.get_denomenator() == 1);
}

TEST_CASE("fraction increment and decrement", "[fraction]")
{
    Fraction f(1, 11);

    REQUIRE(f.get_numerator() == 1);
    REQUIRE(f.get_denomenator() == 11);

    f++;

    REQUIRE(f.get_numerator() == 2);
    REQUIRE(f.get_denomenator() == 11);

    ++f;

    REQUIRE(f.get_numerator() == 3);
    REQUIRE(f.get_denomenator() == 11);

    f--;

    REQUIRE(f.get_numerator() == 2);
    REQUIRE(f.get_denomenator() == 11);

    --f;

    REQUIRE(f.get_numerator() == 1);
    REQUIRE(f.get_denomenator() == 11);
}
