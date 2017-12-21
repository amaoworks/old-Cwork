#include "queue.h"

//队列初始化
void initQueue(Queue *queue){
	queue->head = NULL;
	queue->tail = NULL;
}

//队列入
void enQueue(Queue *queue, DataType iData){
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = iData;
	node->next = NULL;

	if(queue->head == NULL){
		queue->head = node;
	}else{
		queue->tail->next = node;
	}
	queue->tail = node;

	return;
	
}

//队列出
void deQueue(Queue *queue){
	if(queue->head->next == NULL){
		queue->head = NULL;;
	}else{
		queue->head = queue->head->next;
	}

	return;
}

//队列长度
int getLength(Queue *queue){
	Node *node = queue->head;
	int i = 0;
	while(node != NULL){
		node = node->next;
		i++;
	}

	return i;
}

//队列输出
void dispQueue(Queue *queue){
	Node *node = queue->head;
	int i = 0;
	while(node != NULL){
		printf("the %dth node: %d\n", i + 1, node->data);
		node = node->next;
		i++;
	}
	printf("disp finished!\n");

	return;
}
