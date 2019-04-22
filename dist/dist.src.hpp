#pragma once

#include "../outcome/outcome.hpp"
#include "../util/tree.hpp"

class Dist
{
  Tree _outcomes;

  void _normalize(void);

public:
  Dist(void) = default;
  Dist(const Dist &other) = default;
  Dist(const Fraction &frac);

  Dist &operator=(const Dist &other);
  // Dist &operator=(Dist &&other);

  void insert(const Outcome outcome);

  Dist &operator+=(const Dist &other);
  Dist &operator-=(const Dist &other);
  Dist &operator*=(const Dist &other);
  Dist &operator/=(const Dist &other);
  Dist &operator%=(const Dist &other);

  Tree::iterator begin(void);
  Tree::iterator end(void);
  Tree::const_iterator begin(void) const;
  Tree::const_iterator end(void) const;

  friend Dist operator+(const Dist &lhs, const Dist &rhs);
  friend Dist operator-(const Dist &lhs, const Dist &rhs);
  friend Dist operator*(const Dist &lhs, const Dist &rhs);
  friend Dist operator/(const Dist &lhs, const Dist &rhs);
  friend Dist operator%(const Dist &lhs, const Dist &rhs);
};

Dist operator+(const Dist &lhs, const Dist &rhs);
Dist operator-(const Dist &lhs, const Dist &rhs);
Dist operator*(const Dist &lhs, const Dist &rhs);
Dist operator/(const Dist &lhs, const Dist &rhs);
Dist operator%(const Dist &lhs, const Dist &rhs);