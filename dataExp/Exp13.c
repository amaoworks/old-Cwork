/*************************************************************************
    > File Name: Exp13.c
    > Author: Lucio
    > Mail: amaoworks@gmail.com 
    > Created Time: 2017年12月24日 星期日 12时58分21秒
 ************************************************************************/

#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1

typedef int ElemType;	//定义表元素的类型

typedef struct LNode{	//线性表的单链表储存
	ElemType data;
	struct LNode *next;
} LNode, *LinkList;

LinkList CreateList(int n);		//
void PrintList(LinkList L);		//输出带头结点单链表的所有元素
int GetElem(LinkList L ,int i ,ElemType *e);	//

LinkList CreateList(int n){
	LNode *p , *q , *head;
	int i;
	head = (LinkList)malloc(sizeof(LNode));
	head->next=NULL;
	p = head;
	for(i = 0 ;i < n ;i++){
		q = (LinkList)malloc(sizeof(LNode));
		printf("input data %i:", i+1);
		scanf("%d", &q->data);	//输入元素值
		q->next = NULL;			//结点指针域置空
		p->next = q;
		p = q;
	}
	return head;
}

void PrintList(LinkList L){
	LNode *p;
	p = L->next;				//*p指向单链表的第一个元素
	while(p!=NULL){
		printf("%5d", p->data);
		p = p->next;
	}
}

int GetElem(LinkList L ,int i ,ElemType *e){
	LNode *p;
	int j = 1;
	p = L->next;
	while(p&&j<i){
		p = p->next;
		j++;
	}
	if(!p||j>i)
		return ERROR;
	*e = p->data;
	return OK;
}

int main(int argc ,char **argv){
	int i , n;
	ElemType e;
	LinkList L = NULL;			//定义指向单链表的指针
	printf("Please input n:");	//输入单链表的元素个数
	scanf("%d",&n);
	if(n>0){
		printf("\n1-Create LinkList:\n");
		L = CreateList(n);
		printf("\n2-Print LinkList:\n");
		PrintList(L);
		printf("\n3-GetElem from LinkList:\n");
		printf("input i=");
		scanf("%d",&i);
		if(GetElem(L , i , &e))
			printf("NO%d is %d\n", i , e);
		else
			printf("not exists\n");
	}else
		printf("ERROR\n");
	return 0;
}
