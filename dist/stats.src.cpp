#include "stats.src.hpp"

Fraction mean(const Dist &dist)
{
    return moment(1, dist);
}

Fraction variance(const Dist &dist)
{
    return moment(2, dist) - pow(mean(dist), 2);
}

Fraction moment(const int n, const Dist &dist)
{
    Fraction result(0);

    for (auto o : dist)
        result += pow(o.value, n) * o.probability;

    return result;
}
