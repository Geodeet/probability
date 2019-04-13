#include <iostream>

#include "fraction/fraction.hpp"
#include "outcome/outcome.hpp"
#include "util/tree.hpp"

int main(int argc, char **argv)
{
  Tree t;

  Outcome o1(1), o2(2), o3(3), o4(5), o5(8), o6(9);

  t.insert(o5);
  t.insert(o2);
  t.insert(o1);
  t.insert(o4);
  t.insert(o3);
  t.insert(o6);

  t.print();

  std::cout << "======" << std::endl;

  for(auto o: t)
    std::cout << o << std::endl;

  return 0;
}
