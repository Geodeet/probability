#include "outcome.src.hpp"

// Default constructor
Outcome::Outcome(void)
{
  value = Fraction(1);
  probability = Fraction(1);
};

// Copy constructor
Outcome::Outcome(const Outcome &other)
{
  value = other.value;
  probability = other.probability;
};

// Copy constructor from just a value
Outcome::Outcome(const int nvalue)
{
  value = Fraction(nvalue);
  probability = Fraction(1);
}

// Copy constructor from just a value
Outcome::Outcome(const Fraction &nvalue)
{
  value = nvalue;
  probability = Fraction(1);
}

// Copy constructor from separate values
Outcome::Outcome(const int nvalue, const int nprobability)
{
  value = Fraction(nvalue);
  probability = Fraction(nprobability);
}

// Copy constructor from separate values
Outcome::Outcome(const Fraction &nvalue, const int nprobability)
{
  value = nvalue;
  probability = Fraction(nprobability);
}

// Copy constructor from separate values
Outcome::Outcome(const int nvalue, const Fraction &nprobability)
{
  value = Fraction(nvalue);
  probability = nprobability;
};

// Copy constructor from separate values
Outcome::Outcome(const Fraction &nvalue, const Fraction &nprobability)
{
  value = nvalue;
  probability = nprobability;
};

Outcome operator+(const Outcome &lhs, const Outcome &rhs)
{
  return Outcome(lhs.value + rhs.value, lhs.probability * rhs.probability);
}

Outcome operator-(const Outcome &lhs, const Outcome &rhs)
{
  return Outcome(lhs.value - rhs.value, lhs.probability * rhs.probability);
}

Outcome operator*(const Outcome &lhs, const Outcome &rhs)
{
  return Outcome(lhs.value * rhs.value, lhs.probability * rhs.probability);
}

Outcome operator/(const Outcome &lhs, const Outcome &rhs)
{
  return Outcome(lhs.value / rhs.value, lhs.probability * rhs.probability);
}

Outcome operator%(const Outcome &lhs, const Outcome &rhs)
{
  return Outcome(lhs.value % rhs.value, lhs.probability * rhs.probability);
}

// Comparison operator
bool operator==(const Outcome &lhs, const Outcome &rhs)
{
  return (lhs.value == rhs.value);
};

// Unequal comparison operator
bool operator!=(const Outcome &lhs, const Outcome &rhs)
{
  return !(lhs == rhs);
};

// Less than comparison operator
bool operator<(const Outcome &lhs, const Outcome &rhs)
{
  return (lhs.value < rhs.value);
};

// Greater than comparison operator
bool operator>(const Outcome &lhs, const Outcome &rhs)
{
  return (!(lhs < rhs) and (lhs != rhs));
};

// Less than equal comparison operator
bool operator<=(const Outcome &lhs, const Outcome &rhs)
{
  return !(lhs > rhs);
};

// Greater than equal comparison operator
bool operator>=(const Outcome &lhs, const Outcome &rhs)
{
  return !(lhs < rhs);
};

std::ostream &operator<<(std::ostream &os, const Outcome outcome)
{
  os << "(" << outcome.value << "," << outcome.probability << ")";

  return os;
}
