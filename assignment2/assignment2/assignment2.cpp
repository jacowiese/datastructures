// assignment2.cpp

#include <iostream>
#include <iomanip>
#include <string>
#include "arrayStack.h"
#include "arrayQueue.h"

using namespace std;


void printlist(int* list, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << setw(2) << list[i] << " | ";
	}
	cout << endl;
}

void swap(int* list, int first, int second)
{
	int temp = list[first];
	list[first] = list[second];
	list[second] = temp;
}

int partition(int* list, int first, int last)
{
	int pivot, index, smallIndex;

	swap(list, first, (first + last) / 2);

	pivot = list[first];
	smallIndex = first;

	for (index = first + 1; index <= last; index++)
	{
		if (list[index] < pivot)
		{
			smallIndex++;
			swap(list, smallIndex, index);
		}
	}

	swap(list, first, smallIndex);
	printlist(list, 11);

	return smallIndex;
}

void recquicksort(int* list, int first, int last)
{
	int pivotLocation;

	if (first < last)
	{
		pivotLocation = partition(list, first, last);
		recquicksort(list, first, pivotLocation - 1);
		recquicksort(list, pivotLocation + 1, last);
	}
}

void quicksort(int* list, int size)
{
	recquicksort(list, 0, size-1);
}

int main()
{
	int list[] = {11, 8, 9, 4, 2, 5, 3, 12, 6, 10, 7};
	printlist(list, 11);

	quicksort(list, 11);
	printlist(list, 11);
}