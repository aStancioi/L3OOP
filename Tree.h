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
    
    void remove(int v);
    string inorder();
    string preorder();
    string postorder();

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
    
    Node *getMinNode(Node *node);
    Node *remove(int v, Node *node);
    string inorder(Node *node);
    string preorder(Node *node);
    string postorder(Node *node);
};
