// chapter_11.cpp : Binary Tree implementation

#include <iostream>
#include "bstree.h"
#include <string>

using namespace std;

int main()
{
	bSearchTreeType<int> tree;

	tree.insert(6);
	tree.insert(3);
	tree.insert(12);
	tree.insert(8);
	tree.insert(1);
	tree.insert(3);

	tree.search(6);

	tree.deleteNode(6);

	cout << "Inorder traversal:" << endl;
	tree.inorderTraversal();

	cout << endl << "Preorder traversal:" << endl;
	tree.preorderTraversal();

	cout << endl << "Postorder traversal:" << endl;
	tree.postorderTraversal();
}
