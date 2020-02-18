// chapter_5.cpp : Linked lists

#include <iostream>
#include <list>

int main()
{
	std::list<int> myList;
	for (int i = 0; i < 100; i++)
	{
		myList.push_back(i);
	}


	auto it = myList.begin();
	while (it != myList.end())
	{
		std::cout << *it << std::endl;
		it++;
	}

	return 0;
}
