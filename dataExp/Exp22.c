/*************************************************************************
    > File Name: Exp22.c
    > Author: Yiyao Mao
    > Mail: amaoworks@gmail.com 
    > Created Time: 2018年01月03日 星期三 00时41分45秒
 ************************************************************************/

#include<stdio.h>
typedef  int ElemType; /*定义元素的类型*/
typedef struct{
    ElemType *base;
    ElemType *top;
    int stacksize;     /*当前已分配的存储空间*/
}SqStack;

void conveshen(SqStack *S){
	ElemType n,h;
	int m=0,k=0;
	InitStack(S);
	printf("Input element\n");
	scanf("%d",&n);
	while(n){
		m++;
		Push(S,n%2);
		n=n/2;
	}
	while(k<m){
		k++;
		Pop(S,&h);
		printf("%d",h);
	}
}

int main(int argc ,char **argv){
	SqStack S;
	conveshen(&S);
	printf("\n");
}
