#pragma once

#include "dist.src.hpp"

Fraction mean(const Dist &dist);

Fraction variance(const Dist &dist);

Fraction moment(const int n, const Dist &dist);