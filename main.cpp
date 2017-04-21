#include <iostream>

#include "distribution.h"
//#include "distribution_arithmetic.h"
#include "benchmark.h"
#include "expression.h"

int main(int argc, char **argv)
{
  Distribution A, B, C, D, E;
  //Fraction frac(1,10);
  
  A.make_uniform(1000);
  B.make_uniform(1000);
  //C.make_uniform(30);
  //D.make_uniform(30);
    
  E = A+B;//+C+D;
  
  //E.print();

  //Benchmark::test();

  /*
  Distribution A, B, C, smaller, larger, equal, remainder, Arem, Brem;
  
  int seats = 5;
  
  A.make_uniform(5,15);
  B.make_uniform(1,20);
  C.make_uniform(1,20);
  
  Brem = B % ((A+B+C) / seats);
  smaller = (A % ((A+B+C) / seats) ) < (B % ((A+B+C) / seats) );
  larger = (B % ((A+B+C) / seats) ) < (A % ((A+B+C) / seats) );
  equal = (B % ((A+B+C) / seats) ) == (A % ((A+B+C) / seats) );
  remainder = ((A % ((A+B+C) / seats) ) + (B % ((A+B+C) / seats) ) + (C % ((A+B+C) / seats) )) / ((A+B+C) / seats);
  
  std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
  std::cout << "||| A |||" << std::endl;
  A.histogram();
  std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
  std::cout << "||| B |||" << std::endl;
  B.histogram();
  std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
  std::cout << "||| A remainder |||" << std::endl;
  Arem.histogram();
  std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
  std::cout << "||| B remainder |||" << std::endl;
  Brem.histogram();
  std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
  std::cout << "||| A rem < B rem |||" << std::endl;
  smaller.histogram();
  std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
  std::cout << "||| B rem < A rem |||" << std::endl;
  larger.histogram();
  std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
  std::cout << "||| A rem = B rem |||" << std::endl;
  equal.histogram();
  std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
  std::cout << "||| number of remainder seats |||" << std::endl;
  remainder.histogram();
  */
  
  return 0;
}
