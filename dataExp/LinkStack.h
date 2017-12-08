#ifndef LinkStack_h
#define LinkStack_h

#include <stdio.h>
#include <stdlib.h>

typedef int SElemType;
typedef struct node {
	SElemType data;
	struct node *link;
} LinkNode ,*LinkList ,*LinkStack;

#endif
