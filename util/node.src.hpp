#include "../outcome/outcome.hpp"

class Node
{
    Node *_left;
    Node *_right;

    unsigned int _depth;

    Outcome _outcome;

    void _rotate_left(void);
    void _rotate_right(void);

  public:
    Node(Outcome outcome);

    void insert(const Outcome outcome);
};