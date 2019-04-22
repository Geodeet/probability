#include "arithmetic.src.hpp"

// Addition of two fractions
Fraction operator+(const Fraction &A, const Fraction &B)
{
    // New fraction is obtained through
    // a/b + c/d = (ad + bc) / bd
    return Fraction(A._numer * B._denom + B._numer * A._denom, A._denom * B._denom);
}

// Addition of a fraction and an integer
Fraction operator+(const Fraction &A, const int &Bi)
{
    // We use the addition of two fractions
    return (A + Fraction(Bi));
}

// Addition of an integer and a fraction
Fraction operator+(const int &Ai, const Fraction &B)
{
    // We use the addition of two fractions
    return (Fraction(Ai) + B);
}

// Subtraction of two fractions
Fraction operator-(const Fraction &A, const Fraction &B)
{
    // New fraction is obtained through
    // a/b - c/d = (ad - bc) / bd
    return Fraction(A._numer * B._denom - B._numer * A._denom, A._denom * B._denom);
}

// Subtraction of a fraction and an integer
Fraction operator-(const Fraction &A, const int &Bi)
{
    // We use the subtraction of two fractions
    return (A - Fraction(Bi));
}

// Subtraction of an integer and a fraction
Fraction operator-(const int &Ai, const Fraction &B)
{
    // We use the subtraction of two fractions
    return (Fraction(Ai) - B);
}

// Multiplication of two fractions
Fraction operator*(const Fraction &A, const Fraction &B)
{
    // New fraction is obtained through
    // a/b * c/d = (ac) / (bd)
    return Fraction(A._numer * B._numer, A._denom * B._denom);
}

// Multiplication of a fraction and an integer
Fraction operator*(const Fraction &A, const int &Bi)
{
    // We use the multiplication of two fractions
    return (A * Fraction(Bi));
}

// Multiplication of an integer and a fraction
Fraction operator*(const int &Ai, const Fraction &B)
{
    // We use the multiplication of two fractions
    return (Fraction(Ai) * B);
}

// Division of two fractions
Fraction operator/(const Fraction &A, const Fraction &B)
{
    // New fraction is obtained through
    // a/b / c/d = (ad) / (bc)
    return Fraction(A._numer * B._denom, B._numer * A._denom);
}

// Division of a fraction and an integer
Fraction operator/(const Fraction &A, const int &Bi)
{
    // We use the division of two fractions
    return (A / Fraction(Bi));
}

// Division of an integer and a fraction
Fraction operator/(const int &Ai, const Fraction &B)
{
    // We use the division of two fractions
    return (Fraction(Ai) / B);
}

// Function that returns the increment needed in the modulo operator
Fraction find_increment(const Fraction &original, const Fraction &modulo)
{
    Fraction incr(modulo);

    // Check whether we are smaller than the requested interval
    if ((original <= modulo) and (original <= modulo * -1))
    {
        // If that is the case we need to increment with a positive fraction
        if (incr < 0)
        {
            incr *= -1;
        }
    }

    // Check whether we are larger than the requested interval
    if ((original >= modulo) and (original >= modulo * -1))
    {
        // If that is the case we need to increment with a negative fraction
        if (incr > 0)
        {
            incr *= -1;
        }
    }

    return incr;
}

// Function that checks whether a fraction lies in an interval needed in the modulo operator
inline bool check_interval(const Fraction &frac, const Fraction &bound)
{
    return (((frac <= bound) and (frac <= bound * -1)) or ((frac >= bound) and (frac >= bound * -1)));
}

// Modulo of two fractions
Fraction operator%(const Fraction &A, const Fraction &B)
{
    // TODO this can be way optimized!

    // We need to keep subtracting or adding the other fraction until we have a fraction between -other and other
    Fraction incr = find_increment(A, B);
    Fraction new_frac = A;

    while (check_interval(new_frac, incr))
    {
        new_frac += incr;
    }

    // Simplify fraction if needed
    new_frac._simplify();

    return new_frac;
}

// Modulo of a fraction and an integer
Fraction operator%(const Fraction &A, const int &Bi)
{
    // We use the modulo operator for two fractions
    return (A % Fraction(Bi));
}

// Modulo of an integer and a fraction
Fraction operator%(const int &Ai, const Fraction &B)
{
    // We use the modulo operator for two fractions
    return (Fraction(Ai) % B);
}

// Get the absolute value of the fractions
Fraction abs(const Fraction &frac)
{
    // Create a copy with the absolute value of the numerator
    Fraction new_frac(std::abs(frac._numer), frac._denom);

    return new_frac;
}

// Round the fraction to the nearest integer
long long int round(const Fraction &frac)
{
    long long int base = frac._numer / frac._denom;

    if (frac._numer % frac._denom > frac._denom / 2)
    {
        return base + 1;
    }
    else
    {
        return base;
    }
}

// Lower the fraction to the nearest smaller integer
long long int floor(const Fraction &frac)
{
    return frac._numer / frac._denom;
}

// Raise the fraction to the nearest larger integer
long long int ceil(const Fraction &frac)
{
    if (frac._numer % frac._denom == 0)
    {
        return frac._numer / frac._denom;
    }
    else
    {
        return frac._numer / frac._denom + 1;
    }
}

// Compute the power with an integer exponent
Fraction pow(const Fraction &frac, int exponent)
{
    return Fraction(std::pow(frac._numer, exponent), std::pow(frac._denom, exponent));
}

// ===================== COMPARISON FUNCTIONS ===================================================
// NOTE: we define operator== and operator< explicitly and base all other operators on these

// Comparison operator
bool operator==(const Fraction &A, const Fraction &B)
{
    if (A._numer == B._numer and A._denom == B._denom)
    {
        return true;
    }

    // Then it is not equal
    return false;
}

// Comparison operator for fractions and integers
bool operator==(const Fraction &A, const int &Bi)
{
    // We use the comparison operator for fractions
    return (A == Fraction(Bi));
}

// Comparison operator for integers and fractions
bool operator==(const int &Ai, const Fraction &B)
{
    // We use the comparison operator for fractions
    return (Fraction(Ai) == B);
}

// Unequal comparison operator
bool operator!=(const Fraction &A, const Fraction &B)
{
    // We reuse the comparison operator
    return !(A == B);
}

// Unequal comparison operator for fractions and integers
bool operator!=(const Fraction &A, const int &Bi)
{
    // We use the unequal comparison operator for fractions
    return (A != Fraction(Bi));
}

// Unequal comparison operator for integers and fractions
bool operator!=(const int &Ai, const Fraction &B)
{
    // We use the unequal comparison operator for fractions
    return (Fraction(Ai) != B);
}

// Less than operator
bool operator<(const Fraction &A, const Fraction &B)
{
    long long int numA = A._numer * B._denom;
    long long int numB = B._numer * A._denom;

    return (numA < numB) ? true : false;
}

// Less than operator for fractions and integers
bool operator<(const Fraction &A, const int &Bi)
{
    // We use the less than operator for fractions
    return (A < Fraction(Bi));
}

// Less than operator for integers and fractions
bool operator<(const int &Ai, const Fraction &B)
{
    // We use the less than operator for fractions
    return (Fraction(Ai) < B);
}

// Greater than operator
bool operator>(const Fraction &A, const Fraction &B)
{
    // We base it on the less than and unequal operators
    return (!(A < B) and (A != B));
}

// Greater than operator for fractions and integers
bool operator>(const Fraction &A, const int &Bi)
{
    // We use the greater than operator for fractions
    return (A > Fraction(Bi));
}

// Greater than operator for integers and fractions
bool operator>(const int &Ai, const Fraction &B)
{
    // We use the greater than operator for fractions
    return (Fraction(Ai) > B);
}

// Less equal operator
bool operator<=(const Fraction &A, const Fraction &B)
{
    // We base it on the greater than operator
    return !(A > B);
}

// Less equal operator for fractions and integers
bool operator<=(const Fraction &A, const int &Bi)
{
    // We use the less equal operator for fractions
    return (A <= Fraction(Bi));
}

// Less equal operator for integers and fractions
bool operator<=(const int &Ai, const Fraction &B)
{
    // We use the less equal operator for fractions
    return (Fraction(Ai) <= B);
}

// Greater equal operator
bool operator>=(const Fraction &A, const Fraction &B)
{
    // We base it on the less than operator
    return !(A < B);
}

// Greater equal operator for fractions and integers
bool operator>=(const Fraction &A, const int &Bi)
{
    // We use the greater equal for fractions
    return (A >= Fraction(Bi));
}

// Greater equal operator for integers and fractions
bool operator>=(const int &Ai, const Fraction &B)
{
    // We use the greater equal for fractions
    return (Fraction(Ai) >= B);
}
