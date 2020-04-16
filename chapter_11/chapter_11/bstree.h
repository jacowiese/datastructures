#ifndef __BSTREE_H
#define __BSTREE_H

#include "binaryTreeADT.h"

template <class elemType>
class bSearchTreeType : public binaryTreeType<elemType>
{
public:
	bool search(const elemType &searchItem) const;

	void insert(const elemType &insertItem);

	void deleteNode(const elemType &deleteItem);

private:
	void deleteFromTree(binaryTreeNode<elemType> *&p);
};

template <class elemType>
bool bSearchTreeType<elemType>::search(const elemType &searchItem) const
{
	binaryTreeNode<elemType> *current;
	bool found = false;

	if (this->root == NULL)
		std::cerr << "Cannot search an empty tree." << std::endl;
	else
	{
		current = this->root;

		while (current != NULL && !found)
		{
			if (current->info == searchItem)
				found = true;
			else if (current->info > searchItem)
				current = current->llink;
			else
				current = current->rlink;
		}
	}

	return found;
}

template <class elemType>
void bSearchTreeType<elemType>::insert(const elemType &insertItem)
{
	binaryTreeNode<elemType> *current = NULL;
	binaryTreeNode<elemType> *trailCurrent = NULL;
	binaryTreeNode<elemType> *newNode;

	newNode = new binaryTreeNode<elemType>;
	newNode->info = insertItem;
	newNode->llink = NULL;
	newNode->rlink = NULL;

	if (this->root == NULL) // If this is the first node
	{
		this->root = newNode;
	}
	else // If not the first node
	{
		current = this->root;

		while (current != NULL)
		{
			trailCurrent = current;

			if (current->info == insertItem)
			{
				std::cerr << "Item is already in the list: " << insertItem << std::endl;
				return;
			}
			else
			{
				if (current->info > insertItem)
				{
					current = current->llink;
				}
				else {
					current = current->rlink;
				}
			}
		}

		if (trailCurrent->info > insertItem)
			trailCurrent->llink = newNode;
		else
			trailCurrent->rlink = newNode;
	}
}

template <class elemType>
void bSearchTreeType<elemType>::deleteNode(const elemType &deleteItem)
{
	binaryTreeNode<elemType> *current, *trailCurrent;
	bool found = false;

	if (this->root == NULL)
		std::cerr << "Cannot delete from an empty tree." << std::endl;
	else
	{
		current = this->root;
		trailCurrent = current;

		while (current != NULL && !found)
		{
			if (current->info == deleteItem)
				found = true;
			else
			{
				trailCurrent = current;

				if (current->info > deleteItem)
					current = current->llink;
				else
					current = current->rlink;
			}
		}

		if (current == NULL)
			std::cerr << "The item to delete is not in the tree: " << deleteItem << std::endl;
		else
		{
			if (current == this->root)
				deleteFromTree(this->root);
			else if (trailCurrent->info > deleteItem)
				deleteFromTree(trailCurrent->llink);
			else
				deleteFromTree(trailCurrent->rlink);
		}
	}
}

template <class elemType>
void bSearchTreeType<elemType>::deleteFromTree(binaryTreeNode<elemType> *&p)
{
	binaryTreeNode<elemType> *current;
	binaryTreeNode<elemType> *trailCurrent;
	binaryTreeNode<elemType> *temp;

	if (p == NULL)
	{
		std::cerr << "Error: The node to be deleted is NULL." << std::endl;
	}
	else
	{
		if (p->llink == NULL && p->rlink == NULL) // Case 1
		{
			temp = p;
			p = NULL;
			delete temp;
		}
		else if (p->llink == NULL) // Case 2
		{
			temp = p;
			p = temp->llink;
			delete temp;
		}
		else if (p->rlink == NULL) // Case 3
		{
			temp = p;
			p = temp->rlink;
			delete temp;
		}
		else // Case 4
		{
			current = p->llink;
			trailCurrent = NULL;

			while (current->rlink != NULL)
			{
				trailCurrent = current;
				current = current->rlink;
			}

			p->info = current->info;

			if (trailCurrent == NULL)
				p->llink = current->llink;
			else
				trailCurrent->rlink = current->llink;

			delete current;
		}
	}
}

#endif
