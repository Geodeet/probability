#pragma once

#include <stack>

#include "../outcome/outcome.hpp"

// Forward declaration of tree node
class Node;

class Tree
{
  Node *_root;

  Tree(Node *root);

  // Tree _copy(void) const;

public:
  Tree(void);
  Tree(const Tree &other);
  ~Tree(void);

  Tree &operator=(const Tree &other);

  void insert(const Outcome outcome);

  Fraction probability(Fraction outcome) const;

  // For debugging purposes
  void print(void) const;

private:
  // Iterator over the tree
  class StackIterator
  {
  protected:
    std::stack<Node *> _stack;

    StackIterator(Node *node);

    void _follow_left(void);
    void _advance(void);

    bool operator==(const StackIterator &other);
    bool operator!=(const StackIterator &other);
  };

public:
  class iterator : public std::iterator<
                       std::bidirectional_iterator_tag,
                       Outcome,
                       long int>, StackIterator
  {
  public:
    iterator(void);
    iterator(Node *node);

    iterator &operator++(void);
    iterator operator++(int);

    bool operator==(const iterator &other) const;
    bool operator!=(const iterator &other) const;

    reference operator*(void);
    pointer operator->(void);
  };

  class const_iterator : public std::iterator<
                             std::bidirectional_iterator_tag,
                             Outcome,
                             long int,
                             const Outcome *,
                             const Outcome &>, StackIterator
  {
  public:
    const_iterator(void);
    const_iterator(Node *node);

    const_iterator &operator++(void);
    const_iterator operator++(int);

    bool operator==(const const_iterator &other) const;
    bool operator!=(const const_iterator &other) const;

    reference operator*(void) const;
    pointer operator->(void) const;
  };

public:
  iterator begin(void);
  iterator end(void);

  const_iterator begin(void) const;
  const_iterator end(void) const;
};
