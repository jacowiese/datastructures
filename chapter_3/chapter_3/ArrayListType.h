#ifndef __ARRAY_LIST_TYPE
#define __ARRAY_LIST_TYPE

template <class elemType>
class ArrayListType 
{
public:
	ArrayListType(int size = 100);
	ArrayListType(const ArrayListType<elemType>& otherList);
	~ArrayListType();

	const ArrayListType<elemType>& operator=(const ArrayListType<elemType>&);
	bool isEmpty() const;
	bool isFull() const;
	int listSize() const;
	int maxListSize() const;
	void print() const;
	bool isItemAtEqual(int location, const elemType& item) const;
	void insertAt(int locaiton, const elemType& insertItem);
	void insertEnd(const elemType &insertItem);
	void removeAt(int location);
	void retrieveAt(int location, elemType &retItem) const;
	void replaceAt(int location, const elemType &repItem);
	void clearList();
	int seqSearch(const elemType &item) const;
	void insert(const elemType &insertItem);
	void remove(const elemType &removeItem);

protected:
	elemType *list;
	int length;
	int maxSize;
};

#endif