// chapter_5.cpp : Linked lists

#include <iostream>
#include "UnorderedLinkedList.h"

int main()
{
	UnorderedLinkedList<int> itemList;
	itemList.insertFirst(6);
	itemList.print();

	return 0;
}
