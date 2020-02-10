#pragma once

#include "LinkedList.h"

template <class Type>
class UnorderedLinkedList : public linkedListType<Type>
{
public:
	bool search(const Type& searchItem) const;
	void insertFirst(const Type& newItem);
	void insertLast(const Type& newItem);
	void deleteNode(const Type& deleteItem);
};