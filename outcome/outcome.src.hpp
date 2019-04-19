/* OUTCOME CLASS
    This class represent one concrete outcome of a discrete distribution
    Therefore it holds an outcome value and a probability on that value
    Furthermore some comparison operators are provided
*/

#pragma once

#include <ostream>

#include "../fraction/fraction.hpp"

// A distribution is a collection of outcomes, each of which has a value and a probability
class Outcome
{
public:
  // The two member values
  Fraction value;
  Fraction probability;

  // Some constructors for this structure
  Outcome(void);
  Outcome(const Outcome &other);
  Outcome(const int value);
  Outcome(const Fraction &value);
  Outcome(const int value, const int probability);
  Outcome(const Fraction &value, const int probability);
  Outcome(const int value, const Fraction &probability);
  Outcome(const Fraction &value, const Fraction &probability);
};

Outcome operator+(const Outcome &lhs, const Outcome &rhs);
Outcome operator-(const Outcome &lhs, const Outcome &rhs);
Outcome operator*(const Outcome &lhs, const Outcome &rhs);
Outcome operator/(const Outcome &lhs, const Outcome &rhs);
Outcome operator%(const Outcome &lhs, const Outcome &rhs);

bool operator==(const Outcome &lhs, const Outcome &rhs);
bool operator!=(const Outcome &lhs, const Outcome &rhs);
bool operator<(const Outcome &lhs, const Outcome &rhs);
bool operator>(const Outcome &lhs, const Outcome &rhs);
bool operator<=(const Outcome &lhs, const Outcome &rhs);
bool operator>=(const Outcome &lhs, const Outcome &rhs);

std::ostream& operator<<(std::ostream &os, const Outcome outcome);