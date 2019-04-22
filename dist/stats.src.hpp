#pragma once

#include "dist.src.hpp"

Fraction mean(const Dist &dist);
Fraction variance(const Dist &dist);
// skewness can only be computed exact if it's squared
// Fraction skewness_squared(const Dist &dist);
Fraction kurtosis(const Dist &dist);

Fraction moment(const int n, const Dist &dist);