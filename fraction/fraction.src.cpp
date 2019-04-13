#include "fraction.src.hpp"

// Testing a new simplification method
void Fraction::_simplify(void)
{
  // Check whether we have the number zero, then we simply put the denomenator to 1
  if (_numer == 0)
  {
    _denom = 1;
    return;
  }

  // Check whether we have the number one
  if (_numer == _denom)
  {
    _numer = 1;
    _denom = 1;
    return;
  }

  // First make sure only the numerator can be negative
  if (_denom < 0)
  {
    _numer *= -1;
    _denom *= -1;
  }

  // Now we apply the algorithm of Euclid
  long long int a = std::abs(_numer);
  long long int b = _denom;

  while (a != b)
    if (a > b)
      a -= b;
    else
      b -= a;

  _numer /= a;
  _denom /= a;
}

// Default constructor
Fraction::Fraction(void)
{
  // Simply initialize to 1/1
  _numer = 1;
  _denom = 1;
}

// Constructor from integer
Fraction::Fraction(const int num)
{
  // Simply initialize to num/1
  _numer = num;
  _denom = 1;
}

// Copy constructor
Fraction::Fraction(const Fraction &frac)
{
  // Copy the values of the other fraction
  _numer = frac._numer;
  _denom = frac._denom;

  // Simplify the fraction if needed
  _simplify();
}

// Constructor from two integers
Fraction::Fraction(const int numer, const int denom)
{
  _numer = numer;
  _denom = denom;

  // Simplify the fraction if needed
  _simplify();
}

// Addition assignment
Fraction &Fraction::operator+=(const Fraction &other)
{
  // New fraction is obtained through
  // a/b + c/d = (ad + bc) / bd
  _numer = _numer * other._denom + other._numer * _denom;
  _denom *= other._denom;

  // Simplify the fraction
  _simplify();

  return *this;
}

// Addition assignment for integers
Fraction &Fraction::operator+=(const int &other)
{
  // We use the addition assignment for fractions
  return operator+=(Fraction(other));
}

// Subtraction assignment
Fraction &Fraction::operator-=(const Fraction &other)
{
  // New fraction is obtained through
  // a/b - c/d = (ad - bc) / bd
  _numer = _numer * other._denom - other._numer * _denom;
  _denom *= other._denom;

  // Simplify the fraction
  _simplify();

  return *this;
}

// Subtraction assignment for integers
Fraction &Fraction::operator-=(const int &other)
{
  // We use the subtraction assignment for fractions
  return operator-=(Fraction(other));
}

// Multiplication assignment
Fraction &Fraction::operator*=(const Fraction &other)
{
  // New fraction is obtained through
  // a/b * c/d = (ac) / (bd)
  _numer *= other._numer;
  _denom *= other._denom;

  // Simplify the fraction
  _simplify();

  return *this;
}

// Multiplication assignment for integers
Fraction &Fraction::operator*=(const int &other)
{
  // We use the multiplication assignment for fractions
  return operator*=(Fraction(other));
}

// Division assignment
Fraction &Fraction::operator/=(const Fraction &other)
{
  // New fraction is obtained through
  // a/b / c/d = (ad) / (bc)
  _numer *= other._denom;
  _denom *= other._numer;

  // Simplify the fraction
  _simplify();

  return *this;
}

// Division assignment for integers
Fraction &Fraction::operator/=(const int &other)
{
  // We use the division assignment for fractions
  return operator/=(Fraction(other));
}

// Modulo assignment
Fraction &Fraction::operator%=(const Fraction &other)
{
  // New fraction is obtained by using the modulo operator
  *this = *this % other;

  return *this;
}

// Modulo assignment for integers
Fraction &Fraction::operator%=(const int &other)
{
  // We use the modulo assignment for fractions
  return operator%=(Fraction(other));
}

// Negation operator
Fraction Fraction::operator-(void) const
{
  return Fraction(-1 * _numer, _denom);
}

// Assignment operator
Fraction &Fraction::operator=(const Fraction &other)
{
  // Simply copy the numerator and denomenator
  _numer = other._numer;
  _denom = other._denom;

  return *this;
}

// Assignment operator for integers
Fraction &Fraction::operator=(const int &other)
{
  // Simply copy the integer into the numerator
  _numer = other;
  _denom = 1;

  return *this;
}

// Prefix increment operator
Fraction &Fraction::operator++(void)
{
  // Simply increment the numerator
  _numer++;

  // Simplify fraction if needed
  _simplify();

  return *this;
}

// Prefix decrement operator
Fraction &Fraction::operator--(void)
{
  // Simply decrement the numerator
  _numer--;

  // Simplify fraction if needed
  _simplify();

  return *this;
}

// Postfix increment operator
Fraction Fraction::operator++(int)
{
  // Create a temporary copy
  Fraction copy(*this);

  // Use prefix increment on self
  ++(*this);

  // Simplify if needed
  _simplify();

  // Return the original state
  return copy;
}

// Postfix decrement operator
Fraction Fraction::operator--(int)
{
  // Create a temporary copy
  Fraction copy(*this);

  // Use prefix decrement on self
  --(*this);

  // Simplify if needed
  _simplify();

  // Return the original state
  return copy;
}

// Get the absolute value of the fractions
Fraction Fraction::abs(void) const
{
  // Create a copy with the absolute value of the numerator
  Fraction new_frac(std::abs(_numer), _denom);

  return new_frac;
}

// Round the fraction to the nearest integer
long long int Fraction::round(void) const
{
  long long int base = _numer / _denom;

  if (_numer % _denom > _denom / 2)
  {
    return base + 1;
  }
  else
  {
    return base;
  }
}

// Lower the fraction to the nearest smaller integer
long long int Fraction::floor(void) const
{
  return _numer / _denom;
}

// Raise the fraction to the nearest larger integer
long long int Fraction::ceil(void) const
{
  if (_numer % _denom == 0)
  {
    return _numer / _denom;
  }
  else
  {
    return _numer / _denom + 1;
  }
}

// Return the fraction as a double
double Fraction::as_double(void) const
{
  return (((double)_numer) / ((double)_denom));
}

// Return a copy of the numerator
long long int Fraction::get_numerator(void) const
{
  return _numer;
}

// Return a copy of the denomenator
long long int Fraction::get_denomenator(void) const
{
  return _denom;
}

// Recursive power computation
Fraction power_iteration(const Fraction &base, int exponent)
{
  if (exponent == 0)
  {
    return Fraction(1);
  }
  else if (exponent > 0)
  {
    return base * power_iteration(base, --exponent);
  }
  else
  {
    return base * power_iteration(base, ++exponent);
  }
}

// Compute the power with an integer exponent
Fraction Fraction::pow(int exponent) const
{
  return power_iteration(Fraction(_numer, _denom), exponent);
}

// Give fraction as string
std::string Fraction::as_string(void) const
{
  // Simply return the fraction as string
  if (_denom != 1)
  {
    return std::to_string(_numer) + " / " + std::to_string(_denom);
  }
  else
  {
    return std::to_string(_numer);
  }
}

// Print fraction to std out
void Fraction::print(void) const
{
  std::cout << this->as_string();
}

// Streaming operator
std::ostream& operator<<(std::ostream &os, const Fraction fraction)
{
  os << fraction.as_string();

  return os;
}
