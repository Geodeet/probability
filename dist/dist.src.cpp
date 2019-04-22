#include "dist.src.hpp"

Dist::Dist(const Fraction &frac)
{
    insert(Outcome(frac, 1));
}

void Dist::_normalize(void)
{
    Fraction norm(0);

    for (auto o : _outcomes)
        norm += o.probability;

    for (auto o : _outcomes)
        o.probability /= norm;
}

Dist &Dist::operator=(const Dist &other)
{
    _outcomes = other._outcomes;

    return *this;
}

void Dist::insert(const Outcome outcome)
{
    _outcomes.insert(outcome);
}

Dist &Dist::operator+=(const Dist &other)
{
    Tree result;

    for (auto t : _outcomes)
        for (auto o : other._outcomes)
            result.insert(t + o);

    _outcomes = result;

    _normalize();

    return *this;
}

Dist &Dist::operator-=(const Dist &other)
{
    Tree result;

    for (auto t : _outcomes)
        for (auto o : other._outcomes)
            result.insert(t - o);

    _outcomes = result;

    _normalize();

    return *this;
}

Dist &Dist::operator*=(const Dist &other)
{
    Tree result;

    for (auto t : _outcomes)
        for (auto o : other._outcomes)
            result.insert(t * o);

    _outcomes = result;

    _normalize();

    return *this;
}

Dist &Dist::operator/=(const Dist &other)
{
    Tree result;

    for (auto t : _outcomes)
        for (auto o : other._outcomes)
            result.insert(t / o);

    _outcomes = result;

    _normalize();

    return *this;
}

Dist &Dist::operator%=(const Dist &other)
{
    Tree result;

    for (auto t : _outcomes)
        for (auto o : other._outcomes)
            result.insert(t % o);

    _outcomes = result;

    _normalize();

    return *this;
}

Tree::iterator Dist::begin(void)
{
    return _outcomes.begin();
}

Tree::iterator Dist::end(void)
{
    return _outcomes.end();
}

Tree::const_iterator Dist::begin(void) const
{
    return _outcomes.begin();
}

Tree::const_iterator Dist::end(void) const
{
    return _outcomes.end();
}

Dist operator+(const Dist &lhs, const Dist &rhs)
{
    Dist result;

    for (auto l : lhs)
        for (auto r : rhs)
            result.insert(l + r);

    result._normalize();

    return result;
}

Dist operator-(const Dist &lhs, const Dist &rhs)
{
    Dist result;

    for (auto l : lhs)
        for (auto r : rhs)
            result.insert(l - r);

    result._normalize();

    return result;
}

Dist operator*(const Dist &lhs, const Dist &rhs)
{
    Dist result;

    for (auto l : lhs)
        for (auto r : rhs)
            result.insert(l * r);

    result._normalize();

    return result;
}

Dist operator/(const Dist &lhs, const Dist &rhs)
{
    Dist result;

    for (auto l : lhs)
        for (auto r : rhs)
            result.insert(l / r);

    result._normalize();

    return result;
}

Dist operator%(const Dist &lhs, const Dist &rhs)
{
    Dist result;

    for (auto l : lhs)
        for (auto r : rhs)
            result.insert(l % r);

    result._normalize();

    return result;
}