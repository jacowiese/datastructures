#include "ArrayListType.h"
#include <iostream>

using namespace std;

template <class elemType>
ArrayListType<elemType>::ArrayListType(int size)
{
	if (size < 0) {
		cerr << "The array size must be positive. Creating an array with size 100." << endl;
		maxSize = 100;
	}
	else {
		maxSize = size;
	}

	length = 0;
	list = new elemType[maxSize];
	assert(list != NULL);
}

template <class elemType>
ArrayListType<elemType>::ArrayListType(const ArrayListType<elemType>& otherList)
{
	maxSize = otherList.maxSize;
	length = otherList.length;
	list = new elemType[maxSize];
	assert(list != NULL);

	for (int j = 0; j < length; j++) {
		list[j] = otherList.list[j];
	}
}

template <class elemType>
ArrayListType<elemType>::~ArrayListType()
{
	delete[] list;
}

template <class elemType>
const ArrayListType<elemType>& ArrayListType<elemType>::operator=(const ArrayListType<elemType>& otherList)
{
	if (this != otherList) {
		delete[] list;
		maxSize = otherList.maxSize;
		length = otherList.length;

		list = new elemType[maxSize];
		assert(list != NULL);

		for (int i = 0; i < length; i++) {
			list[i] = otherList.list[i];
		}
	}

	return *this;
}

template <class elemType>
bool ArrayListType<elemType>::isEmpty() const
{
	return (length == 0);
}

template <class elemType>
bool ArrayListType<elemType>::isFull() const
{
	return (length == maxSize);
}

template <class elemType>
int ArrayListType<elemType>::listSize() const
{
	return length;
}

template <class elemType>
int ArrayListType<elemType>::maxListSize() const
{
	return maxListSize;
}

template <class elemType>
void ArrayListType<elemType>::print() const
{
	for (int i = 0; i < length; i++) {
		cout << list[i] << " ";
	}
	cout << endl;
}

template <class elemType>
bool ArrayListType<elemType>::isItemAtEqual(int location, const elemType& item) const
{
	return (list[location] == item);
}

template <class elemType>
void ArrayListType<elemType>::insertAt(int locaiton, const elemType& insertItem)
{
	if (locaiton < 0 || locaiton >= maxSize) {
		cerr << "The position of the item to be inserted is out of range" << endl;
	} else {
		if (length >= maxSize) {
			cerr << "Cannot insert into a full list" << endl;
		}
		else {
			// Move each item down
			for (int i = length; i > locaiton; i--)
			{
				list[i] = list[i - 1];
			}
			
			list[locaiton] = insertItem;
			length++;
		}
	}
}

template <class elemType>
void ArrayListType<elemType>::insertEnd(const elemType &insertItem)
{
	if (length >= maxSize) {
		cerr << "Cannot insert into a full list" << endl;
	}
	else {
		list[length] = insertItem;
		length++;
	}
}

template <class elemType>
void ArrayListType<elemType>::removeAt(int location)
{
	if (location < 0 || location >= length) {
		cerr << "The location of the item to be removed is out of range" << endl;
	}
	else {
		for (int i = location; i < length - 1; i++) {
			list[i] = list[i + 1];
		}

		length--;
	}
}

template <class elemType>
void ArrayListType<elemType>::retrieveAt(int location, elemType &retItem) const
{
	if (location < 0 || location >= length) {
		cerr << "The location of the item to be retrieved is out of range" << endl;
	}
	else {
		retItem = list[location];
	}
}

template <class elemType>
void ArrayListType<elemType>::replaceAt(int location, const elemType &repItem)
{
	if (location < 0 || location >= length) {
		cerr << "The location of the item to be replaced is out of range" << endl;
	}
	else {
		list[location] = repItem;
	}
}

template <class elemType>
void ArrayListType<elemType>::clearList()
{
	length = 0;
}

template <class elemType>
int ArrayListType<elemType>::seqSearch(const elemType &item) const
{
	int loc;
	bool found = false;

	for (loc = 0; loc < length; loc++) {
		if (list[loc] == item) {
			found = true;
			break;
		}
	}

	if (found) {
		return loc;
	}
	else {
		return -1;
	}
}

template <class elemType>
void ArrayListType<elemType>::insert(const elemType &insertItem)
{
	int loc;
	if (length == 0) {
		list[length++] = insertItem;
	}
	else if (length == maxSize) {
		cerr << "Cannot insert into a full list." << endl;
	}
	else {
		loc = seqSearch(insertItem);

		if (loc == -1) {
			list[length++] = insertItem;
		}
		else {
			cerr << "The item to be inserted is already in the list." << endl;
		}
	}
}

template <class elemType>
void ArrayListType<elemType>::remove(const elemType &removeItem)
{
	int loc;

	if (length == 0) {
		cerr << "Cannot delete from an empty list." << endl;
	}
	else {
		loc = seqSearch(removeItem);
		if (loc != -1) {
			removeAt(loc);
		}
		else {
			cout << "The item to be deleted is not in the list." << endl;
		}
	}
}
