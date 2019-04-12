#include "fraction.hpp"

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
std::ostream& Fraction::operator<<(std::ostream &os) const
{
  os << this->as_string();

  return os;
}

// ======================== ARITHMETIC FUNCTIONS ==============================

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