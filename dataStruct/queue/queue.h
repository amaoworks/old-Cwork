#include <stdlib.h>
#include <stdio.h>

#ifndef queue_h
#define queue_h
typedef int DataType; 

typedef struct _node{
	DataType data;
	struct _node *next;
} Node;

typedef struct _queue{
	Node *head;
	Node *tail;
} Queue;

void initQueue(Queue *);
void enQueue(Queue *, DataType);
void deQueue(Queue *);
int getLength(Queue *);
void dispQueue(Queue *);

#endif
