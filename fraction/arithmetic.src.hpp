/* FRACTION ARITHMETIC
    This file contains all arithmetic functions that are defined
    for fractions.
*/

#pragma once

#include "fraction.src.hpp"

// Some arithmetic for fractions
Fraction operator+(const Fraction &A, const Fraction &B);
Fraction operator-(const Fraction &A, const Fraction &B);
Fraction operator*(const Fraction &A, const Fraction &B);
Fraction operator/(const Fraction &A, const Fraction &B);
Fraction operator%(const Fraction &A, const Fraction &B);

Fraction operator+(const Fraction &A, const int &Bi);
Fraction operator-(const Fraction &A, const int &Bi);
Fraction operator*(const Fraction &A, const int &Bi);
Fraction operator/(const Fraction &A, const int &Bi);
Fraction operator%(const Fraction &A, const int &Bi);

Fraction operator+(const int &Ai, const Fraction &B);
Fraction operator-(const int &Ai, const Fraction &B);
Fraction operator*(const int &Ai, const Fraction &B);
Fraction operator/(const int &Ai, const Fraction &B);
Fraction operator%(const int &Ai, const Fraction &B);

Fraction abs(const Fraction &frac);
long long int round(const Fraction &frac);
long long int floor(const Fraction &frac);
long long int ceil(const Fraction &frac);
Fraction pow(const Fraction &frac, int exponent);

// Comparison operators
bool operator==(const Fraction &A, const Fraction &B);
bool operator!=(const Fraction &A, const Fraction &B);
bool operator<(const Fraction &A, const Fraction &B);
bool operator>(const Fraction &A, const Fraction &B);
bool operator<=(const Fraction &A, const Fraction &B);
bool operator>=(const Fraction &A, const Fraction &B);

bool operator==(const int &Ai, const Fraction &B);
bool operator!=(const int &Ai, const Fraction &B);
bool operator<(const int &Ai, const Fraction &B);
bool operator>(const int &Ai, const Fraction &B);
bool operator<=(const int &Ai, const Fraction &B);
bool operator>=(const int &Ai, const Fraction &B);

bool operator==(const Fraction &A, const int &Bi);
bool operator!=(const Fraction &A, const int &Bi);
bool operator<(const Fraction &A, const int &Bi);
bool operator>(const Fraction &A, const int &Bi);
bool operator<=(const Fraction &A, const int &Bi);
bool operator>=(const Fraction &A, const int &Bi);