#pragma once

#include "dist.src.hpp"

Fraction mean(const Dist &dist);
Fraction variance(const Dist &dist);
// skewness needs expressions (sqrt)
// Fraction skewness_squared(const Dist &dist);
Fraction kurtosis(const Dist &dist);

Fraction moment(const int n, const Dist &dist);

Fraction mode(const Dist &dist);

Fraction median(const Dist &dist);
Fraction percentile(const Fraction percent, const Dist &dist);

// entropy needs expressions (2log)
// Fraction entropy(const Dist &dist);