#include "distribution.h"

// Sum the probabilities in a distribution
Fraction Distribution::_sum_probabilities( void ) const {
  Fraction total_prob( 0 );
  
  // Simply add all probabilities together
  for( Outcome outcome : _outcomes ) {
    total_prob += outcome._probability;
  }
  
  return total_prob;
}

// Binary comparison to determine uniqueness (and destroy one of the two entries in the list)
// This method also merges the probabilities
bool Distribution::_merge_compare( Outcome &out_keep, Outcome &out_delete ) {
  if( out_delete == out_keep ) {
    // Here we add the probability of the deleted outcome to the kept
    out_keep._probability += out_delete._probability;
    return true;
  }
  else {
    return false;
  }
}

// Remove the duplicate outcomes (while merging the probabilities)
void Distribution::_remove_duplicates ( void ) {
  // First sort the list of outcomes
  _outcomes.sort();
  
  // Declare some iterators
  std::list<Outcome>::iterator iter = _outcomes.begin(), next = iter;
  
  // Then pair-wise compare for uniqueness
  while( ++next != _outcomes.end() ) {
    if( _merge_compare( *iter, *next ) ) {
      _outcomes.erase( next );
    }
    else {
      ++iter;
    }
    next = iter;
  }
}

// Add an outcome to a distribution, comparing for duplicates when adding
void Distribution::_add_outcome( Outcome outcome ) {
  for( auto out : _outcomes ) {
    if( _merge_compare( out, outcome ) ) {
      return;
    }
  }
  
  // We have added a unique outcome
  _outcomes.push_back( outcome );
}

// Compute the maximum probability
Fraction Distribution::_max_probability( void ) const {
  Fraction max(0);
  
  for( auto out : _outcomes ) {
    if( max < out._probability ) {
      max = out._probability;
    }
  }
  
  return max;
}

// Add an outcome 
void Distribution::add_outcome( Outcome outcome ) {
  //_outcomes.push_back( outcome );
  _add_outcome( outcome );
}

// Add an outcome from integer value and probability
void Distribution::add_outcome( int value, Fraction probability ) {
  //_outcomes.push_back( Outcome( value, probability ) );
  _add_outcome( Outcome( value, probability ) );
}

// Add an outcome from fraction value and probability
void Distribution::add_outcome( Fraction value, Fraction probability ) {
  //_outcomes.push_back( Outcome( value, probability ) );
  _add_outcome( Outcome( value, probability ) );
}

// Add a list of outcomes
void Distribution::add_outcome( std::list<Outcome> &out_list ) {
  _outcomes.insert( _outcomes.end(), out_list.begin(), out_list.end() );
  _remove_duplicates();
}

// Delete an outcome
void Distribution::del_outcome( Outcome outcome ) {
  _outcomes.remove( outcome );
}

// Delete an outcome based on the value
void Distribution::del_outcome( int value ) {
  _outcomes.remove( Outcome( value ) );
}

// Delete an outcome based on the value
void Distribution::del_outcome( Fraction value ) {
  _outcomes.remove( Outcome( value ) );
}

// Clear the outcomes
void Distribution::clear_outcomes( void ) {
  _outcomes.clear();
}

// Compute the expected value
Fraction Distribution::exp_value( void ) const {
  Fraction exp( 0 );
  
  for( Outcome out : _outcomes )
  {
    exp += out._value * out._probability;
  }
  
  return exp;
}

// Compute the variance
Fraction Distribution::variance( void ) const {
  Fraction mean = exp_value();
  Fraction square( 0 );
  
  for( Outcome out : _outcomes )
  {
    square += out._probability * out._value * out._value;
  }
  
  return square - mean * mean;
}

// This method normalizes the distribution
void Distribution::normalize( void ) {
  // First get the total probability
  Fraction total = _sum_probabilities();
  
  // Divide by the total when it is not equal to 1
  if( total != 1 ) {
//    *this /= total;
  }
}

// Print the distribution to the terminal
void Distribution::print( void ) const {
  std::cout << "value \t | probability" << std::endl;
  
  // Simply loop over the outcomes and print the value and probability
  for( auto out : _outcomes ) {
    std::cout << out._value.as_string() << "\t | " << out._probability.as_string() << std::endl;
  }
}

// Write a histogram to the standard out
void Distribution::histogram( int max_ticks ) const {
  Fraction max = _max_probability();
  Fraction incr = max / max_ticks;
  
  for( auto out : _outcomes ) {
    std::cout << out._value.as_string() << "\t | " << out._probability.as_string() << "\t | ";
    Fraction cursor = out._probability;
    
    while( cursor > 0 ) {
      cursor -= incr;
      std::cout << "=";
    }
    
    std::cout << std::endl;
  }
}

// Write a histogram with the standard number of ticks (100)
void Distribution::histogram( void ) const {
  histogram( 100 );
}

// Plot the distribution with gnuplot
void Distribution::plot( void ) const {
  
}

// Assignment operator that works with expressions
Distribution& Distribution::operator= ( Expression& expr ) {
  std::set< const Distribution* > dists;
  Combination* comb = new Combination();

  clear_outcomes();

  // Identify all distributions in the expression
  expr.count( dists );
  
  // Create an odometer for these distributions
  Odometer odo( dists );
  odo.init_comb( comb );
  
  do {
    add_outcome( expr.eval( comb ), comb->get_probability() );
  } while( odo( comb ) );
  
  // Remove duplicates
  //_remove_duplicates();
  
  // Delete all heap allocated expression objects
  delete &expr;
  delete comb;
  
  return *this;
}

// Regular assignment operator
Distribution& Distribution::operator= ( const Distribution& dist ) {
  _outcomes = dist._outcomes;
  
  _remove_duplicates();
  
  return *this;
}

/*
// Turn the distribution into a combination
Combination<Distribution> Distribution::get_combination( void ) const {
  Combination<Distribution> new_comb;
  
  for( Outcome iter : _outcomes ) {
    new_comb.add_atom( CombAtom<Distribution>( this, iter._value, iter._probability ) );
  }
  
  return new_comb;
}

// Assignment operator based on combinations
Distribution& Distribution::operator= ( Combination<Distribution>& comb ) {
  clear_outcomes();

  for( CombAtom<Distribution> iter : comb._atoms ) {
    add_outcome( iter.get_value(), iter.get_prob() );
  }
  
  _remove_duplicates();
  
  // Delete the combination that was made to compute the expression
  delete &comb;
  
  return *this;
}
*/