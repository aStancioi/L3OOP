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

//Binarbaum inorder
string Tree::inorder(Node *node) {
	//string result;
	if (node == nullptr)
	{
		return "";
	}
	return inorder(node->left) + to_string(node->value) + " " + inorder(node->right);
	

}

string Tree::inorder() {
    return inorder(root);
}

//Binarbaum preorder
string Tree::preorder(Node *node)
{
	string result;
	if (node == nullptr)
	{
		return "";
	}
	return  to_string(node->value) + " " + preorder(node->left) + preorder(node->right);
}

string Tree::preorder() {
   return preorder(root);
	
}

//Binarbaum postorder
string Tree::postorder(Node *node) {
	
		string result;
		if (node == nullptr)
		{
			return "";
		}
		return preorder(node->left) + preorder(node->right)+ to_string(node->value) + " ";

}

string Tree::postorder() {
    return postorder(root);
}


//entfernen
Node *Tree::remove(int value, Node *node) {
    if(node == nullptr)
        return nullptr;

    if (value < node->value) {
            node->left = remove(value, node->left);
    }
    else if (value > node->value) {
            node->right = remove(value, node->right);
    }
    else {

        if(node->left == nullptr && node->right == nullptr)
        {
            delete node;
            node = nullptr;
        }
        else if(node->left == nullptr)
        {
            Node *temp;
            temp = node;
            node = node->right;
            delete temp;
        }
        else if(node->right == nullptr)
        {
            Node *temp;
            temp = node;
            node = node->left;
            delete temp;
        }
        else
        {
            Node *min = getMinNode(node->right);
            node->value = min->value;
            node->right = remove(min->value, node->right);
        }
    }
   return node;
}

void Tree::remove(int v) {
    root = remove(v, root);
}

Node *Tree::getMinNode(Node *node) {
    if(node == nullptr)
        return nullptr;
    Node *current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}
