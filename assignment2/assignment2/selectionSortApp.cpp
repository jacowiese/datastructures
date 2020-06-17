#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "arrayListType.h"

using namespace std;

int main(void)
{
	cout << "Selection Sort algorithm:" << endl;
	string numbers;
	cout << "Input list (sep by spaces): ";
	getline(cin, numbers, '\n');
	istringstream iss(numbers);

	arrayListType<int> arrayList(100);
	string token;

	while (getline(iss, token, ' '))
	{
		if (!token.empty())
		{
			arrayList.insert(stoi(token));
		}
	}

	arrayList.print();

	return 0;
}