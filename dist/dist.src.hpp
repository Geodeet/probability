#pragma once

#include "../outcome/outcome.hpp"
#include "../util/tree.hpp"

class Dist
{
  Tree _outcomes;

  void _normalize(void);

public:
  Dist &operator=(const Dist &other);

  Dist &operator+=(const Dist &other);
  Dist &operator-=(const Dist &other);
  Dist &operator*=(const Dist &other);
  Dist &operator/=(const Dist &other);
  Dist &operator%=(const Dist &other);
  // ...
};
