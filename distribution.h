/* DISTRIBUTION CLASS
    This class defines a discrete probability distribution
    Some overloaded methods are provided to create composite distributions (should change this to global functions!)
    Some methods for characterization are implemented (e.g. expected value)
    Also pretty printing is supported
*/

#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <set>
//#include "combination.h"
#include "distribution_arithmetic.h"
#include "outcome.h"
#include "odometer.h"

class Distribution {
protected:
  // The vector that holds all possible outcomes of this distribution
  std::list<Outcome> _outcomes;
  
  // Sum all probabilities
  Fraction _sum_probabilities( void ) const;
  
  // Compare and merge two outcomes
  bool _merge_compare( Outcome &out_keep, Outcome &out_delete );
  
  // Remove duplicates
  void _remove_duplicates( void );
  void _add_outcome( Outcome outcome );
  
  // Compute the maximum probability
  Fraction _max_probability( void ) const;
  
public:  
  // Inserting and deleting outcomes (user is responsible to not add duplicates, except for list addition)
  void add_outcome( Outcome outcome );
  void add_outcome( int value, Fraction probability );
  void add_outcome( Fraction value, Fraction probability );
  void add_outcome( std::list<Outcome> &out_list );
  void del_outcome( Outcome outcome );
  void del_outcome( int value );
  void del_outcome( Fraction value );
  void clear_outcomes( void );
  
  // Some methods that define standard distributions
  void make_uniform( void );
  void make_uniform( int end );
  void make_uniform( int begin, int end );
  void make_uniform( Fraction begin, Fraction size, int steps );
  
  void make_bernoulli( void );
  void make_bernoulli( Fraction p );
  
  void make_binomial( void );
  void make_binomial( int n );
  void make_binomial( Fraction p );
  void make_binomial( int n, Fraction p );
  
  // Some methods that provide characterization
  Fraction exp_value( void ) const;
  Fraction variance( void ) const;
  
  // Normalize the distribution
  void normalize( void );
  
  // Some methods that provide sample drawing
  Fraction draw_sample( void );
  std::list<Fraction> draw_sample( int num_samples );
  
  // Pretty printing the distribution
  void print( void ) const;
  void histogram( int max_ticks ) const;
  void histogram( void ) const;
  void plot( void ) const;
  
  // Odometer class is friend to access the outcome list
  friend class Odometer;
  
  // Assignment operator that works with expressions
  Distribution& operator= ( Expression& expr );
  // Regular assignment operator
  Distribution& operator= ( const Distribution& dist );
  
  /*
  // Turn a distribution into a combination
  Combination<Distribution> get_combination( void ) const;
  
  // Assignment operator that works with combination evaluation
  Distribution& operator= ( Combination<Distribution>& comb );
  */
    
};
