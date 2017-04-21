
#pragma once

#include "expression.h"

class Distribution;

// ADDITION OPERATORS

Expression& operator+ ( const Distribution& A, const Distribution& B );
Expression& operator+ ( const Distribution& A, const Expression& Be );
Expression& operator+ ( const Expression& Ae, const Distribution& B );
Expression& operator+ ( const Expression& Ae, const Expression& Be );

Expression& operator+ ( const Fraction& Af, const Expression& Be );
Expression& operator+ ( const Expression& Ae, const Fraction& Bf );
Expression& operator+ ( const Fraction& Af, const Distribution& B );
Expression& operator+ ( const Distribution& A, const Fraction& Bf );

Expression& operator+ ( int Ai, const Expression& Be );
Expression& operator+ ( const Expression& Ae, int Bi );
Expression& operator+ ( int Ai, const Distribution& B );
Expression& operator+ ( const Distribution& A, int Bi );

// SUBTRACTION OPERATORS

Expression& operator- ( const Distribution& A, const Distribution& B );
Expression& operator- ( const Distribution& A, const Expression& Be );
Expression& operator- ( const Expression& Ae, const Distribution& B );
Expression& operator- ( const Expression& Ae, const Expression& Be );

Expression& operator- ( const Fraction& Af, const Expression& Be );
Expression& operator- ( const Expression& Ae, const Fraction& Bf );
Expression& operator- ( const Fraction& Af, const Distribution& B );
Expression& operator- ( const Distribution& A, const Fraction& Bf );

Expression& operator- ( int Ai, const Expression& Be );
Expression& operator- ( const Expression& Ae, int Bi );
Expression& operator- ( int Ai, const Distribution& B );
Expression& operator- ( const Distribution& A, int Bi );

// MULTIPLICATION OPERATORS

Expression& operator* ( const Distribution& A, const Distribution& B );
Expression& operator* ( const Distribution& A, const Expression& Be );
Expression& operator* ( const Expression& Ae, const Distribution& B );
Expression& operator* ( const Expression& Ae, const Expression& Be );

Expression& operator* ( const Fraction& Af, const Expression& Be );
Expression& operator* ( const Expression& Ae, const Fraction& Bf );
Expression& operator* ( const Fraction& Af, const Distribution& B );
Expression& operator* ( const Distribution& A, const Fraction& Bf );

Expression& operator* ( int Ai, const Expression& Be );
Expression& operator* ( const Expression& Ae, int Bi );
Expression& operator* ( int Ai, const Distribution& B );
Expression& operator* ( const Distribution& A, int Bi );

// DIVISION OPERATORS

Expression& operator/ ( const Distribution& A, const Distribution& B );
Expression& operator/ ( const Distribution& A, const Expression& Be );
Expression& operator/ ( const Expression& Ae, const Distribution& B );
Expression& operator/ ( const Expression& Ae, const Expression& Be );

Expression& operator/ ( const Fraction& Af, const Expression& Be );
Expression& operator/ ( const Expression& Ae, const Fraction& Bf );
Expression& operator/ ( const Fraction& Af, const Distribution& B );
Expression& operator/ ( const Distribution& A, const Fraction& Bf );

Expression& operator/ ( int Ai, const Expression& Be );
Expression& operator/ ( const Expression& Ae, int Bi );
Expression& operator/ ( int Ai, const Distribution& B );
Expression& operator/ ( const Distribution& A, int Bi );

// MODULO OPERATORS

Expression& operator% ( const Distribution& A, const Distribution& B );
Expression& operator% ( const Distribution& A, const Expression& Be );
Expression& operator% ( const Expression& Ae, const Distribution& B );
Expression& operator% ( const Expression& Ae, const Expression& Be );

Expression& operator% ( const Fraction& Af, const Expression& Be );
Expression& operator% ( const Expression& Ae, const Fraction& Bf );
Expression& operator% ( const Fraction& Af, const Distribution& B );
Expression& operator% ( const Distribution& A, const Fraction& Bf );

Expression& operator% ( int Ai, const Expression& Be );
Expression& operator% ( const Expression& Ae, int Bi );
Expression& operator% ( int Ai, const Distribution& B );
Expression& operator% ( const Distribution& A, int Bi );

// COMPARISON OPERATORS

Expression& operator== ( const Distribution& A, const Distribution& B );
Expression& operator== ( const Distribution& A, const Expression& Be );
Expression& operator== ( const Expression& Ae, const Distribution& B );
Expression& operator== ( const Expression& Ae, const Expression& Be );

Expression& operator== ( const Fraction& Af, const Expression& Be );
Expression& operator== ( const Expression& Ae, const Fraction& Bf );
Expression& operator== ( const Fraction& Af, const Distribution& B );
Expression& operator== ( const Distribution& A, const Fraction& Bf );

Expression& operator== ( int Ai, const Expression& Be );
Expression& operator== ( const Expression& Ae, int Bi );
Expression& operator== ( int Ai, const Distribution& B );
Expression& operator== ( const Distribution& A, int Bi );

// LESS THAN OPERATORS

Expression& operator< ( const Distribution& A, const Distribution& B );
Expression& operator< ( const Distribution& A, const Expression& Be );
Expression& operator< ( const Expression& Ae, const Distribution& B );
Expression& operator< ( const Expression& Ae, const Expression& Be );

Expression& operator< ( const Fraction& Af, const Expression& Be );
Expression& operator< ( const Expression& Ae, const Fraction& Bf );
Expression& operator< ( const Fraction& Af, const Distribution& B );
Expression& operator< ( const Distribution& A, const Fraction& Bf );

Expression& operator< ( int Ai, const Expression& Be );
Expression& operator< ( const Expression& Ae, int Bi );
Expression& operator< ( int Ai, const Distribution& B );
Expression& operator< ( const Distribution& A, int Bi );
