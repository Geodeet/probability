#include "stats.src.hpp"

Fraction mean(const Dist &dist)
{
    Fraction result(0);

    for (auto o : dist)
        result += o.value * o.probability;

    return result;
}

Fraction variance(const Dist &dist)
{
    Fraction result(0);

    for (auto o : dist)
        result += o.value * o.value * o.probability;

    Fraction meansq = mean(dist);
    meansq *= meansq;

    return result - meansq;
}

Fraction moment(const int n, const Dist &dist)
{
    Fraction result(0);

    for (auto o: dist)
        result += pow()
}
