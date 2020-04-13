#include<iostream>
#include<string>
#include<algorithm>
#include"Tree.h"

using namespace std;

Tree::Tree()
{
    root = new Node(0);
}

Tree::Tree(int v)
{
    root = new Node(v);
}

Tree::~Tree()
{
    delete root;
}

void Tree::insert(int v, Node* node)
{
    if (v < node->value) {
        if (node->left == nullptr) {
            node->left = new Node(v);
            return;
        }
        insert(v, node->left);

    }
    else {
        if (node->right == nullptr) {
            node->right = new Node(v);
            return;
        }
        insert(v, node->right);
    }
}

void Tree::insert(int v)
{
    insert(v, root);
}

unsigned int Tree::countNodes(Node* node)
{
    if (node == nullptr)
        return 0;
    return 1 + countNodes(node->left) + countNodes(node->right); //recursively adds one for each existing node.
}

unsigned int Tree::countNodes()
{
    countNodes(root);
}

unsigned int Tree::countEdges(Node* node)
{
    if (node == nullptr)
        return 0;
    return countNodes(root) - 1;
}

unsigned int Tree::countEdges()
{
    countEdges(root);
}

unsigned int Tree::height(Node* node)
{
    if (node == nullptr)
        return 0;
    return 1 + std::max(height(node->left), height(node->right)); //recursively adds 1 for each row of existing branches; goes down towards the higher number
}

unsigned int Tree::height()
{
    return height(root);
}