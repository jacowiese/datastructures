#include <iostream>
#include "stackType.h"
#include "queueType.h"

using namespace std;

int main()
{
	stackType<int> stack;

	stack.push(5);
	cout << stack.top();
	stack.pop();

	queueType<int> queue;
	queue.addQueue(5);
	queue.addQueue(6);
	cout << queue.front();
	cout << queue.back();
}
