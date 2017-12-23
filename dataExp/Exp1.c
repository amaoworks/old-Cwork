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

int InitList_sq(Sqlist *L);		//初始化顺序表
int CreatList_sq(Sqlist *L, int n);		//创建顺序表并手动分配元素
int ListInsert_sq(Sqlist *L, int i, ElemType e);//插入指定元素到顺序表指定位置
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
		printf("input data %d:", i+1);
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

int ListInsert_sq(Sqlist *L, int i, ElemType e){
	int k;
	if(i<1 || i>L->length+1)
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

int ListDelete_sq(Sqlist *L, int i){
	int *p , *q;
	if(i<1 || i>L->length)
		return ERROR;
	p = L->slist + i - 1;
	q = L->slist + L->length - 1;
	for( ; p <= q ; p++)
		*p = *(p+1);
	L->length--;
	return OK;
}

int ListLocate(Sqlist *L, ElemType e){
	int n = 0;
	int *p = L->slist;

	for(int i = 0 ; i<L->length ; i++ , p++)
		if(*p == e)
			{printf("Find data:%d and location is %d\n", e, i+1);
			 n = 1;}

	if(n == 0)
		printf("Can't find data:%d's element\n", e);
}

int main(int argc, char **argv){
	Sqlist sl;
	int n , m , k;

	printf("please input n:");
	scanf("%d",&n);
	if(n>0){
		printf("\n1-Create Sqlist:\n");
		InitList_sq(&sl);
		CreatList_sq(&sl, n);
		printf("\n2-Print Sqlist:\n");
		PrintList_sq(&sl);
		printf("\nplease input insert location and data:(location,data)\n");
		scanf("%d,%d",&m,&k);
		ListInsert_sq(&sl , m , k);
		printf("\n3-Print Sqlist:\n");
		PrintList_sq(&sl);
		printf("\n");
		
		//Here's the test part
		printf("Attention! Test part!\n");
		ElemType e , i;
		printf("4-Please input the data you want to find:\n");
		scanf("%d",&e);
		ListLocate(&sl , e);
		printf("\n5-Please input the location where the data you want to delete:\n");
		scanf("%d",&i);
		ListDelete_sq(&sl , i);
		printf("\n6-Print Sqlist:\n");
		PrintList_sq(&sl);
		printf("\n");
	}
	else
		printf("ERROR");
	return 0;
}
