/*************************************************************************
    > File Name: Exp23.c
    > Author: Yiyao Mao
    > Mail: amaoworks@gmail.com 
    > Created Time: 2017年12月24日 星期日 17时45分39秒
 ************************************************************************/

#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define M 20
#define  elemtype  char

typedef struct
{
    elemtype stack[M];
    int top;
} stacknode;

void init(stacknode *st);
void push(stacknode *st,elemtype x);
void pop(stacknode *st);

void init(stacknode *st){
    st->top=0;
}

void push(stacknode *st,elemtype x){
    if(st->top==M)
        printf("the stack is overflow!\n");
    else
    {
        st->top=st->top+1;
        st->stack[st->top]=x;
    }
}

void pop(stacknode *st){
	if(st->top>0)
		st->top--;
    else
		printf("Stack is Empty!\n");
}

int main(int argc ,char **argv){
    char s[M];
    int i;
    stacknode *sp;
    printf("create a empty stack!\n");
    sp=malloc(sizeof(stacknode));
    init(sp);
    printf("input a expression:\n");
    gets(s);
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]=='(')
            push(sp,s[i]);
        if(s[i]==')')
            pop(sp);
    }
    if(sp->top==0)
        printf("'('match')'!\n");
    else
        printf("'('not match')'!\n");
    return 0;
}
