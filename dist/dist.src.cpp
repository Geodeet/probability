#include "dist.src.hpp"

void Dist::_normalize(void)
{
}

Dist &Dist::operator=(const Dist &other)
{
    _outcomes = other._outcomes;
}

Dist &Dist::operator+=(const Dist &other)
{
    

    for(auto outcome : other._outcomes)
    {

    }
}
