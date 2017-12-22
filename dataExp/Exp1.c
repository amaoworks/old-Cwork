/*************************************************************************
    > File Name: Exp1.c
    > Author: Lucio
    > Mail: amaoworks@gmail.com 
    > Created Time: 2017年12月22日 星期五 16时12分38秒
 ************************************************************************/

#include<stdio.h>
#include<malloc.h>

#define ERROR 0
#define OK 1
#define INIT_SIZE 5		//初始分配的顺序表长度
#define INCREM 5		//溢出时，顺序表长度的增量

typedef int ElemType;	//定义表元素的类型
typedef struct Sqlist{
	ElemType *slist;	//储存空间的基地址
	int length;			//顺序表的当前长度
	int listsize;		//当前分配的储存空间
} Sqlist;

int InitList_sq(Sqlist *L);		//
int CreatList_sq(Sqlist *L, int n);		//
int ListInsert_sq(Sqlist *L, int i, ElemType e);	//
int PrintList_sq(Sqlist *L);	//输出顺序表的元素
int ListDelete_sq(Sqlist *L, int i);	//删除第i个元素
int ListLocate(Sqlist *L, ElemType e);	//查找值为e的元素

int InitList_sq(Sqlist *L){
	L->slist=(ElemType*)malloc(INIT_SIZE * sizeof(ElemType));
	if(!L->slist) return ERROR ;
	L->length = 0;
	L->listsize = INIT_SIZE;
	return OK;
}

int CreatList_sq(Sqlist *L, int n){
	ElemType e;
	int i;
	for(i=0 ;i<n ;i++){
		printf("input data %d", i+1);
		scanf("%d", &e);
		if(!ListInsert_sq(L,i+1,e))
			return ERROR;
	}
	return OK;
}

int PrintList_sq(Sqlist *L){
	int i;
	for(i=1 ;i<=L->length ;i++)
		printf("%5d",L->slist[i-1]);
	return OK;
}

int ListInsert_sq(Sqlist *L, int ElemType e){
	int k;
	if(i<1 ||i>L->length+1)
		return ERROR;
	if(L->length>=L->listsize){
		L->slist=(ElemType*)realloc(L->slist,(INIT_SIZE+INCREM)*sizeof(ElemType));
		if(!L->slist)
			return ERROR;
		L->listsize+=INCREM;
	}
	for(k=L->length-1;k>=i-1;k--){
		L->slist[k+1]=L->slist[k];
	}
	L->slist[i-1]=e;
	L->length++;
	return OK;
}
