#include <stdlib.h>
#include <stdio.h>

#include "list.h"

//链表初始化
void initList(List *list){
	list->head = NULL;
	list->tail = NULL;
	list->current = NULL;
}

//链表头插法
void addHead(List *list, DataType iData){
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = iData;
	node->next = NULL;

	if(list->head == NULL){
		list->tail = node;
	}else{
		node->next = list->head;
	}
	list->head = node;

	return;
}

//链表尾插法
void addTail(List *list, DataType iData){
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = iData;
	node->next = NULL;

	if(list->head == NULL){
		list->head = node;
	}else{
		list->tail->next = node;
	}
	list->tail = node;

	return;
	
}

//链表节点获取
Node *getNode(List *list, DataType iData){
	Node *node = (Node *)malloc(sizeof(Node));
	node = list->head;
	while(node != NULL){
		if(node->data == iData){
			return node;
		}else{
			node = node->next;
		}
	}

	return NULL;
}

//删除链表中的节点
void deleNode(List *list, DataType iData){
	if(list->head->data == iData){
		list->head = list->head->next;
	}
	Node *prev = list->head;
	Node *node = prev->next;
	while(node != NULL){
		if(node->data == iData){
			prev->next = prev->next->next;

			return;
		}else{
			prev = prev->next;
			node = node->next;
		}
	}

	return;
}

//链表长度
int getLength(List *list){
	Node *node = list->head;
	int i = 0;
	while(node != NULL){
		node = node->next;
		i++;
	}

	return i;
}

//链表输出
void dispList(List *list){
	Node *node = list->head;
	int i = 0;
	while(node != NULL){
		printf("the %dth node: %d\n", i + 1, node->data);
		node = node->next;
		i++;
	}
	printf("disp finished!\n");

	return;
}
