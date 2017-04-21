#include "outcome.h"

// Default constructor
Outcome::Outcome( void ) {
  _value = Fraction( 1 );
  _probability = Fraction( 1 );
};

// Copy constructor
Outcome::Outcome( const Outcome &other ) {
  _value = other._value; 
  _probability = other._probability;
};

// Copy constructor from just a value
Outcome::Outcome( const int value ) {
  _value = Fraction( value );
  _probability = Fraction( 1 );
}

// Copy constructor from just a value
Outcome::Outcome( const Fraction &value ) {
  _value = value;
  _probability = Fraction( 1 );
}

// Copy constructor from separate values
Outcome::Outcome( const int value, const int probability ) {
  _value = Fraction( value );
  _probability = Fraction( probability );
}

// Copy constructor from separate values
Outcome::Outcome( const Fraction &value, const int probability ) {
  _value = value;
  _probability = Fraction( probability );
}

// Copy constructor from separate values
Outcome::Outcome( const int value, const Fraction &probability ) {
  _value = Fraction( value );
  _probability = probability;
};

// Copy constructor from separate values
Outcome::Outcome( const Fraction &value, const Fraction &probability ) {
  _value = value;
  _probability = probability;
};

// Comparison operator
bool operator== ( const Outcome &A, const Outcome &B ) {
  return (A._value == B._value);
};

// Unequal comparison operator
bool operator!= ( const Outcome &A, const Outcome &B ) {
  return !(A == B);
};

// Less than comparison operator
bool operator< ( const Outcome &A, const Outcome &B ) {
  return (A._value < B._value);
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

