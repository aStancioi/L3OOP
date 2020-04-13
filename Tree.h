#include "Node.h"
#include <string>
using std::string;
class Tree {
public:
    Tree(int v);
    Tree();
    ~Tree();
    //inserts a new root
    void insert(int v);
    unsigned int countNodes();
    unsigned int countEdges();
    unsigned int height();

private:
    //inserts a new node
    void insert(int v, Node* node);
    //counts nodes
    unsigned int countNodes(Node* node);
    //counts edges
    unsigned int countEdges(Node* node);
    //returns the height of the tree
    unsigned int height(Node* node);
    Node* root;
};