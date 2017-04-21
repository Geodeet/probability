/* ODOMETER CLASS
    Works like an odometer on containers in a vector: increasing the iterators to each container like an odometer.
    Currently only works with Distributions.
*/

#pragma once

#include <vector>
#include "expression.h"
#include "outcome.h"

// Forward declaration of Distribution class from expression.h

using namespace std;

// The odometer class declaration
class Odometer {
private:
  vector<const Distribution*> dists;
  vector<list<Outcome>::const_iterator> state;
  vector<list<Outcome>::const_iterator> begin;
  vector<list<Outcome>::const_iterator> end;
  
public:
  Odometer( set<const Distribution*> new_dists );
  bool operator() ( Combination* comb );
  void init_comb( Combination* comb ) const;
};