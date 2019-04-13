#include <iostream>

#include "node.src.hpp"

Node::Node(Node* nparent, Outcome outcome) : _depth(0), parent(nparent), left(nullptr), right(nullptr), outcome(outcome) {}

void Node::insert(const Outcome new_outcome)
{
    if (outcome == new_outcome)
        outcome.probability += new_outcome.probability;
    else if (new_outcome < outcome)
    {
        if (left)
            left->insert(new_outcome);
        else
            left = new Node(this, new_outcome);
    }
    else
    {
        if (right)
            right->insert(new_outcome);
        else
            right = new Node(this, new_outcome);
    }
}

void Node::print(std::string prefix) const
{
    std::cout << prefix << outcome << std::endl;

    if (left)
        left->print(prefix + "  ");
    else
        std::cout << prefix + "  --" << std::endl;

    if (right)
        right->print(prefix + "  ");
    else
        std::cout << prefix + "  --" << std::endl;
}