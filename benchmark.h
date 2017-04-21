/* BENCHMARK CLASS
    This class defines some standardized tests to asses performence (during optimization of code).
*/

#pragma once

#include <iostream>
#include <cmath>
#include <ctime>

#include "distribution.h"
#include "distribution_arithmetic.h"

class Benchmark {
private:
  static double _add_two( int num );
  static double _add_three( int num );
  static double _add_four( int num );
  static double _add_large( int num );
  
  static double _time_test( int vars, int size );
  static void _write_line( double time, int vars, int size );
  static void _test( int vars, int size );
  
public:
  static void order_test( void );
  static void time_test( void );
  static void test( void );
};