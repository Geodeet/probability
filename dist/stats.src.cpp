#include "stats.src.hpp"

Fraction mean(const Dist &dist)
{
    return moment(1, dist);
}

Fraction variance(const Dist &dist)
{
    // return moment(2, dist) - pow(mean(dist), 2);
    Dist centralized = dist - mean(dist);

    return moment(2, centralized);
}

Fraction skewness(const Dist &dist)
{

}

Fraction kurtosis(const Dist &dist)
{

}

Fraction moment(const int n, const Dist &dist)
{
    Fraction result(0);

    for (auto o : dist)
        result += pow(o.value, n) * o.probability;

    return result;
}
