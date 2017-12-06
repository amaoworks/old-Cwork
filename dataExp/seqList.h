#ifndef seqList_h
#define seqList_h

#include <stdio.h>
#include <stdlib.h>
#define initSize 30

typedef int DataType;

typedef struct _seq{
	DataType *arr;
	int arrSize;
	int maxSize;
} SeqList;

void initList(SeqList *List );	//初始化顺序表
void creatList(SeqList *List );	//创建函数
void insertList(SeqList *List ,DataType data ,int local );	//插入函数
void searchList(SeqList *List ,DataType data );		//查找函数
void deleteList(SeqList *List ,DataType data ,int local );	//删除函数
void displayList(SeqList *List);	//显示函数

#endif 
