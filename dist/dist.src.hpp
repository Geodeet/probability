#pragma once

#include "../outcome/outcome.hpp"
#include "../util/tree.hpp"

class Dist
{
    Tree _outcomes;

    Fraction _normalize(void);

  public:
    Dist(void);

    Dist& operator=(const Dist &other);

    Dist& operator+=(const Dist &other);
    Dist& operator-=(const Dist &other);
    // ...
};
