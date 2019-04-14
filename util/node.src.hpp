#pragma once

#include "../outcome/outcome.hpp"

class Node
{
    unsigned int _depth;
    bool _is_leaf;

    void _rotate_left(void);
    void _rotate_right(void);

  public:
    Node *parent, *left, *right;

    Outcome outcome;

    Node(Node *parent);

    bool is_leaf(void) const;

    // Inserting returns the new depth
    unsigned int insert(const Outcome new_outcome);

    // For debugging purposes
    void print(std::string prefix = "") const;
};