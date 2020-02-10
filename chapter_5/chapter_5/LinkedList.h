#pragma once

template <class Type>
struct nodeType
{
	Type info;
	nodeType<Type> link;
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
	~linkedListType();

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
