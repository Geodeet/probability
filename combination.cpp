
#include "combination.h"

Atom::Atom( const Distribution* new_dist, const Fraction& new_value, const Fraction& new_probability ) {
  dist = new_dist;
  value = new_value;
  probability = new_probability;
}

Combination::Combination( void ) {
  
}

Combination::~Combination( void ) {
  for( auto atom : atoms ) {
    delete atom;
  }
}

Fraction Combination::get_value( const Distribution* dist ) const {
  for( auto atom : atoms ) {
    if( atom->dist == dist ) {
      //std::cout << "  getting: " << dist << " | " << &atom->value << std::endl;
      return atom->value;
    }
  }
  
  return Fraction(0);
}

Fraction Combination::get_probability( const Distribution* dist ) const {
  for( auto atom : atoms ) {
    if( atom->dist == dist ) {
      return atom->probability;
    }
  }
  
  return Fraction(0);
}

Fraction Combination::get_probability( void ) const {
  Fraction total(1);

  for( auto atom : atoms ) {
    total *= atom->probability;
  }
  
  return total;
}

void Combination::add_value( const Distribution* dist, const Fraction& value, const Fraction& probability ) {
  Atom *new_atom = new Atom( dist, value, probability );
  atoms.push_back( new_atom );
}

void Combination::set_value( const Distribution* dist, const Fraction& value, const Fraction& probability ) {
  for( auto atom : atoms ) {
    if( atom->dist == dist ) {
      //std::cout << "  setting: " << dist << " | " << &atom->value << std::endl;
      atom->value = value;
      atom->probability = probability;
      return;
    }
  }
}

bool Combination::is_empty( void ) const {
  return atoms.empty();
}

void Combination::print ( void ) const {
  std::cout << "  atoms:" << std::endl;
  for( auto atom : atoms ) {
    std::cout << "  " << atom->dist << " | " << &atom->value << " | " << atom->value.as_string() << std::endl;
  }
}

