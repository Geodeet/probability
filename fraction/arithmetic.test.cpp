#include <catch.hpp>

#include "arithmetic.src.hpp"

TEST_CASE("fraction addition", "[fraction][arithmetic]")
{
    Fraction f1(1, 2), f2(3, 4), f3(-5, 7), f4(-1, 3);

    Fraction res1 = f1 + f2;
    Fraction res2 = f2 + f3;
    Fraction res3 = f3 + f4;

    REQUIRE(res1.get_numerator() == 5);
    REQUIRE(res1.get_denomenator() == 4);
    REQUIRE(res2.get_numerator() == 1);
    REQUIRE(res2.get_denomenator() == 28);
    REQUIRE(res3.get_numerator() == -22);
    REQUIRE(res3.get_denomenator() == 21);
}

TEST_CASE("fraction subtraction", "[fraction][arithmetic]")
{
    Fraction f1(1, 2), f2(3, 4), f3(-5, 7), f4(-1, 3);

    Fraction res1 = f1 - f2;
    Fraction res2 = f2 - f3;
    Fraction res3 = f3 - f4;

    REQUIRE(res1.get_numerator() == -1);
    REQUIRE(res1.get_denomenator() == 4);
    REQUIRE(res2.get_numerator() == 41);
    REQUIRE(res2.get_denomenator() == 28);
    REQUIRE(res3.get_numerator() == -8);
    REQUIRE(res3.get_denomenator() == 21);
}

TEST_CASE("fraction multiplication", "[fraction][arithmetic]")
{
    Fraction f1(1, 2), f2(3, 4), f3(-5, 7), f4(-1, 3);

    Fraction res1 = f1 * f2;
    Fraction res2 = f2 * f3;
    Fraction res3 = f3 * f4;

    REQUIRE(res1.get_numerator() == 3);
    REQUIRE(res1.get_denomenator() == 8);
    REQUIRE(res2.get_numerator() == -15);
    REQUIRE(res2.get_denomenator() == 28);
    REQUIRE(res3.get_numerator() == 5);
    REQUIRE(res3.get_denomenator() == 21);
}

TEST_CASE("fraction division", "[fraction][arithmetic]")
{
    Fraction f1(1, 2), f2(3, 4), f3(-5, 7), f4(-1, 3);

    Fraction res1 = f1 / f2;
    Fraction res2 = f2 / f3;
    Fraction res3 = f3 / f4;

    REQUIRE(res1.get_numerator() == 2);
    REQUIRE(res1.get_denomenator() == 3);
    REQUIRE(res2.get_numerator() == -21);
    REQUIRE(res2.get_denomenator() == 20);
    REQUIRE(res3.get_numerator() == 15);
    REQUIRE(res3.get_denomenator() == 7);
}

TEST_CASE("fraction modulo", "[fraction][arithmetic]")
{
    Fraction f1(1, 2), f2(3, 4), f3(-5, 7), f4(-1, 3);

    Fraction res1 = f1 % f2;
    Fraction res2 = f2 % f3;
    Fraction res3 = f3 % f4;

    REQUIRE(res1.get_numerator() == 1);
    REQUIRE(res1.get_denomenator() == 2);
    REQUIRE(res2.get_numerator() == 1);
    REQUIRE(res2.get_denomenator() == 28);
    REQUIRE(res3.get_numerator() == -1);
    REQUIRE(res3.get_denomenator() == 21);
}

TEST_CASE("fraction integer addition", "[fraction][arithmetic]")
{
    Fraction f(1, 3);

    Fraction res1 = f + 2;
    Fraction res2 = 2 + f;

    REQUIRE(res1.get_numerator() == 7);
    REQUIRE(res1.get_denomenator() == 3);
    REQUIRE(res2.get_numerator() == 7);
    REQUIRE(res2.get_denomenator() == 3);
}

TEST_CASE("fraction integer subtraction", "[fraction][arithmetic]")
{
    Fraction f(1, 3);

    Fraction res1 = f - 2;
    Fraction res2 = 2 - f;

    REQUIRE(res1.get_numerator() == -5);
    REQUIRE(res1.get_denomenator() == 3);
    REQUIRE(res2.get_numerator() == 5);
    REQUIRE(res2.get_denomenator() == 3);
}

TEST_CASE("fraction integer multiplication", "[fraction][arithmetic]")
{
    Fraction f(1, 3);

    Fraction res1 = f * 2;
    Fraction res2 = 2 * f;

    REQUIRE(res1.get_numerator() == 2);
    REQUIRE(res1.get_denomenator() == 3);
    REQUIRE(res2.get_numerator() == 2);
    REQUIRE(res2.get_denomenator() == 3);
}

TEST_CASE("fraction integer division", "[fraction][arithmetic]")
{
    Fraction f(1, 3);

    Fraction res1 = f / 2;
    Fraction res2 = 2 / f;

    REQUIRE(res1.get_numerator() == 1);
    REQUIRE(res1.get_denomenator() == 6);
    REQUIRE(res2.get_numerator() == 6);
    REQUIRE(res2.get_denomenator() == 1);
}

TEST_CASE("fraction integer modulo", "[fraction][arithmetic]")
{
    Fraction f(1, 3);

    Fraction res1 = f % 2;
    Fraction res2 = 2 % f;

    REQUIRE(res1.get_numerator() == 1);
    REQUIRE(res1.get_denomenator() == 3);
    REQUIRE(res2.get_numerator() == 0);
    REQUIRE(res2.get_denomenator() == 1);
}

TEST_CASE("fraction absolute value", "[fraction]")
{
    Fraction f1(2, 5), f2(-4, 7), f3(-5, -8), f4(7, -9);

    REQUIRE(abs(f1).get_numerator() == 2);
    REQUIRE(abs(f1).get_denomenator() == 5);
    REQUIRE(abs(f2).get_numerator() == 4);
    REQUIRE(abs(f2).get_denomenator() == 7);
    REQUIRE(abs(f3).get_numerator() == 5);
    REQUIRE(abs(f3).get_denomenator() == 8);
    REQUIRE(abs(f4).get_numerator() == 7);
    REQUIRE(abs(f4).get_denomenator() == 9);
}

TEST_CASE("fraction rounding", "[fraction]")
{
    Fraction f1(4), f2(4, 5), f3(6, 5), f4(8, 5), f5(11, 5);

    REQUIRE(round(f1) == 4);
    REQUIRE(round(f2) == 1);
    REQUIRE(round(f3) == 1);
    REQUIRE(round(f4) == 2);
    REQUIRE(round(f5) == 2);
}

TEST_CASE("fraction flooring", "[fraction]")
{
    Fraction f1(4), f2(4, 5), f3(6, 5), f4(8, 5), f5(11, 5);

    REQUIRE(floor(f1) == 4);
    REQUIRE(floor(f2) == 0);
    REQUIRE(floor(f3) == 1);
    REQUIRE(floor(f4) == 1);
    REQUIRE(floor(f5) == 2);
}

TEST_CASE("fraction ceiling", "[fraction]")
{
    Fraction f1(4), f2(4, 5), f3(6, 5), f4(8, 5), f5(11, 5);

    REQUIRE(ceil(f1) == 4);
    REQUIRE(ceil(f2) == 1);
    REQUIRE(ceil(f3) == 2);
    REQUIRE(ceil(f4) == 2);
    REQUIRE(ceil(f5) == 3);
}

TEST_CASE("fraction powers", "[fraction]")
{
    Fraction f1(2), f2(1, 2), f3(6, 5);

    REQUIRE(pow(f1, 4).get_numerator() == 16);
    REQUIRE(pow(f1, 4).get_denomenator() == 1);
    REQUIRE(pow(f2, 4).get_numerator() == 1);
    REQUIRE(pow(f2, 4).get_denomenator() == 16);
    REQUIRE(pow(f3, 4).get_numerator() == 1296);
    REQUIRE(pow(f3, 4).get_denomenator() == 625);
}

TEST_CASE("fraction equality", "[fraction][arithmetic]")
{
    Fraction f1(1, 3), f2(-1, 3), f3(-1, 3), f4(-2, 5), f5(1, 5);

    REQUIRE(!(f1 == f2));
    REQUIRE((f2 == f3));
    REQUIRE(!(f3 == f4));
    REQUIRE(!(f4 == f5));
}

TEST_CASE("fraction inequality", "[fraction][arithmetic]")
{
    Fraction f1(1, 3), f2(-1, 3), f3(-1, 3), f4(-2, 5), f5(1, 5);

    REQUIRE((f1 != f2));
    REQUIRE(!(f2 != f3));
    REQUIRE((f3 != f4));
    REQUIRE((f4 != f5));
}

TEST_CASE("fraction less than", "[fraction][arithmetic]")
{
    Fraction f1(1, 3), f2(-1, 3), f3(-1, 3), f4(-2, 5), f5(1, 5);

    REQUIRE(!(f1 < f2));
    REQUIRE(!(f2 < f3));
    REQUIRE(!(f3 < f4));
    REQUIRE((f4 < f5));
}

TEST_CASE("fraction greater than", "[fraction][arithmetic]")
{
    Fraction f1(1, 3), f2(-1, 3), f3(-1, 3), f4(-2, 5), f5(1, 5);

    REQUIRE((f1 > f2));
    REQUIRE(!(f2 > f3));
    REQUIRE((f3 > f4));
    REQUIRE(!(f4 > f5));
}

TEST_CASE("fraction less than equal", "[fraction][arithmetic]")
{
    Fraction f1(1, 3), f2(-1, 3), f3(-1, 3), f4(-2, 5), f5(1, 5);

    REQUIRE(!(f1 <= f2));
    REQUIRE((f2 <= f3));
    REQUIRE(!(f3 <= f4));
    REQUIRE((f4 <= f5));
}

TEST_CASE("fraction greater than equal", "[fraction][arithmetic]")
{
    Fraction f1(1, 3), f2(-1, 3), f3(-1, 3), f4(-2, 5), f5(1, 5);

    REQUIRE((f1 >= f2));
    REQUIRE((f2 >= f3));
    REQUIRE((f3 >= f4));
    REQUIRE(!(f4 >= f5));
}

TEST_CASE("fraction integer equality", "[fraction][arithmetic]")
{
    Fraction f1(1, 3), f2(4, 3), f3(-3, 5), f4(4);

    REQUIRE(!(f1 == 0));
    REQUIRE(!(f2 == 1));
    REQUIRE(!(f3 == -1));
    REQUIRE((f4 == 4));
}

TEST_CASE("fraction integer inequality", "[fraction][arithmetic]")
{
    Fraction f1(1, 3), f2(4, 3), f3(-3, 5), f4(4);

    REQUIRE((f1 != 0));
    REQUIRE((f2 != 1));
    REQUIRE((f3 != -1));
    REQUIRE(!(f4 != 4));
}

TEST_CASE("fraction integer less than", "[fraction][arithmetic]")
{
    Fraction f1(1, 3), f2(4, 3), f3(-3, 5), f4(4);

    REQUIRE(!(f1 < 0));
    REQUIRE((f1 < 1));
    REQUIRE(!(f2 < 1));
    REQUIRE((f2 < 2));
    REQUIRE(!(f3 < -1));
    REQUIRE((f3 < 0));
    REQUIRE(!(f4 < 3));
    REQUIRE(!(f4 < 4));
    REQUIRE((f4 < 5));
}

TEST_CASE("fraction integer greater than", "[fraction][arithmetic]")
{
    Fraction f1(1, 3), f2(4, 3), f3(-3, 5), f4(4);

    REQUIRE((f1 > 0));
    REQUIRE(!(f1 > 1));
    REQUIRE((f2 > 1));
    REQUIRE(!(f2 > 2));
    REQUIRE((f3 > -1));
    REQUIRE(!(f3 > 0));
    REQUIRE((f4 > 3));
    REQUIRE(!(f4 > 4));
    REQUIRE(!(f4 > 5));
}

TEST_CASE("fraction integer less than equal", "[fraction][arithmetic]")
{
    Fraction f1(1, 3), f2(4, 3), f3(-3, 5), f4(4);

    REQUIRE(!(f1 <= 0));
    REQUIRE((f1 <= 1));
    REQUIRE(!(f2 <= 1));
    REQUIRE((f2 <= 2));
    REQUIRE(!(f3 <= -1));
    REQUIRE((f3 <= 0));
    REQUIRE(!(f4 <= 3));
    REQUIRE((f4 <= 4));
    REQUIRE((f4 <= 5));
}

TEST_CASE("fraction integer greater than equal", "[fraction][arithmetic]")
{
    Fraction f1(1, 3), f2(4, 3), f3(-3, 5), f4(4);

    REQUIRE((f1 >= 0));
    REQUIRE(!(f1 >= 1));
    REQUIRE((f2 >= 1));
    REQUIRE(!(f2 >= 2));
    REQUIRE((f3 >= -1));
    REQUIRE(!(f3 >= 0));
    REQUIRE((f4 >= 3));
    REQUIRE((f4 >= 4));
    REQUIRE(!(f4 >= 5));
}
