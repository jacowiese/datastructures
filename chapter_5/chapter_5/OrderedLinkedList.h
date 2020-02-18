#pragma once
#include "LinkedList.h"

template <class T>
class OrderedLinkedList : public linkedListType<T>
{
public:
	bool search(const Type& searchItem) const;
	void insertFirst(const Type& newItem);
	void insertLast(const Type& newItem);
	void deleteNode(const Type& deleteItem);
};

template<class T>
inline bool OrderedLinkedList<T>::search(const Type & searchItem) const
{
	return false;
}

template<class T>
inline void OrderedLinkedList<T>::insertFirst(const Type & newItem)
{
}

template<class T>
inline void OrderedLinkedList<T>::insertLast(const Type & newItem)
{
}

template<class T>
inline void OrderedLinkedList<T>::deleteNode(const Type & deleteItem)
{
}
