#include "UnorderedLinkedList.h"
#include "LinkedList.h"
#include <iostream>

template <class Type>
bool UnorderedLinkedList<Type>::search(const Type& searchItem) const
{
	nodeType<Type> *current = this->first;
	bool found = false;

	while (current != NULL && !found)
	{
		if (current->info == searchItem)
		{
			found = true;
		}
		else {
			current = current->link;
		}
	}

	return found;
}

template <class Type>
void UnorderedLinkedList<Type>::insertFirst(const Type& newItem)
{
	nodeType<Type> *newNode = new nodeType<Type>;
	newNode->info = newItem;
	newNode->link = this->first;
	this->first = newNode;
	this->count++;

	// If the list was empty to begin with, newNode is also the last node in the list
	if (this->last == NULL)
	{
		this->last = newNode;
	}
}

template <class Type>
void UnorderedLinkedList<Type>::insertLast(const Type& newItem)
{
	nodeType<Type> *newNode = new nodeType<Type>;
	newNode->info = newItem;
	newNode->link = NULL;

	// If the list is empty, newNode is both the first and last node
	if (this->first == NULL)
	{
		this->first = newNode;
		this->last = newNode;
		this->count++;
	} else
	{ // The list is not empty, insert newNode after last
		this->last->link = newNode;
		this->last = newNode;
		this->count++;
	}
}

template <class Type>
void UnorderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
	nodeType<Type> *current;
	nodeType<Type> *trailCurrent;
	bool found;

	if (this->first == NULL) // Case 1
	{
		std::cout << "Cannot delete from an empty list." << std::endl;
	}
	else {
		if (this->first->info == deleteItem) // Case 2
		{
			current = this->first;
			this->first = this->first->link;
			this->count--;

			if (this->first == NULL) // the list has only one node
				this->last = NULL;

			delete current;
		}
		else {
			// search the list for the node with the given info to be deleted
			found = false;
			trailCurrent = this->first;
			current = this->first->link;

			while (current != NULL && !found)
			{
				if (current->info != deleteItem)
				{
					trailCurrent = current;
					current = current->link;
				}
				else {
					found = true;
				}
			}

			if (found) // Case 3
			{
				trailCurrent->link = current->link;
				this->count--;

				if (this->last == current)
				{
					this->last = trailCurrent;
				}

				delete current;
			}
			else {
				std::cout << "The item to be deleted is not in the list." << std::endl;
			}
		}
	}
}
