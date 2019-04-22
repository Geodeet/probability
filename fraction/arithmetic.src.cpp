#include "arithmetic.src.hpp"

// Addition of two fractions
Fraction operator+(const Fraction &A, const Fraction &B)
{
    // New fraction is obtained through
    // a/b + c/d = (ad + bc) / bd
    return Fraction(A._numer * B._denom + B._numer * A._denom, A._denom * B._denom);
}

// Subtraction of two fractions
Fraction operator-(const Fraction &A, const Fraction &B)
{
    // New fraction is obtained through
    // a/b - c/d = (ad - bc) / bd
    return Fraction(A._numer * B._denom - B._numer * A._denom, A._denom * B._denom);
}

// Multiplication of two fractions
Fraction operator*(const Fraction &A, const Fraction &B)
{
    // New fraction is obtained through
    // a/b * c/d = (ac) / (bd)
    return Fraction(A._numer * B._numer, A._denom * B._denom);
}

// Division of two fractions
Fraction operator/(const Fraction &A, const Fraction &B)
{
    // New fraction is obtained through
    // a/b / c/d = (ad) / (bc)
    return Fraction(A._numer * B._denom, B._numer * A._denom);
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

// Unequal comparison operator
bool operator!=(const Fraction &A, const Fraction &B)
{
    // We reuse the comparison operator
    return !(A == B);
}

// Less than operator
bool operator<(const Fraction &A, const Fraction &B)
{
    long long int numA = A._numer * B._denom;
    long long int numB = B._numer * A._denom;

    return (numA < numB) ? true : false;
}

// Greater than operator
bool operator>(const Fraction &A, const Fraction &B)
{
    // We base it on the less than and unequal operators
    return (!(A < B) and (A != B));
}

// Less equal operator
bool operator<=(const Fraction &A, const Fraction &B)
{
    // We base it on the greater than operator
    return !(A > B);
}

// Greater equal operator
bool operator>=(const Fraction &A, const Fraction &B)
{
    // We base it on the less than operator
    return !(A < B);
}
