#include "benchmark.h"

double Benchmark::_add_two( int num ) {
  Distribution A, B, C;
  A.make_uniform(1,num);
  B.make_uniform(1,num);
  
  std::clock_t begin = std::clock();
  C = A + B;
  std::clock_t end = std::clock();
  
  return double(end - begin) / double(CLOCKS_PER_SEC) * 1000.0;
}

double Benchmark::_add_three( int num ) {
  Distribution A, B, C, D;
  A.make_uniform(1,num);
  B.make_uniform(1,num);
  C.make_uniform(1,num);
  
  std::clock_t begin = std::clock();
  D = A + B + C;
  std::clock_t end = std::clock();
  
  return double(end - begin) / double(CLOCKS_PER_SEC) * 1000.0;
}

double Benchmark::_add_four( int num ) {
  Distribution A, B, C, D, E;
  A.make_uniform(1,num);
  B.make_uniform(1,num);
  C.make_uniform(1,num);
  D.make_uniform(1,num);
  
  std::clock_t begin = std::clock();
  E = A + B + C + D;
  std::clock_t end = std::clock();
  
  return double(end - begin) / double(CLOCKS_PER_SEC) * 1000.0;
}

double Benchmark::_time_test( int vars, int size ) {
  double time;

  switch (vars) {
    case 2:
      time = _add_two( size );
      break;
    case 3:
      time = _add_three( size );
      break;
    case 4:
      time = _add_four( size );
      break;
  }
  
  return time;
}

void Benchmark::_write_line( double time, int vars, int size ) {
  std::cout << "-=  Addition of " << vars << " variables of length " << size << "\ttook " << time << "\t ms." << std::endl;
}

void Benchmark::_test( int vars, int size ) {
  _write_line( _time_test( vars, size ), vars, size );
}

void Benchmark::order_test( void ) {
  double time;
  int incr = 100;
  
  std::cout << "-= Order check on input size" << std::endl;
  
  for( int i = incr; i < 1500 ; i += incr ) {
    time = _time_test( 2, i );
    
    std::cout << "-=  Vars: " << i << "\t| Time: " << time << "\tms" << std::endl;
  }
}

void Benchmark::time_test( void ) {
  std::cout << "-= Time check for various combinations" << std::endl;
  _test( 2, 500 );
  _test( 2, 1000 );
  _test( 2, 1500 );
  _test( 3, 50 );
  _test( 3, 100 );
  _test( 4, 20 );
  _test( 4, 30 );
}

void Benchmark::test( void ) {
  order_test();
  time_test();
}