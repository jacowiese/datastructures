#include <iostream>
#include "linkedQueueType.h"

using namespace std;

int main(void)
{
	linkedQueueType<int> queue1;
	queue1.addQueue(6);
	queue1.addQueue(12);
	queue1.addQueue(18);
	queue1.addQueue(24);
	queue1.printQueue();

	linkedQueueType<int> queue2(queue1);
	queue2.printQueue();

	return 0;
}