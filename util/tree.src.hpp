#pragma once

#include "../outcome/outcome.hpp"

// Forward declaration of tree node
class Node;

class Tree
{
    Node *_root;

  public:
    Tree(void);

    void insert(const Outcome outcome);

    // For debugging purposes
    void print(void) const;

  private:
    // Iterator over the tree
    class iterator : std::iterator<
                         std::bidirectional_iterator_tag,
                         Outcome,
                         long int,
                         Outcome *,
                         Outcome>
    {
        Node *_cur;
        bool _at_end;

        void _advance(void);

      public:
        iterator(void);
        iterator(Node *node);

        iterator& operator++(void);
        iterator operator++(int);

        bool operator==(const iterator &other) const;
        bool operator!=(const iterator &other) const;

        reference operator*();
        reference operator->();
    };

  public:
    iterator begin(void);
    iterator end(void);
};
