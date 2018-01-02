/*************************************************************************
    > File Name: Exp42.c
    > Author: Yiyao Mao
    > Mail: amaoworks@gmail.com 
    > Created Time: 2017年12月24日 星期日 18时03分23秒
 ************************************************************************/

#include<stdio.h>
#include<malloc.h>

#define N 20
typedef struct edgenode{  /*图的邻接表：邻接链表结点*/
    int adjvex;  /*顶点序号*/
    struct edgenode *next; /*下一个结点的指针*/
}edgenode;

typedef struct vnode{ /*图的邻接表：邻接表*/
    char data;    /*顶点信息*/
    int ind;      /*顶点入度*/
    struct edgenode *link;  /*指向邻接链表指针*/
}vnode;

void createGraph_list(vnode adjlist[],int *p); /*建立有向图的邻接表*/
void topSort(vnode g[],int n); /*拓扑排序*/

void createGraph_list(vnode adjlist[],int *p){ /*建立有向图的邻接表*/
    int i,j,n,e;
    char v;
    edgenode *s;
    i=0;n=0;e=0;
    printf("输入顶点序列(以#结束)：\n");
    while((v=getchar())!='#')
    {
        adjlist[i].data=v;        /*读入顶点信息*/
        adjlist[i].link=NULL;
        adjlist[i].ind=0;
        i++;
    }
    n=i;
    *p=n;
    /*建立邻接链表*/
    printf("\n请输入弧的信息(i=-1结束)：i,j:\n");
    scanf("%d,%d",&i,&j);
    while(i!=-1){
        s=(struct edgenode*)malloc(sizeof(edgenode));
        s->adjvex=j;
        s->next=adjlist[i].link;
        adjlist[i].link=s;
        adjlist[j].ind++;  /*顶点j的入度加1*/
        e++;
        scanf("%d,%d",&i,&j);
    }
    printf("邻接表:");
    for(i=0;i<n;i++){  /*输出邻接表*/
        printf("\n%c,%d:",adjlist[i].data,adjlist[i].ind);
        s=adjlist[i].link;
        while(s!=NULL){
            printf("->%d",s->adjvex);
            s=s->next;
        }
    }
}

void topSort(vnode g[],int n){

}//{ /*拓扑排序*/
//	int TopoSort(va_list G){
//	Stack S;
//	int indegree[MAX_VERTEX_NUM];
//	int i , count , k;
//	AreNode *p;
//	FindID(G,indegree);
//	InitStack(&s);
//	for(i=0;i<G.vexnum;i++)
//		if(indegree[i]==0) Push(&s,i);
//			count=0;
//	while(!LsEmpty(s)){
//		Pap(&s,&i);
//	}
//}
//}

int main(int argc ,char **argv){
    vnode adjlist[N];
    int n,*p;
    p=&n;
    createGraph_list(adjlist,p);
    return 0;
}
