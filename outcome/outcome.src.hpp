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

  friend std::ostream& operator<<(std::ostream &os, const Outcome outcome);

  // Some befriended comparison operators (all working on the value member)
  friend bool operator==(const Outcome &A, const Outcome &B);
  friend bool operator!=(const Outcome &A, const Outcome &B);
  friend bool operator<(const Outcome &A, const Outcome &B);
  friend bool operator>(const Outcome &A, const Outcome &B);
  friend bool operator<=(const Outcome &A, const Outcome &B);
  friend bool operator>=(const Outcome &A, const Outcome &B);
};

bool operator==(const Outcome &A, const Outcome &B);
bool operator!=(const Outcome &A, const Outcome &B);
bool operator<(const Outcome &A, const Outcome &B);
bool operator>(const Outcome &A, const Outcome &B);
bool operator<=(const Outcome &A, const Outcome &B);
bool operator>=(const Outcome &A, const Outcome &B);

std::ostream& operator<<(std::ostream &os, const Outcome outcome);