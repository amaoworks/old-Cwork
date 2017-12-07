#include "linkedList.h"

void initalizeList(LinkedList *list) {
	list->head = NULL;
	list->tail = NULL;
	list->current = NULL;
}

void addHead(LinkedList *list ,void* data) {
	Node *node = (Node*)malloc(sizeof(Node));
	node->data = data;
	if (list->head == NULL ) {
		list->tail = node;
		node->next = NULL;
	} else {
		node->next = list->head;
	}
	list->head = node;
}

void addTail(LinkedList *list ,void* data) {
	Node *node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	if (list->head == NULL) {
		list->head = node;
	} else {
		list->tail->next = node;
	}
	list->tail = node;
}

void delete(LinkedList *list ,Node *node) {
	if(node == list->head){
		if(list->head->next == NULL) {
			list->head = list->tail = NULL;
		} else {
			list->head = list->head->next;
		}
	} else {
		Node *tmp = list->head;
		while(tmp != NULL && tmp->next != node) {
			tmp = tmp->next;
		}
		if(tmp != NULL) {
			tmp->next = node->next;
		}
	}
	free(node);
}

int compare(void* data1 ,void* data2){
	    if(data1 > data2)
		return 1;
	    else if(data1 == data2)
		return 0;
	    else 
		return -1;
	}

void *getNode(LinkedList *list ,COMPARE compare ,void* data) {
	Node *node = list->head;
	while(node != NULL) {
		if(compare(node->data ,data) == 0) {
			return node;
		}
		node = node->next;
	}
	return NULL;
}

void displayLinkedList(LinkedList *list) {
	printf("\nLinked List\n");
	Node *node = list->head;
	while(node != NULL) {
		printf("%d\t",node->data);
		node = node->next;
	}
	printf("\n");
}
