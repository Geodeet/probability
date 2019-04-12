#include "outcome.hpp"

// Default constructor
Outcome::Outcome( void ) {
  value = Fraction( 1 );
  probability = Fraction( 1 );
};

// Copy constructor
Outcome::Outcome( const Outcome &other ) {
  value = other.value; 
  probability = other.probability;
};

// Copy constructor from just a value
Outcome::Outcome( const int nvalue ) {
  value = Fraction( nvalue );
  probability = Fraction( 1 );
}

// Copy constructor from just a value
Outcome::Outcome( const Fraction &nvalue ) {
  value = nvalue;
  probability = Fraction( 1 );
}

// Copy constructor from separate values
Outcome::Outcome( const int nvalue, const int nprobability ) {
  value = Fraction( nvalue );
  probability = Fraction( nprobability );
}

// Copy constructor from separate values
Outcome::Outcome( const Fraction &nvalue, const int nprobability ) {
  value = nvalue;
  probability = Fraction( nprobability );
}

// Copy constructor from separate values
Outcome::Outcome( const int nvalue, const Fraction &nprobability ) {
  value = Fraction( nvalue );
  probability = nprobability;
};

// Copy constructor from separate values
Outcome::Outcome( const Fraction &nvalue, const Fraction &nprobability ) {
  value = nvalue;
  probability = nprobability;
};

// Comparison operator
bool operator== ( const Outcome &A, const Outcome &B ) {
  return (A.value == B.value);
};

// Unequal comparison operator
bool operator!= ( const Outcome &A, const Outcome &B ) {
  return !(A == B);
};

// Less than comparison operator
bool operator< ( const Outcome &A, const Outcome &B ) {
  return (A.value < B.value);
};

// Greater than comparison operator
bool operator> ( const Outcome &A, const Outcome &B ) {
  return (!(A < B) and (A != B));
};

// Less than equal comparison operator
bool operator<= ( const Outcome &A, const Outcome &B ) {
  return !(A > B);
};

// Greater than equal comparison operator
bool operator>= ( const Outcome &A, const Outcome &B ) {
  return !(A < B);
};

