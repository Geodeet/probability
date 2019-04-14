#include <iostream>

#include "node.src.hpp"

// Utility function to compute the maximum
unsigned int max(unsigned int lhs, unsigned int rhs)
{
    return lhs < rhs ? rhs : lhs;
}

Node::Node(Node *nparent) : _depth(0), _is_leaf(true), parent(nparent), left(nullptr), right(nullptr) {}

bool Node::is_leaf(void) const
{
    return _is_leaf;
}

unsigned int Node::insert(const Outcome new_outcome)
{
    if (_is_leaf)
    {
        _is_leaf = false;
        left = new Node(this);
        right = new Node(this);
        outcome = new_outcome;
    }
    else if (outcome == new_outcome)
        outcome.probability += new_outcome.probability;
    else if (new_outcome < outcome)
        _depth = max(left->insert(new_outcome), _depth);
    else
        _depth = max(right->insert(new_outcome), _depth);

    return _depth + 1;
}

void Node::print(std::string prefix) const
{
    if (_is_leaf)
        std::cout << prefix << "leaf"
                  << " | " << _depth << std::endl;
    else
    {
        std::cout << prefix << outcome << " | " << _depth << std::endl;
        left->print(prefix + "  ");
        right->print(prefix + "  ");
    }
}