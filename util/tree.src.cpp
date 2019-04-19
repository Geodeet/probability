#include "node.src.hpp"

#include "tree.src.hpp"

Tree::Tree(void) : _root(new Node()) {}

Tree::Tree(Node *root) : _root(root) {}

Tree::Tree(const Tree &other) : _root(new Node())
{
    delete _root;
    _root = other._root->copy();
}

Tree::~Tree(void)
{
    delete _root;
}

Tree &Tree::operator=(const Tree &other)
{
    // TODO use move semantics or avoid copying tree
    delete _root;
    _root = other._root->copy();

    return *this;
}

void Tree::insert(Outcome outcome)
{
    if (outcome.probability != 0)
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

Tree::const_iterator Tree::begin(void) const
{
    return Tree::const_iterator(_root);
}

Tree::const_iterator Tree::end(void) const
{
    return Tree::const_iterator();
}

// Iterator implementation
Tree::StackIterator::StackIterator(Node *node)
{
    if (node)
    {
        _stack.push(node);
        _follow_left();
    }
}

void Tree::StackIterator::_follow_left(void)
{
    if (!_stack.empty())
        while (!_stack.top()->left->is_leaf())
            _stack.push(_stack.top()->left);
}

void Tree::StackIterator::_advance(void)
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

bool Tree::StackIterator::operator==(const StackIterator &other)
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

bool Tree::StackIterator::operator!=(const StackIterator &other)
{
    if (_stack.empty() && other._stack.empty())
        return false;
    else if (_stack.empty() || other._stack.empty())
        return true;
    else
        return _stack.top() != other._stack.top();
}

Tree::iterator::iterator(void) : StackIterator(nullptr) {}

Tree::const_iterator::const_iterator(void) : StackIterator(nullptr) {}

Tree::iterator::iterator(Node *node) : StackIterator(node) {}

Tree::const_iterator::const_iterator(Node *node) : StackIterator(node) {}

Tree::iterator &Tree::iterator::operator++(void)
{
    _advance();

    return *this;
}

Tree::const_iterator &Tree::const_iterator::operator++(void)
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

Tree::const_iterator Tree::const_iterator::operator++(int)
{
    Tree::const_iterator iter;
    iter._stack = _stack;

    _advance();

    return iter;
}

bool Tree::iterator::operator==(const iterator &other) const
{
    return _stack == other._stack;
}

bool Tree::const_iterator::operator==(const const_iterator &other) const
{
    return _stack == other._stack;
}

bool Tree::iterator::operator!=(const iterator &other) const
{
    return _stack != other._stack;
}

bool Tree::const_iterator::operator!=(const const_iterator &other) const
{
    return _stack != other._stack;
}

Tree::iterator::reference Tree::iterator::operator*(void)
{
    return _stack.top()->outcome;
}

Tree::const_iterator::reference Tree::const_iterator::operator*(void)const
{
    return _stack.top()->outcome;
}

Tree::iterator::pointer Tree::iterator::operator->(void)
{
    return &_stack.top()->outcome;
}

Tree::const_iterator::pointer Tree::const_iterator::operator->(void)const
{
    return &_stack.top()->outcome;
}