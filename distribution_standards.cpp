#include "distribution.h"

// Simple uniform from 0 to 9
void Distribution::make_uniform( void ) {
  // Clear previous outcomes!
  clear_outcomes();
  
  for( int i = 0; i != 10; ++i ) {
    add_outcome( i, Fraction( 1, 10 ) );
  }
}

// Uniform from to end-1
void Distribution::make_uniform( int end ) {
  // Clear previous outcomes!
  clear_outcomes();
  
  if( end > 0 ) {
    for( int i = 0; i != end; ++i ) {
      add_outcome( i, Fraction( 1, end ) );
    }
  }
}

// Uniform from begin to end
void Distribution::make_uniform( int begin, int end ) {
  // Clear previous outcomes!
  clear_outcomes();
  
  int total = end - begin + 1;
  
  if( total > 0 ) {
    for( int i = begin; i <= end; ++i ) {
      add_outcome( i, Fraction( 1, total ) );
    }
  }
}

// Uniform from begin with fractional step size
void Distribution::make_uniform( Fraction begin, Fraction size, int steps ) {
  // Clear previous outcomes!
  clear_outcomes();

  if( steps > 0 ) {
    for( int i = 0; i != steps; ++i ) {
      add_outcome( begin, Fraction( 1, steps ) );
      begin += size;
    }
  }
}

// Bernoulli with p = .5
void Distribution::make_bernoulli( void ) {
  // Clear previous outcomes!
  clear_outcomes();

  add_outcome( 0, Fraction( 1, 2 ) );
  add_outcome( 1, Fraction( 1, 2 ) );
}

// Bernoulli with fractional p
void Distribution::make_bernoulli( Fraction p ) {
  // Clear previous outcomes!
  clear_outcomes();

  add_outcome( 0, 1 - p );
  add_outcome( 1, p );
}

// Binomial with n=10, p=.5
void Distribution::make_binomial( void ) {
  make_binomial( 10, Fraction(1,2) );
}

// Binomial with p=.5
void Distribution::make_binomial( int n ) {
  make_binomial( n, Fraction(1,2) );
}

// Binomial with n=10
void Distribution::make_binomial( Fraction p ) {
  make_binomial( 10, p );
}

// Compute factorial recursively
int fact( int n ) {
  if( n > 1 ) {
    return n * fact( n - 1 );
  }
  else {
    return 1;
  }
}

// Compute n choose k
inline int choose( int n, int k ) {
  return fact(n) / fact(k) / fact(n-k);
}

// Compute the probability of a binomial outcome
Fraction binom_probability( int n, int k, const Fraction &p ) {
  return p.pow(k) * (1-p).pow(n-k) * choose(n,k);
}

// Binomial with n and p
void Distribution::make_binomial( int n, Fraction p ) {
  // Clear previous outcomes first!
  clear_outcomes();
  
  for( int i = 0; i <= n; ++i ) {
    add_outcome( i, binom_probability( n, i, p ) );
  }
}