#include <stdio.h>
#include "linkedList.h"

int main(int argc ,char **argv ){
	LinkedList linkedlist;
	initalizeList(&linkedlist);

	addHead(&linkedlist,1);
	addHead(&linkedlist,3);
	addHead(&linkedlist,5);
	addHead(&linkedlist,7);
	displayLinkedList(&linkedlist);

	addTail(&linkedlist,2);
	addTail(&linkedlist,4);
	addTail(&linkedlist,6);
	displayLinkedList(&linkedlist);

	Node *node = getNode(&linkedlist ,compare ,7 );
	delete(&linkedlist ,node );
	displayLinkedList(&linkedlist);

	return 0;
}
