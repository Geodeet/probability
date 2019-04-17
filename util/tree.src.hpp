#pragma once

#include <stack>

#include "../outcome/outcome.hpp"

// Forward declaration of tree node
class Node;

class Tree
{
    Node *_root;

    Tree(Node *root);

  public:
    Tree(void);
    Tree(const Tree &other);
    ~Tree(void);

    Tree copy(void) const;

    void insert(const Outcome outcome);

    Fraction probability(Fraction outcome) const;

    // For debugging purposes
    void print(void) const;

  private:
    // Iterator over the tree
    class iterator : std::iterator<
                         std::bidirectional_iterator_tag,
                         Outcome,
                         long int>
    {
        // Node *_cur;
        std::stack<Node*> _stack;

        void _follow_left(void);
        void _advance(void);

      public:
        iterator(void);
        iterator(Node *node);

        iterator& operator++(void);
        iterator operator++(int);

        bool operator==(const iterator &other) const;
        bool operator!=(const iterator &other) const;

        reference operator*();
        pointer operator->();
    };

  public:
    iterator begin(void);
    iterator end(void);
};
