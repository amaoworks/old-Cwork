#ifndef linkedList_h
#define linkedList_h

#include <stdlib.h>
#include <stdio.h>

typedef struct _node {
	void *data;
	struct _node *next;
} Node;

typedef struct _linkedList {
	Node *head;
	Node *tail;
	Node *current;
} LinkedList;

typedef int(*COMPARE) (void*,void*);
int compare(void*,void*);

void initalizeList(LinkedList* );			//初始化链表
void addHead(LinkedList* ,void* );			//给链表的头节点添加数据
void addTail(LinkedList* ,void* );			//给链表的尾节点添加数据
void delete(LinkedList* ,Node* );			//从链表删除节点
void *getNode(LinkedList* ,COMPARE ,void* );//返回包含指定数据的节点指针
void displayLinkedList(LinkedList* );//打印链表

#endif
