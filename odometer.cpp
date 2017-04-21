
#include "odometer.h"
#include "distribution.h"

void Odometer::init_comb( Combination* comb ) const {
  for( auto dist : dists ) {
    comb->add_value( dist, dist->_outcomes.front()._value, dist->_outcomes.front()._probability );
  }
}

Odometer::Odometer( std::set<const Distribution*> new_dists ) {
  //dists = new_dists;
  for( const auto dist : new_dists ) {
    dists.push_back( dist );
  }
  
  for( auto dist : dists ) {
    // Initialize the begin vector with begin iterators
    begin.push_back( dist->_outcomes.begin() );
    // Initialize the end vector with end iterators
    end.push_back( dist->_outcomes.end() );
    // Initialize the state vector with iterators
    state.push_back( dist->_outcomes.begin() );
  }
}

bool Odometer::operator() ( Combination* comb ) {
  int cur = 0;
  bool carry = true;
     
  // Main loop (This can probably be done better)
  while( carry and cur != dists.size() ) {
    ++(state[cur]);
    comb->set_value( dists[cur], state[cur]->_value, state[cur]->_probability );

    if( state[cur] == end[cur] ) { // Here we have to carry over to the next digit
      state[cur] = begin[cur];
      comb->set_value( dists[cur], state[cur]->_value, state[cur]->_probability );
      ++cur;
    }
    else {
      carry = false; // We are done
    }
  }
  
  // Check whether we reached the end of the odometer
  if( cur == dists.size() ) {
    return false;
  }
  else {
    return true;
  }
}
