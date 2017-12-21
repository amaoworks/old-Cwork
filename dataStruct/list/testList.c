#include "list.h"
#include <stdlib.h>

int main(int argc, char **argv)
{
	List *list1 = (List *)malloc(sizeof(List));
	printf("the first:\n");
	initList(list1);
	addHead(list1, 1);
	addHead(list1, 3);
	addHead(list1, 5);
	addHead(list1, 7);
	addHead(list1, 9);
	dispList(list1);
	printf("the second:\n");
	deleNode(list1, 1);
	dispList(list1);
	printf("The length: %d\n", getLength(list1));
	Node *node = getNode(list1, 7);
	printf("The getNode result: %d\n", node->data);

	return 0;
}
