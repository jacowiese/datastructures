// Quicksort program

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
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
	cout << endl;
	cout << "pivot: " << pivot << endl;

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
//
//int main()
//{
//
//	cout << "Quicksort algorithm:" << endl;
//	string numbers;
//	cout << "Input list (sep by spaces): ";
//	getline(cin, numbers, '\n');
//	istringstream iss(numbers);
//
//	vector<string> tokens;
//	string token;
//	
//	while (getline(iss, token, ' '))
//	{
//		if (!token.empty())
//		{
//			tokens.push_back(token);
//		}
//	}
//
//	int size = tokens.size();
//	int* list = new int[size];
//	for (int i = 0; i < size; i++)
//		list[i] = stoi(tokens[i]);
//
//	quicksort(list, size);
//
//	delete[] list;
//}