#include "node.src.hpp"

#include "tree.src.hpp"

Tree::Tree(void) : _root(new Node()) {}

Tree::Tree(Node *root) : _root(root) {}

Tree::Tree(const Tree &other)
{
    delete _root;
    _root = other.copy()._root;
}

Tree::~Tree(void)
{
    delete _root;
}

Tree Tree::copy(void) const
{
    return Tree(_root->copy());
}

void Tree::insert(Outcome outcome)
{
    _root = _root->insert(outcome);
}

Fraction Tree::probability(Fraction outcome) const
{
    return _root->find(outcome);
}

void Tree::print(void) const
{
    _root->print();
}

Tree::iterator Tree::begin(void)
{
    return Tree::iterator(_root);
}

Tree::iterator Tree::end(void)
{
    return Tree::iterator();
}

// Iterator implementation
Tree::iterator::iterator(void) : _stack() {}

Tree::iterator::iterator(Node *node) : _stack()
{
    if (node)
    {
        _stack.push(node);
        _follow_left();
    }
}

void Tree::iterator::_follow_left(void)
{
    if (!_stack.empty())
        while (!_stack.top()->left->is_leaf())
            _stack.push(_stack.top()->left);
}

void Tree::iterator::_advance()
{
    if (!_stack.empty())
    {
        if (_stack.top()->right->is_leaf())
        {
            Node *prev;
            do
            {
                prev = _stack.top();
                _stack.pop();
            } while (!_stack.empty() && _stack.top()->right == prev);
        }
        else
        {
            _stack.push(_stack.top()->right);
            _follow_left();
        }
    }
}

Tree::iterator &Tree::iterator::operator++(void)
{
    _advance();

    return *this;
}

Tree::iterator Tree::iterator::operator++(int)
{
    Tree::iterator iter;
    iter._stack = _stack;

    _advance();

    return iter;
}

bool Tree::iterator::operator==(const iterator &other) const
{
    if (_stack.empty() ^ other._stack.empty())
        return false;
    else if (_stack.empty() && other._stack.empty())
        return true;
    else if (_stack.top() == other._stack.top())
        return true;
    else
        return false;
}

bool Tree::iterator::operator!=(const iterator &other) const
{
    if (_stack.empty() && other._stack.empty())
        return false;
    else if (_stack.empty() || other._stack.empty())
        return true;
    else
        return _stack.top() != other._stack.top();
}

Tree::iterator::reference Tree::iterator::operator*(void)
{
    return _stack.top()->outcome;
}

Tree::iterator::pointer Tree::iterator::operator->(void)
{
    return &_stack.top()->outcome;
}
