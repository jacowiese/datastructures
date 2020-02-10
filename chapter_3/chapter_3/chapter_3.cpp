// chapter_3.cpp : Pointers & Array based lists

#include <iostream>
#include <iomanip>
#include <string>
#include "ArrayListType.h"

using namespace std;

void example_1() {
	int *p;
	int num1 = 5;
	int num2 = 8;

	p = &num1;

	cout << "&num1 = " << &num1 << ", p = " << p << endl;
	cout << "num1 = " << num1 << ", *p = " << *p << endl;

	*p = 10;
	cout << "num1 = " << num1 << ", *p = " << *p << endl;

	p = &num2;

	cout << "&num2 = " << &num2 << ", p = " << p << endl;
	cout << "num2 = " << num2 << ", *p = " << *p << endl;

	*p = 2 * (*p);

	cout << "num2 = " << num2 << ", *p = " << *p << endl;
}

void example_2() {
	// Single value
	int *p = new int;
	*p = 28;
	cout << *p << endl;
	delete p;

	// Array values
	int *q = new int[10];
	q[0] = 10;
	delete[] q;
}

void example_3() {
	// Same address allocated, not the same value anymore
	int *p = new int;
	*p = 6;
	cout << "p = " << *p << ", &p = " << p << endl;
	delete p;
	int *q = new int;
	cout << "q = " << *q << ", &q = " << q << endl;
	delete q;
}

void example_4() {
	int **board = new int*[10];
	for (int i = 0; i < 10; i++)
		board[i] = new int[15];

	for (int j = 0; j < 10; j++) {
		for (int i = 0; i < 15; i++) {
			board[j][i] = i * j + 10;
		}
	}

	for (int j = 0; j < 10; j++) {
		for (int i = 0; i < 15; i++) {
			cout << setw(3) << board[j][i]  << ", ";
		}
		cout << endl;
	}
}

void example_5() {
	int *p = new int;
	int *q = new int;
	*p = 5;
	*q = 6;
	cout << "&p = " << p << ", p = " << *p << endl;
	cout << "&q = " << q << ", q = " << *q << endl;
	p++;
	q++;
	cout << "&p = " << p << ", p = " << *p << endl;
	cout << "&q = " << q << ", q = " << *q << endl;
}

int main()
{
	// example_1();
	// example_2();
	// example_3();
	// example_4();
	// example_5();

	ArrayListType<int> intList(100);
	ArrayListType<string> stringList;

	for (int counter = 0; counter < 5; counter++) {
		intList.insertAt(counter, counter * 10 + 10);
	}
	intList.print();

	return 0;
}
