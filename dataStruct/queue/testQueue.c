#include "queue.h"

int main(int argc, char **argv)
{
	Queue *queue1 = (Queue *)malloc(sizeof(Queue));
	printf("the first:\n");
	initQueue(queue1);
	enQueue(queue1, 1);
	enQueue(queue1, 3);
	enQueue(queue1, 5);
	enQueue(queue1, 7);
	enQueue(queue1, 9);
	printf("The length: %d\n", getLength(queue1));
	dispQueue(queue1);
	printf("the second:\n");
	deQueue(queue1);
	printf("The length: %d\n", getLength(queue1));
	dispQueue(queue1);
	deQueue(queue1);
	dispQueue(queue1);
	printf("The length: %d\n", getLength(queue1));
	enQueue(queue1, 11);
	dispQueue(queue1);
	printf("The length: %d\n", getLength(queue1));

	return 0;
}
