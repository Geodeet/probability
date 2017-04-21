
#include "distribution_arithmetic.h"

// ADDITION OPERATORS

Expression& operator+ ( const Distribution& A, const Distribution& B ) {
  Literal *Ae = new Literal(A);
  Literal *Be = new Literal(B);
  Binary *bin = new Addition( *Ae, *Be );
  return *bin;
}

Expression& operator+ ( const Distribution& A, const Expression& Be ) {
  Literal *Ae = new Literal(A);
  Binary *bin = new Addition( *Ae, Be );
  return *bin;
}

Expression& operator+ ( const Expression& Ae, const Distribution& B ) {
  Literal *Be = new Literal(B);
  Binary *bin = new Addition( Ae, *Be );
  return *bin;
}

Expression& operator+ ( const Expression& Ae, const Expression& Be ) {
  Binary *bin = new Addition( Ae, Be );
  return *bin;
}

Expression& operator+ ( const Fraction& Af, const Expression& Be ) {
  Constant *Ae = new Constant( Af );
  Binary *bin = new Addition( *Ae, Be );
  return *bin;
}

Expression& operator+ ( const Expression& Ae, const Fraction& Bf ) {
  Constant *Be = new Constant( Bf );
  Binary *bin = new Addition( Ae, *Be );
  return *bin;
}

Expression& operator+ ( const Fraction& Af, const Distribution& B ) {
  Constant *Ae = new Constant( Af );
  Literal *Be = new Literal( B );
  Binary *bin = new Addition( *Ae, *Be );
  return *bin;
}

Expression& operator+ ( const Distribution& A, const Fraction& Bf ) {
  Literal *Ae = new Literal( A );
  Constant *Be = new Constant( Bf );
  Binary *bin = new Addition( *Ae, *Be );
  return *bin;
}

Expression& operator+ ( int Ai, const Expression& Be ) {
  Constant *Ae = new Constant( Ai );
  Binary *bin = new Addition( *Ae, Be );
  return *bin;
}

Expression& operator+ ( const Expression& Ae, int Bi ) {
  Constant *Be = new Constant( Bi );
  Binary *bin = new Addition( Ae, *Be );
  return *bin;
}

Expression& operator+ ( int Ai, const Distribution& B ) {
  Constant *Ae = new Constant( Ai );
  Literal *Be = new Literal( B );
  Binary *bin = new Addition( *Ae, *Be );
  return *bin;
}

Expression& operator+ ( const Distribution& A, int Bi ) {
  Literal *Ae = new Literal( A );
  Constant *Be = new Constant( Bi );
  Binary *bin = new Addition( *Ae, *Be );
  return *bin;
}

// SUBTRACTION OPERATORS

Expression& operator- ( const Distribution& A, const Distribution& B ) {
  Literal *Ae = new Literal(A);
  Literal *Be = new Literal(B);
  Binary *bin = new Subtraction( *Ae, *Be );
  return *bin;
}

Expression& operator- ( const Distribution& A, const Expression& Be ) {
  Literal *Ae = new Literal(A);
  Binary *bin = new Subtraction( *Ae, Be );
  return *bin;
}

Expression& operator- ( const Expression& Ae, const Distribution& B ) {
  Literal *Be = new Literal(B);
  Binary *bin = new Subtraction( Ae, *Be );
  return *bin;
}

Expression& operator- ( const Expression& Ae, const Expression& Be ) {
  Binary *bin = new Subtraction( Ae, Be );
  return *bin;
}

Expression& operator- ( const Fraction& Af, const Expression& Be ) {
  Constant *Ae = new Constant( Af );
  Binary *bin = new Subtraction( *Ae, Be );
  return *bin;
}

Expression& operator- ( const Expression& Ae, const Fraction& Bf ) {
  Constant *Be = new Constant( Bf );
  Binary *bin = new Subtraction( Ae, *Be );
  return *bin;
}

Expression& operator- ( const Fraction& Af, const Distribution& B ) {
  Constant *Ae = new Constant( Af );
  Literal *Be = new Literal( B );
  Binary *bin = new Subtraction( *Ae, *Be );
  return *bin;
}

Expression& operator- ( const Distribution& A, const Fraction& Bf ) {
  Literal *Ae = new Literal( A );
  Constant *Be = new Constant( Bf );
  Binary *bin = new Subtraction( *Ae, *Be );
  return *bin;
}

Expression& operator- ( int Ai, const Expression& Be ) {
  Constant *Ae = new Constant( Ai );
  Binary *bin = new Subtraction( *Ae, Be );
  return *bin;
}

Expression& operator- ( const Expression& Ae, int Bi ) {
  Constant *Be = new Constant( Bi );
  Binary *bin = new Subtraction( Ae, *Be );
  return *bin;
}

Expression& operator- ( int Ai, const Distribution& B ) {
  Constant *Ae = new Constant( Ai );
  Literal *Be = new Literal( B );
  Binary *bin = new Subtraction( *Ae, *Be );
  return *bin;
}

Expression& operator- ( const Distribution& A, int Bi ) {
  Literal *Ae = new Literal( A );
  Constant *Be = new Constant( Bi );
  Binary *bin = new Subtraction( *Ae, *Be );
  return *bin;
}

// MULTIPLICATION OPERATORS

Expression& operator* ( const Distribution& A, const Distribution& B ) {
  Literal *Ae = new Literal(A);
  Literal *Be = new Literal(B);
  Binary *bin = new Multiplication( *Ae, *Be );
  return *bin;
}

Expression& operator* ( const Distribution& A, const Expression& Be ) {
  Literal *Ae = new Literal(A);
  Binary *bin = new Multiplication( *Ae, Be );
  return *bin;
}

Expression& operator* ( const Expression& Ae, const Distribution& B ) {
  Literal *Be = new Literal(B);
  Binary *bin = new Multiplication( Ae, *Be );
  return *bin;
}

Expression& operator* ( const Expression& Ae, const Expression& Be ) {
  Binary *bin = new Multiplication( Ae, Be );
  return *bin;
}

Expression& operator* ( const Fraction& Af, const Expression& Be ) {
  Constant *Ae = new Constant( Af );
  Binary *bin = new Multiplication( *Ae, Be );
  return *bin;
}

Expression& operator* ( const Expression& Ae, const Fraction& Bf ) {
  Constant *Be = new Constant( Bf );
  Binary *bin = new Multiplication( Ae, *Be );
  return *bin;
}

Expression& operator* ( const Fraction& Af, const Distribution& B ) {
  Constant *Ae = new Constant( Af );
  Literal *Be = new Literal( B );
  Binary *bin = new Multiplication( *Ae, *Be );
  return *bin;
}

Expression& operator* ( const Distribution& A, const Fraction& Bf ) {
  Literal *Ae = new Literal( A );
  Constant *Be = new Constant( Bf );
  Binary *bin = new Multiplication( *Ae, *Be );
  return *bin;
}

Expression& operator* ( int Ai, const Expression& Be ) {
  Constant *Ae = new Constant( Ai );
  Binary *bin = new Multiplication( *Ae, Be );
  return *bin;
}

Expression& operator* ( const Expression& Ae, int Bi ) {
  Constant *Be = new Constant( Bi );
  Binary *bin = new Multiplication( Ae, *Be );
  return *bin;
}

Expression& operator* ( int Ai, const Distribution& B ) {
  Constant *Ae = new Constant( Ai );
  Literal *Be = new Literal( B );
  Binary *bin = new Multiplication( *Ae, *Be );
  return *bin;
}

Expression& operator* ( const Distribution& A, int Bi ) {
  Literal *Ae = new Literal( A );
  Constant *Be = new Constant( Bi );
  Binary *bin = new Multiplication( *Ae, *Be );
  return *bin;
}

// DIVISION OPERATORS

Expression& operator/ ( const Distribution& A, const Distribution& B ) {
  Literal *Ae = new Literal(A);
  Literal *Be = new Literal(B);
  Binary *bin = new Division( *Ae, *Be );
  return *bin;
}

Expression& operator/ ( const Distribution& A, const Expression& Be ) {
  Literal *Ae = new Literal(A);
  Binary *bin = new Division( *Ae, Be );
  return *bin;
}

Expression& operator/ ( const Expression& Ae, const Distribution& B ) {
  Literal *Be = new Literal(B);
  Binary *bin = new Division( Ae, *Be );
  return *bin;
}

Expression& operator/ ( const Expression& Ae, const Expression& Be ) {
  Binary *bin = new Division( Ae, Be );
  return *bin;
}

Expression& operator/ ( const Fraction& Af, const Expression& Be ) {
  Constant *Ae = new Constant( Af );
  Binary *bin = new Division( *Ae, Be );
  return *bin;
}

Expression& operator/ ( const Expression& Ae, const Fraction& Bf ) {
  Constant *Be = new Constant( Bf );
  Binary *bin = new Division( Ae, *Be );
  return *bin;
}

Expression& operator/ ( const Fraction& Af, const Distribution& B ) {
  Constant *Ae = new Constant( Af );
  Literal *Be = new Literal( B );
  Binary *bin = new Division( *Ae, *Be );
  return *bin;
}

Expression& operator/ ( const Distribution& A, const Fraction& Bf ) {
  Literal *Ae = new Literal( A );
  Constant *Be = new Constant( Bf );
  Binary *bin = new Division( *Ae, *Be );
  return *bin;
}

Expression& operator/ ( int Ai, const Expression& Be ) {
  Constant *Ae = new Constant( Ai );
  Binary *bin = new Division( *Ae, Be );
  return *bin;
}

Expression& operator/ ( const Expression& Ae, int Bi ) {
  Constant *Be = new Constant( Bi );
  Binary *bin = new Division( Ae, *Be );
  return *bin;
}

Expression& operator/ ( int Ai, const Distribution& B ) {
  Constant *Ae = new Constant( Ai );
  Literal *Be = new Literal( B );
  Binary *bin = new Division( *Ae, *Be );
  return *bin;
}

Expression& operator/ ( const Distribution& A, int Bi ) {
  Literal *Ae = new Literal( A );
  Constant *Be = new Constant( Bi );
  Binary *bin = new Division( *Ae, *Be );
  return *bin;
}

// MODULO OPERATORS

Expression& operator% ( const Distribution& A, const Distribution& B ) {
  Literal *Ae = new Literal(A);
  Literal *Be = new Literal(B);
  Binary *bin = new Modulo( *Ae, *Be );
  return *bin;
}

Expression& operator% ( const Distribution& A, const Expression& Be ) {
  Literal *Ae = new Literal(A);
  Binary *bin = new Modulo( *Ae, Be );
  return *bin;
}

Expression& operator% ( const Expression& Ae, const Distribution& B ) {
  Literal *Be = new Literal(B);
  Binary *bin = new Modulo( Ae, *Be );
  return *bin;
}

Expression& operator% ( const Expression& Ae, const Expression& Be ) {
  Binary *bin = new Modulo( Ae, Be );
  return *bin;
}

Expression& operator% ( const Fraction& Af, const Expression& Be ) {
  Constant *Ae = new Constant( Af );
  Binary *bin = new Modulo( *Ae, Be );
  return *bin;
}

Expression& operator% ( const Expression& Ae, const Fraction& Bf ) {
  Constant *Be = new Constant( Bf );
  Binary *bin = new Modulo( Ae, *Be );
  return *bin;
}

Expression& operator% ( const Fraction& Af, const Distribution& B ) {
  Constant *Ae = new Constant( Af );
  Literal *Be = new Literal( B );
  Binary *bin = new Modulo( *Ae, *Be );
  return *bin;
}

Expression& operator% ( const Distribution& A, const Fraction& Bf ) {
  Literal *Ae = new Literal( A );
  Constant *Be = new Constant( Bf );
  Binary *bin = new Modulo( *Ae, *Be );
  return *bin;
}

Expression& operator% ( int Ai, const Expression& Be ) {
  Constant *Ae = new Constant( Ai );
  Binary *bin = new Modulo( *Ae, Be );
  return *bin;
}

Expression& operator% ( const Expression& Ae, int Bi ) {
  Constant *Be = new Constant( Bi );
  Binary *bin = new Modulo( Ae, *Be );
  return *bin;
}

Expression& operator% ( int Ai, const Distribution& B ) {
  Constant *Ae = new Constant( Ai );
  Literal *Be = new Literal( B );
  Binary *bin = new Modulo( *Ae, *Be );
  return *bin;
}

Expression& operator% ( const Distribution& A, int Bi ) {
  Literal *Ae = new Literal( A );
  Constant *Be = new Constant( Bi );
  Binary *bin = new Modulo( *Ae, *Be );
  return *bin;
}

// COMPARISON OPERATORS

Expression& operator== ( const Distribution& A, const Distribution& B ) {
  Literal *Ae = new Literal(A);
  Literal *Be = new Literal(B);
  Binary *bin = new Comparison( *Ae, *Be );
  return *bin;
}

Expression& operator== ( const Distribution& A, const Expression& Be ) {
  Literal *Ae = new Literal(A);
  Binary *bin = new Comparison( *Ae, Be );
  return *bin;
}

Expression& operator== ( const Expression& Ae, const Distribution& B ) {
  Literal *Be = new Literal(B);
  Binary *bin = new Comparison( Ae, *Be );
  return *bin;
}

Expression& operator== ( const Expression& Ae, const Expression& Be ) {
  Binary *bin = new Comparison( Ae, Be );
  return *bin;
}

Expression& operator== ( const Fraction& Af, const Expression& Be ) {
  Constant *Ae = new Constant( Af );
  Binary *bin = new Comparison( *Ae, Be );
  return *bin;
}

Expression& operator== ( const Expression& Ae, const Fraction& Bf ) {
  Constant *Be = new Constant( Bf );
  Binary *bin = new Comparison( Ae, *Be );
  return *bin;
}

Expression& operator== ( const Fraction& Af, const Distribution& B ) {
  Constant *Ae = new Constant( Af );
  Literal *Be = new Literal( B );
  Binary *bin = new Comparison( *Ae, *Be );
  return *bin;
}

Expression& operator== ( const Distribution& A, const Fraction& Bf ) {
  Literal *Ae = new Literal( A );
  Constant *Be = new Constant( Bf );
  Binary *bin = new Comparison( *Ae, *Be );
  return *bin;
}

Expression& operator== ( int Ai, const Expression& Be ) {
  Constant *Ae = new Constant( Ai );
  Binary *bin = new Comparison( *Ae, Be );
  return *bin;
}

Expression& operator== ( const Expression& Ae, int Bi ) {
  Constant *Be = new Constant( Bi );
  Binary *bin = new Comparison( Ae, *Be );
  return *bin;
}

Expression& operator== ( int Ai, const Distribution& B ) {
  Constant *Ae = new Constant( Ai );
  Literal *Be = new Literal( B );
  Binary *bin = new Comparison( *Ae, *Be );
  return *bin;
}

Expression& operator== ( const Distribution& A, int Bi ) {
  Literal *Ae = new Literal( A );
  Constant *Be = new Constant( Bi );
  Binary *bin = new Comparison( *Ae, *Be );
  return *bin;
}

// LESS THAN OPERATORS

Expression& operator< ( const Distribution& A, const Distribution& B ) {
  Literal *Ae = new Literal(A);
  Literal *Be = new Literal(B);
  Binary *bin = new Less( *Ae, *Be );
  return *bin;
}

Expression& operator< ( const Distribution& A, const Expression& Be ) {
  Literal *Ae = new Literal(A);
  Binary *bin = new Less( *Ae, Be );
  return *bin;
}

Expression& operator< ( const Expression& Ae, const Distribution& B ) {
  Literal *Be = new Literal(B);
  Binary *bin = new Less( Ae, *Be );
  return *bin;
}

Expression& operator< ( const Expression& Ae, const Expression& Be ) {
  Binary *bin = new Less( Ae, Be );
  return *bin;
}

Expression& operator< ( const Fraction& Af, const Expression& Be ) {
  Constant *Ae = new Constant( Af );
  Binary *bin = new Less( *Ae, Be );
  return *bin;
}

Expression& operator< ( const Expression& Ae, const Fraction& Bf ) {
  Constant *Be = new Constant( Bf );
  Binary *bin = new Less( Ae, *Be );
  return *bin;
}

Expression& operator< ( const Fraction& Af, const Distribution& B ) {
  Constant *Ae = new Constant( Af );
  Literal *Be = new Literal( B );
  Binary *bin = new Less( *Ae, *Be );
  return *bin;
}

Expression& operator< ( const Distribution& A, const Fraction& Bf ) {
  Literal *Ae = new Literal( A );
  Constant *Be = new Constant( Bf );
  Binary *bin = new Less( *Ae, *Be );
  return *bin;
}

Expression& operator< ( int Ai, const Expression& Be ) {
  Constant *Ae = new Constant( Ai );
  Binary *bin = new Less( *Ae, Be );
  return *bin;
}

Expression& operator< ( const Expression& Ae, int Bi ) {
  Constant *Be = new Constant( Bi );
  Binary *bin = new Less( Ae, *Be );
  return *bin;
}

Expression& operator< ( int Ai, const Distribution& B ) {
  Constant *Ae = new Constant( Ai );
  Literal *Be = new Literal( B );
  Binary *bin = new Less( *Ae, *Be );
  return *bin;
}

Expression& operator< ( const Distribution& A, int Bi ) {
  Literal *Ae = new Literal( A );
  Constant *Be = new Constant( Bi );
  Binary *bin = new Less( *Ae, *Be );
  return *bin;
}
