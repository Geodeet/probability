#include "node.src.hpp"

#include "tree.src.hpp"

Tree::Tree(void) : _root(new Node(nullptr)) {}

void Tree::insert(Outcome outcome)
{
    _root->insert(outcome);
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
Node *follow_left(Node *node)
{
    while (!node->left->is_leaf())
        node = node->left;

    return node;
}

Tree::iterator::iterator(void) : _cur(nullptr), _at_end(true) {}

Tree::iterator::iterator(Node *node) : _cur(follow_left(node)), _at_end(false) {}

void Tree::iterator::_advance()
{
    if (!_at_end)
    {
        if (!_cur->right->is_leaf())
        {
            _cur = _cur->right;
            _cur = follow_left(_cur);
        }
        else
        {
            while (_cur->parent && _cur->parent->right == _cur)
                _cur = _cur->parent;
            _cur = _cur->parent;
        }
    }

    if (!_cur)
        _at_end = true;
}

Tree::iterator &Tree::iterator::operator++(void)
{
    _advance();

    return *this;
}

Tree::iterator Tree::iterator::operator++(int)
{
    Tree::iterator iter;
    iter._cur = _cur;
    iter._at_end = _at_end;

    _advance();

    return iter;
}

bool Tree::iterator::operator==(const iterator &other) const
{
    return _cur == other._cur || (_at_end && other._at_end);
}

bool Tree::iterator::operator!=(const iterator &other) const
{
    return _cur != other._cur && !(_at_end && other._at_end);
}

Tree::iterator::reference Tree::iterator::operator*(void)
{
    return _cur->outcome;
}

Tree::iterator::pointer Tree::iterator::operator->(void)
{
    return &_cur->outcome;
}
