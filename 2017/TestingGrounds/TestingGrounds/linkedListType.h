#pragma once

#include <iostream>
#include <assert.h>

template <class Type>
struct nodeType
{
	Type info;
	nodeType<Type> *link;
};

template <class Type>
class linkedListIterator
{
public:
	linkedListIterator();
	linkedListIterator(nodeType<Type> *ptr);
	Type operator*();
	linkedListIterator<Type> operator++();
	bool operator==(const linkedListIterator<Type>& right) const;
	bool operator!=(const linkedListIterator<Type>& right) const;

private:
	nodeType<Type> *current;
};

template <class Type>
class linkedListType
{
public:

	// Constructors
	linkedListType();
	linkedListType(const linkedListType<Type>& otherList);

	// Destructor
	virtual ~linkedListType();

	// Override assignment operator
	const linkedListType<Type>& operator=(const linkedListType<Type>&);

	void initializeList();

	bool isEmptyList() const;

	void print() const;

	int length() const;

	void destroyList();

	Type front() const;

	Type back() const;

	virtual bool search(const Type& searchItem) const = 0;

	virtual void insertFirst(const Type& newItem) = 0;

	virtual void insertLast(const Type& newItem) = 0;

	virtual void deleteNode(const Type& deleteItem) = 0;

	linkedListIterator<Type> begin();

	linkedListIterator<Type> end();

private:
	void copyList(const linkedListType<Type>& otherList);

protected:
	int count;
	nodeType<Type> *first;
	nodeType<Type> *last;
};

template <class Type>
linkedListIterator<Type>::linkedListIterator()
{
	current = NULL;
}

template <class Type>
linkedListIterator<Type>::linkedListIterator(nodeType<Type> *ptr)
{
	current = ptr;
}

template <class Type>
Type linkedListIterator<Type>::operator*()
{
	return current->info;
}

template <class Type>
linkedListIterator<Type> linkedListIterator<Type>::operator++()
{
	current = current->link;

	return *this;
}

template <class Type>
bool linkedListIterator<Type>::operator==(const linkedListIterator<Type>& right) const
{
	return (current == right.current);
}

template <class Type>
bool linkedListIterator<Type>::operator!=(const linkedListIterator<Type>& right) const
{
	return (current != right.current);
}

template <class Type>
linkedListIterator<Type> linkedListType<Type>::begin()
{
	linkedListIterator<Type> temp(first);
	return temp;
}

template <class Type>
linkedListIterator<Type> linkedListType<Type>::end()
{
	linkedListIterator<Type> temp(NULL);
	return temp;
}

template <class Type>
linkedListType<Type>::linkedListType()
{
	first = NULL;
	last = NULL;
	count = 0;
}

template <class Type>
linkedListType<Type>::linkedListType(const linkedListType<Type>& otherList)
{
	first = NULL;
	copyList(otherList);
}

template <class Type>
linkedListType<Type>::~linkedListType()
{
	destroyList();
}

// Override assignment operator
template <class Type>
const linkedListType<Type>& linkedListType<Type>::operator=(const linkedListType<Type>& otherList)
{
	// Avoid self-copy
	if (this != &otherList)
	{
		copyList(otherList);
	}

	return *this;
}

template <class Type>
void linkedListType<Type>::initializeList()
{
	destroyList();
}

template <class Type>
bool linkedListType<Type>::isEmptyList() const
{
	return (first == NULL);
}

template <class Type>
void linkedListType<Type>::print() const
{
	nodeType<Type> *current = first;

	while (current != NULL)
	{
		std::cout << current->info << " ";
		current = current->link;
	}
}

template <class Type>
int linkedListType<Type>::length() const
{
	return count;
}

template <class Type>
void linkedListType<Type>::destroyList()
{
	nodeType<Type> *temp;

	while (first != NULL)
	{
		temp = first;
		first = first->link;
		delete temp;
	}

	last = NULL;
	count = 0;
}

template <class Type>
Type linkedListType<Type>::front() const
{
	assert(first != NULL);

	return first->info;
}

template <class Type>
Type linkedListType<Type>::back() const
{
	assert(last != NULL);

	return last->info;
}

template <class Type>
void linkedListType<Type>::copyList(const linkedListType<Type>& otherList)
{
	nodeType<Type> *newNode;
	nodeType<Type> *current;

	// If the list is not empty, make it empty
	if (first != NULL)
		destroyList();

	// If otherlist is empty
	if (otherList.first == NULL)
	{
		first = NULL;
		last = NULL;
		count = 0;
	}
	else {
		current = otherList.first;
		count = otherList.count;

		// Copy and make the first link
		first = new nodeType<Type>;
		first->info = current->info;
		first->link = NULL;
		last = first;

		// Copy the rest of the links
		current = current->link;
		while (current != NULL)
		{
			newNode = new nodeType<Type>;
			newNode->info = current->info;
			newNode->link = NULL;

			last->link = newNode;
			last = newNode;
			current = current->link;
		}
	}
}