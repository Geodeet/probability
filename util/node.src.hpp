#pragma once

#include "../outcome/outcome.hpp"

class Node
{
  unsigned int _depth;
  bool _is_leaf;

  unsigned int _get_balance(void);

  void _update_depth(void);
  Node *_rebalance(Outcome outcome);

  Node *_rotate_left(void);
  Node *_rotate_right(void);

public:
  Node *left, *right;

  Outcome outcome;

  Node(void);
  ~Node(void);

  Node *copy(void) const;

  bool is_leaf(void) const;

  // Inserting returns the new depth
  Node *insert(const Outcome new_outcome);

  Fraction find(Fraction search_outcome) const;

  // For debugging purposes
  void print(std::string prefix = "") const;
};