#ifndef __LINKEDQUEUE_TYPE_H
#define __LINKEDQUEUE_TYPE_H

#include <cassert>
#include "queueADT.h"

template <class Type>
struct nodeTypeQueue
{
	Type info;
	nodeTypeQueue<Type>* link;
};

template <class Type>
class linkedQueueType : public queueADT<Type>
{
public:
	const linkedQueueType<Type>& operator=(const linkedQueueType<Type>&);

	bool isEmptyQueue() const;

	bool isFullQueue() const;

	void initializeQueue();

	Type front() const;

	Type back() const;

	void addQueue(const Type& queueElement);

	void deleteQueue();

	linkedQueueType();

	~linkedQueueType();

	linkedQueueType(const linkedQueueType<Type>& otherQueue);

	void printQueue();

private:
	nodeTypeQueue<Type>* queueFront;
	nodeTypeQueue<Type>* queueRear;
};

#endif

template<class Type>
const linkedQueueType<Type>& linkedQueueType<Type>::operator=(const linkedQueueType<Type>&)
{
	return NULL;
}

template<class Type>
bool linkedQueueType<Type>::isEmptyQueue() const
{
	return queueFront == NULL;
}

template<class Type>
bool linkedQueueType<Type>::isFullQueue() const
{
	return false; // Only full when no more memory is available.
}

template<class Type>
void linkedQueueType<Type>::initializeQueue()
{
	nodeTypeQueue<Type>* temp;

	// Clear the queue from the front
	while (queueFront != NULL)
	{
		temp = queueFront;
		queueFront = queueFront->link;
		delete temp;
	}

	queueRear = NULL;
}

template<class Type>
Type linkedQueueType<Type>::front() const
{
	assert(queueFront != NULL);
	return queueFront->info;
}

template<class Type>
Type linkedQueueType<Type>::back() const
{
	assert(queueRear != NULL);
	return queueRear->info;
}

template<class Type>
void linkedQueueType<Type>::addQueue(const Type& queueElement)
{
	nodeTypeQueue<Type>* newNode = new nodeTypeQueue<Type>;
	newNode->info = queueElement;
	newNode->link = NULL;

	if (queueFront == NULL)
	{
		queueFront = newNode;
		queueRear = queueFront;
	}
	else {
		queueRear->link = newNode;
		queueRear = queueRear->link;
	}
}

template<class Type>
void linkedQueueType<Type>::deleteQueue()
{
	nodeTypeQueue<Type>* temp;

	if (!isEmptyQueue())
	{
		temp = queueFront;
		queueFront = queueFront->link;
		delete temp;

		if (queueFront == NULL)
			queueRear = NULL;
	}
	else {
		std::cout << "Cannot remove from an empty queue." << std::endl;
	}
}

template<class Type>
linkedQueueType<Type>::linkedQueueType()
{
	queueFront = queueRear = NULL;
}

template<class Type>
linkedQueueType<Type>::~linkedQueueType()
{
	if (!isEmptyQueue())
	{
		deleteQueue();
	}
}

template<class Type>
linkedQueueType<Type>::linkedQueueType(const linkedQueueType<Type>& otherQueue)
{
	if (otherQueue.isEmptyQueue())
		return;

	nodeTypeQueue<Type>* temp = otherQueue.queueFront;

	while (temp != NULL)
	{
		addQueue(temp->info);
		temp = temp->link;
	}
}

template<class Type>
void linkedQueueType<Type>::printQueue()
{
	nodeTypeQueue<Type>* temp = queueFront;
	std::cout << std::endl;
	while (temp != NULL)
	{
		std::cout << temp->info << " ";
		temp = temp->link;
	}
	std::cout << std::endl;
}
