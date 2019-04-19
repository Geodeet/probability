#include <iostream>

#include "fraction/fraction.hpp"
#include "outcome/outcome.hpp"
#include "util/tree.hpp"

int main(int argc, char **argv)
{
  Tree t;

  Outcome o1(1), o2(2), o3(3), o4(4), o5(5), o6(6);

  t.insert(o5);
  // t.insert(o2);
  // t.insert(o1);
  // t.insert(o4);
  // t.insert(o3);
  // t.insert(o6);

  // t.insert(Outcome(7));
  // t.insert(Outcome(8));
  // t.insert(Outcome(9));
  // t.insert(Outcome(10));
  // t.insert(Outcome(11));
  // t.insert(Outcome(12));
  // t.insert(Outcome(13));
  // t.insert(Outcome(14));
  // t.insert(Outcome(15));
  // t.insert(Outcome(16));
  // t.insert(Outcome(17));
  // t.insert(Outcome(18));
  // t.insert(Outcome(19));
  // t.insert(Outcome(20));

  t.print();

  std::cout << "======" << std::endl;

  // auto iter = t.begin();

  // std::cout << (iter++)->value << std::endl;
  // std::cout << (iter++)->value << std::endl;
  // std::cout << (iter++)->value << std::endl;
  // std::cout << (iter++)->value << std::endl;
  // std::cout << (iter++)->value << std::endl;
  // std::cout << (iter++)->value << std::endl;
  // std::cout << (iter++)->value << std::endl;
  // std::cout << (iter++)->value << std::endl;
  // std::cout << (iter++)->value << std::endl;
  // std::cout << (iter++)->value << std::endl;

  for (auto o : t)
    std::cout << o << std::endl;

  std::cout << "======" << std::endl;

  Tree c;

  c = t;

  c.print();

  return 0;
}
