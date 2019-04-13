/* FRACTION CLASS
    Fractions consist of a numerator and a denomenator
    This class implements a lot over overloaded methods (for arithmetic etc.)
    Furthermore some simple mathematical functions are provided (e.g. absolute value)
    Also some pretty printing is supplied
*/

// TODO make fraction generic?

#pragma once

#include <iostream>
#include <cmath>

class Fraction
{
private:
  // The numerator and denomenator
  long long int _numer, _denom;

  // Simplify the fraction as much as possible
  void _simplify(void);

public:
  // Constructors
  Fraction(void);
  Fraction(const int num);
  Fraction(const Fraction &frac);
  Fraction(const int numer, const int denom);

  // Some simple mathematical expressions with fractions
  Fraction abs(void) const;
  long long int round(void) const;
  long long int floor(void) const;
  long long int ceil(void) const;
  double as_double(void) const;
  long long int get_numerator(void) const;
  long long int get_denomenator(void) const;
  Fraction pow(int exponent) const;

  // Displaying the number
  std::string as_string(void) const;
  void print(void) const;

  // Assignment arithmetic
  Fraction &operator+=(const Fraction &other);
  Fraction &operator-=(const Fraction &other);
  Fraction &operator*=(const Fraction &other);
  Fraction &operator/=(const Fraction &other);
  Fraction &operator%=(const Fraction &other);

  Fraction &operator+=(const int &other);
  Fraction &operator-=(const int &other);
  Fraction &operator*=(const int &other);
  Fraction &operator/=(const int &other);
  Fraction &operator%=(const int &other);

  // Unary operators
  Fraction operator-(void) const;

  // Assignment
  Fraction &operator=(const Fraction &other);

  Fraction &operator=(const int &other);

  // Increment/decrement operators (work on enumerator only)
  Fraction &operator++(void);
  Fraction &operator--(void);
  Fraction operator++(int);
  Fraction operator--(int);

  // The arithmetic functions are befriended here
  friend Fraction operator+(const Fraction &current, const Fraction &other);
  friend Fraction operator-(const Fraction &current, const Fraction &other);
  friend Fraction operator*(const Fraction &current, const Fraction &other);
  friend Fraction operator/(const Fraction &current, const Fraction &other);
  friend Fraction operator%(const Fraction &current, const Fraction &other);

  friend Fraction operator+(const Fraction &current, const int &other);
  friend Fraction operator-(const Fraction &current, const int &other);
  friend Fraction operator*(const Fraction &current, const int &other);
  friend Fraction operator/(const Fraction &current, const int &other);
  friend Fraction operator%(const Fraction &current, const int &other);

  friend Fraction operator+(const int &current, const Fraction &other);
  friend Fraction operator-(const int &current, const Fraction &other);
  friend Fraction operator*(const int &current, const Fraction &other);
  friend Fraction operator/(const int &current, const Fraction &other);
  friend Fraction operator%(const int &current, const Fraction &other);

  // The comparison functions are befriended here
  friend bool operator==(const Fraction &A, const Fraction &B);
  friend bool operator!=(const Fraction &A, const Fraction &B);
  friend bool operator<(const Fraction &A, const Fraction &B);
  friend bool operator>(const Fraction &A, const Fraction &B);
  friend bool operator<=(const Fraction &A, const Fraction &B);
  friend bool operator>=(const Fraction &A, const Fraction &B);

  friend bool operator==(const int &Ai, const Fraction &B);
  friend bool operator!=(const int &Ai, const Fraction &B);
  friend bool operator<(const int &Ai, const Fraction &B);
  friend bool operator>(const int &Ai, const Fraction &B);
  friend bool operator<=(const int &Ai, const Fraction &B);
  friend bool operator>=(const int &Ai, const Fraction &B);

  friend bool operator==(const Fraction &A, const int &Bi);
  friend bool operator!=(const Fraction &A, const int &Bi);
  friend bool operator<(const Fraction &A, const int &Bi);
  friend bool operator>(const Fraction &A, const int &Bi);
  friend bool operator<=(const Fraction &A, const int &Bi);
  friend bool operator>=(const Fraction &A, const int &Bi);

  friend std::ostream& operator<<(std::ostream &os, const Fraction fraction);
};
