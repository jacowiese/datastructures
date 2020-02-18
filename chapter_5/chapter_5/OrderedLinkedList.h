#pragma once
#include "LinkedList.h"

template <class Type>
class OrderedLinkedList : public linkedListType<Type>
{
public:
	bool search(const Type& searchItem) const;
	void insertFirst(const Type& newItem);
	void insertLast(const Type& newItem);
	void deleteNode(const Type& deleteItem);
	void insert(const Type& newItem);
};

template<class Type>
inline bool OrderedLinkedList<Type>::search(const Type & searchItem) const
{
	nodeType<Type> *current = this->first;
	bool result = false;

	while (result != true && current != NULL) 
	{
		// Break and return true if item found
		if (current->info == searchItem)
		{
			result = true;
			break;
		}
		// Break and return false if we went past our item
		else if (current->info > searchItem)
		{
			result = false;
			break;
		}

		current = current->link;
	}

	return result;
}

template<class Type>
inline void OrderedLinkedList<Type>::insert(const Type& newItem)
{
	nodeType<Type> *node = new nodeType<Type>();
	node->info = newItem;
	node->link = NULL;

	// First item in the list
	if (this->first == NULL && this->last == NULL)
	{
		this->first = node;
		this->last = this->first;
		this->count++;
	}
	else
	{
		nodeType<Type> *current = this->first;
		nodeType<Type> *prev = current;
		while (current != NULL)
		{	// Item is before current
			if (node->info < current->info)
			{
				if (current == this->first)
				{
					// Item is the first item of the list
					node->link = this->first;
					this->first = node;
					this->count++;
					break;
				}
				else
				{ // Item is in the middle of the list before current
					prev->link = node;
					node->link = current;
					this->count++;
					break;
				}
			}
			// Cater for last item in the list
			else if (current->link == NULL)
			{
				current->link = node;
				this->last = node;
				this->count++;
				break;
			}
			prev = current;
			current = current->link;
		}
	}
}

template<class Type>
inline void OrderedLinkedList<Type>::insertFirst(const Type & newItem)
{
	insert(newItem);
}

template<class Type>
inline void OrderedLinkedList<Type>::insertLast(const Type & newItem)
{
	insert(newItem);
}

template<class Type>
inline void OrderedLinkedList<Type>::deleteNode(const Type & deleteItem)
{
	// Cannot delete from empty list
	if (this->first == NULL)
		return;

	nodeType<Type> *current = this->first;
	nodeType<Type> *prev = current;

	while (current != NULL)
	{
		if (current->info == deleteItem)
		{
			// Item to be deleted is the first item in the list
			if (current == this->first)
			{
				current = current->link;
				this->first = current;
				this->count--;
				break;
			}
			else {
				prev->link = current->link;
				this->count--;
				break;
			}
		}
		else if (current->info > deleteItem)
		{
			break;
		}

		prev = current;
		current = current->link;
	}
}
