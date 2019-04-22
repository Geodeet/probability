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

// Fraction skewness_squared(const Dist &dist)
// {
//     Dist centralized = (dist - mean(dist));

//     return pow(moment(3, centralized), 2) / pow(variance(dist), 3);
// }

Fraction kurtosis(const Dist &dist)
{
    Dist centralized = dist - mean(dist);

    return moment(4, centralized) / pow(variance(dist), 2);
}

Fraction moment(const int n, const Dist &dist)
{
    Fraction result(0);

    for (auto o : dist)
        result += pow(o.value, n) * o.probability;

    return result;
}

Fraction mode(const Dist &dist)
{
    Tree::const_iterator iter = dist.begin();

    Fraction maxval = iter->value;
    Fraction maxprob = iter->probability;

    while (++iter != dist.end())
        if (iter->probability > maxprob)
        {
            maxval = iter->value;
            maxprob = iter->probability;
        }

    return maxval;
}

Fraction median(const Dist &dist)
{
    return percentile(50, dist);
}

Fraction percentile(const Fraction percent, const Dist &dist)
{
    if (percent < 0 || 100 < percent)
        throw std::out_of_range("percentile not between 0 and 100");

    Tree::const_iterator iter = dist.begin();
    Fraction accumulator = 0;

    while (iter != dist.end())
    {
        Fraction next_accumulator = accumulator + iter->probability * 100;

        if ((accumulator <= percent && percent < next_accumulator) || next_accumulator == 100)
            return iter->value;

        accumulator = next_accumulator;
        ++iter;
    }

    throw std::out_of_range("distribution not normalized in percentile computation");
}
