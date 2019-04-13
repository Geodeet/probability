#include "node.src.hpp"

#include "tree.src.hpp"

Tree::Tree(void) : _root(nullptr) {}

void Tree::insert(Outcome outcome)
{
    if (_root)
        _root->insert(outcome);
    else
        _root = new Node(nullptr, outcome);
}

void Tree::print(void) const
{
    if (_root)
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
Tree::iterator::iterator(Node *node) : _cur(nullptr)
{
    while(node->left)
        node = node->left;

    _cur = node;
}

Tree::iterator &Tree::iterator::operator++(void)
{
    if (_cur->right)
        _cur = _cur->right;
    else if ()
    _cur = _cur->parent;
    return *this;
}

Tree::iterator Tree::iterator::operator++(int)
{
    Tree::iterator iter(_cur);

    return iter;
}

bool Tree::iterator::operator==(const iterator &other) const
{
    return _cur == other._cur;
}

bool Tree::iterator::operator!=(const iterator &other) const
{
    return _cur != other._cur;
}

Tree::iterator::reference Tree::iterator::operator*(void)
{
    return _cur->outcome;
}

Tree::iterator::reference Tree::iterator::operator->(void)
{
    return _cur->outcome;
}
