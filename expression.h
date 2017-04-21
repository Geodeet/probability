/* EXPRESSION CLASSES
    All classes needed to construct expressions of distributions.
    Expressions are evaluated upon assignment.
*/

#pragma once

#include <list>
#include <set>
#include "fraction.h"
#include "combination.h"

// Using forward declaration of Distribution in combination.h

// Base expression class
class Expression {
public:
  virtual ~Expression( void );
  virtual Fraction eval( const Combination* comb ) const;
  virtual void count( std::set<const Distribution*>& set ) const;
};

// Unary expression
class Unary : public Expression {
protected:
  const Expression* child;
public:
  Unary( const Expression& expr );
  virtual ~Unary( void );
  virtual void count( std::set<const Distribution*>& set ) const;
};

// Binary expression
class Binary : public Expression {
protected:
  const Expression* childA;
  const Expression* childB;
public:
  Binary( const Expression& A, const Expression& B );
  virtual ~Binary( void );
  virtual void count( std::set<const Distribution*>& set ) const;
};

// Negation expression
class Negation : public Unary {
public:
  Negation( const Expression& expr );
  virtual Fraction eval( const Combination* comb ) const;
};

// Addition expression
class Addition : public Binary {
public:
  Addition( const Expression& A, const Expression& B );
  virtual Fraction eval( const Combination* comb ) const;
};

// Subtraction expression
class Subtraction : public Binary {
public:
  Subtraction( const Expression& A, const Expression& B );
  virtual Fraction eval( const Combination* comb ) const;
};

// Multiplication expression
class Multiplication : public Binary {
public:
  Multiplication( const Expression& A, const Expression& B );
  virtual Fraction eval( const Combination* comb ) const;
};

// Division expression
class Division : public Binary {
public:
  Division( const Expression& A, const Expression& B );
  virtual Fraction eval( const Combination* comb ) const;
};

// Modulo expression
class Modulo : public Binary {
public:
  Modulo( const Expression& A, const Expression& B );
  virtual Fraction eval( const Combination* comb ) const;
};

// Comparison expression
class Comparison : public Binary {
public:
  Comparison( const Expression& A, const Expression& B );
  virtual Fraction eval( const Combination* comb ) const;
};

// Less than expression
class Less : public Binary {
public:
  Less( const Expression& A, const Expression& B );
  virtual Fraction eval( const Combination* comb ) const;
};

// Literal expression
class Literal : public Expression {
protected:
  const Distribution* dist;
public:
  Literal( const Distribution& A );
  virtual Fraction eval( const Combination* comb ) const;
  virtual void count( std::set<const Distribution*>& set ) const;
};

// Constant expression
class Constant : public Expression {
protected:
  Fraction value;
public:
  Constant( const Fraction& frac );
  Constant( int integer );
  virtual Fraction eval( const Combination* comb ) const;
  virtual void count( std::set<const Distribution*>& set ) const;
};
