#include <iostream>
#include <string>
#include <assert.h>
#include "Tree.h"
#include "Node.h"

using namespace std;

int main()
{
	Tree tree(10);
	tree.insert(5);
	tree.insert(12);
	
	assert(tree.countNodes() == 3);
	assert(tree.countEdges() == 2);
	assert(tree.height() == 2);
	
	cout << "\nBinarbaum inorder" << tree.inorder();
	cout << "\nBinarbaum postorder" << tree.postorder();
	cout << "\nBinarbaum preorder" << tree.preorder();
	
	tree.remove(5)
	
	return 0;
}
