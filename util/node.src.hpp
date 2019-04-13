#pragma once

#include "../outcome/outcome.hpp"

class Node
{
    unsigned int _depth;

    void _rotate_left(void);
    void _rotate_right(void);

  public:
    Node *parent, *left, *right;

    Outcome outcome;

    Node(Node *parent, Outcome outcome);

    void insert(const Outcome new_outcome);

    // For debugging purposes
    void print(std::string prefix = "") const;
};