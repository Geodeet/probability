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
