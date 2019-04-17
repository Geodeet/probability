#include "dist.src.hpp"

void Dist::_normalize(void)
{
}

Dist &Dist::operator=(const Dist &other)
{
    _outcomes = other._outcomes.copy();
}