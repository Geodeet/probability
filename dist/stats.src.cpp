#include "stats.src.hpp"

Fraction mean(const Dist &dist)
{
    Fraction result(0);

    for (auto s : dist)
        result += s.value * s.probability;

    return result;
}

Fraction variance(const Dist &dist)
{
    Fraction result(0);

    for (auto s : dist)
        result += s.value * s.value * s.probability;

    Fraction meansq = mean(dist);
    meansq *= meansq;

    return result - meansq;
}