/* COMBINATION CLASS
    A combination stores the combination of outcomes that is being evaluated in an expression.
*/

#pragma once

#include <list>
#include "fraction.h"

// Forward declaration of the distribution class (to avoid circular inclusion)
class Distribution;

// Atoms make up a combination of outcomes
class Atom {
public:
  Atom( const Distribution* new_dist, const Fraction& new_value, const Fraction& new_probability );
  const Distribution* dist;
  Fraction value;
  Fraction probability;
};

// A combination is used during evaluation
class Combination {
//private:
public:
  std::list<Atom*> atoms;
public:
  Combination( void );
  ~Combination( void );
  Fraction get_value( const Distribution* dist ) const;
  Fraction get_probability( const Distribution* dist ) const;
  Fraction get_probability( void ) const;
  void add_value( const Distribution* dist, const Fraction& value, const Fraction& probability );
  void set_value( const Distribution* dist, const Fraction& value, const Fraction& probability );
  void clear( void );
  bool is_empty( void ) const;
  void print( void ) const;
};

