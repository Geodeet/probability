#include "../outcome/outcome.hpp"

class Node;

class Tree
{
    Node *_root;

  public:
    Tree(void);

    void insert(const Outcome outcome);
};
