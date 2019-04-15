#include <iostream>

#include "node.src.hpp"

// Utility function to compute the maximum
unsigned int max(unsigned int lhs, unsigned int rhs)
{
    return lhs < rhs ? rhs : lhs;
}

Node::Node(void) : _depth(0), _is_leaf(true), left(nullptr), right(nullptr) {}

unsigned int Node::_get_balance(void)
{
    return left->_depth - right->_depth;
}

void Node::_update_depth(void)
{
    _depth = max(left->_depth, right->_depth) + 1;
}

Node *Node::_rebalance(Outcome outcome)
{
    int balance = left->_depth - right->_depth;

    if (balance > 1 && outcome < left->outcome)
        return _rotate_right();

    if (balance < -1 && right->outcome < outcome)
        return _rotate_left();

    if (balance > 1 && left->outcome < outcome)
    {
        left = left->_rotate_left();
        return _rotate_right();
    }

    if (balance < -1 && outcome < right->outcome)
    {
        right = right->_rotate_right();
        return _rotate_left();
    }

    return this;
}

Node *Node::_rotate_left(void)
{
    Node *a = this;
    Node *b = a->right;
    Node *c = b->left;

    b->left = a;
    a->right = c;

    a->_update_depth();
    b->_update_depth();

    return b;
}

Node *Node::_rotate_right(void)
{
    Node *b = this;
    Node *a = b->left;
    Node *c = a->right;

    a->right = b;
    b->left = c;

    a->_update_depth();
    b->_update_depth();

    return a;
}

bool Node::is_leaf(void) const
{
    return _is_leaf;
}

Node *Node::insert(const Outcome new_outcome)
{
    if (_is_leaf)
    {
        _is_leaf = false;
        left = new Node();
        right = new Node();
        outcome = new_outcome;
        _depth = 1;
        return this;
    }
    else if (outcome == new_outcome)
    {
        outcome.probability += new_outcome.probability;
        return this;
    }
    else if (new_outcome < outcome)
        left = left->insert(new_outcome);
    else
        right = right->insert(new_outcome);

    _update_depth();

    return _rebalance(new_outcome);
}

Fraction Node::find(Fraction search_outcome) const
{
    if (_is_leaf)
        return Fraction(0);
    if (outcome.value == search_outcome)
        return outcome.probability;
    if (search_outcome < outcome.value)
        return left->find(search_outcome);
    else
        return right->find(search_outcome);
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