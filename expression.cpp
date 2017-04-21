
#include "expression.h"

// EXPRESSION METHODS

Expression::~Expression( void ){

}

Fraction Expression::eval( const Combination* comb ) const {
  return Fraction(0);
}
  
void Expression::count( std::set<const Distribution*>& set ) const {

}

// UNARY METHODS

Unary::Unary( const Expression& expr ) {
  child = &expr;
}

Unary::~Unary( void ) {
  delete child;
}

void Unary::count( std::set<const Distribution*>& set ) const {
  child->count( set );
}

// BINARY METHODS

Binary::Binary( const Expression& A, const Expression& B ) {
  childA = &A;
  childB = &B;
}

Binary::~Binary( void ) {
  delete childA;
  delete childB;
}

void Binary::count( std::set<const Distribution*>& set ) const {
  childA->count( set );
  childB->count( set );
}

// NEGATION METHODS

Negation::Negation( const Expression& expr ) : Unary( expr ) {
  
}

Fraction Negation::eval( const Combination* comb ) const {
  return - child->eval( comb );
}

// ADDITION METHODS

Addition::Addition( const Expression& A, const Expression& B ) : Binary( A, B ) {
  
}

Fraction Addition::eval( const Combination* comb ) const {
  return childA->eval( comb ) + childB->eval( comb );
}

// SUBTRACTION METHODS

Subtraction::Subtraction( const Expression& A, const Expression& B ) : Binary( A, B ) {

}

Fraction Subtraction::eval( const Combination* comb ) const {
  return childA->eval( comb ) - childB->eval( comb );
}

// MULTIPLICATION METHODS

Multiplication::Multiplication( const Expression& A, const Expression& B ) : Binary( A, B ) {
  
}

Fraction Multiplication::eval( const Combination* comb ) const {
  return childA->eval( comb ) * childB->eval( comb );
}

// DIVISION METHODS

Division::Division( const Expression& A, const Expression& B ) : Binary( A, B ) {
  
}

Fraction Division::eval( const Combination* comb ) const {
  return childA->eval( comb ) / childB->eval( comb );
}

// MODULO METHODS

Modulo::Modulo( const Expression& A, const Expression& B ) : Binary( A, B ) {
  
}

Fraction Modulo::eval( const Combination* comb ) const {
  return childA->eval( comb ) % childB->eval( comb );
}

// COMPARISON METHODS

Comparison::Comparison( const Expression& A, const Expression& B ) : Binary( A, B ) {
  
}

Fraction Comparison::eval( const Combination* comb ) const {
  return ( childA->eval(comb) == childB->eval(comb) ) ? Fraction(1) : Fraction(0);
}

// LESS THAN METHODS

Less::Less( const Expression& A, const Expression& B ) : Binary( A, B ) {
  
}

Fraction Less::eval( const Combination* comb ) const {
  return ( childA->eval(comb) < childB->eval(comb) ) ? Fraction(1) : Fraction(0);
}

// LITERAL METHODS

Literal::Literal( const Distribution& new_dist ) {
  dist = &new_dist;
}

Fraction Literal::eval( const Combination* comb ) const {
  return comb->get_value( dist );
}

void Literal::count( std::set<const Distribution*>& set ) const {
  if( set.count( dist ) == 0 ) {
    set.insert( dist );
  }
}

// CONSTANT METHODS

Constant::Constant( const Fraction& frac ) {
  value = frac;
}

Constant::Constant( int integer ) {
  value = Fraction( integer );
}

Fraction Constant::eval( const Combination* comb ) const {
  return value;
}

void Constant::count( std::set<const Distribution*>& set ) const {
  
}
