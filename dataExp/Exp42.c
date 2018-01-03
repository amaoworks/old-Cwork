/*************************************************************************
    > File Name: Exp42.c
    > Author: Yiyao Mao
    > Mail: amaoworks@gmail.com 
    > Created Time: 2017年12月24日 星期日 18时03分23秒
 ************************************************************************/

#include<stdio.h>
#include<malloc.h>
#define N 20

typedef struct EdgeNode{
	int adjvex;
	struct EdgeNode *next;
} EdgeNode;

typedef struct VNode{
	char data; 
	int ind; 
	struct EdgeNode *link;
} VNode;

typedef struct ALgraph{
	int vexnum,arcnum;
	VNode adjlist[N];
}ALGraph;

void createGraph_list(ALGraph *g);
void topSort(ALGraph *g);
void createGraph_list(ALGraph *g){
	int i,j,e;
	char v;
	EdgeNode *s;
	i=0;
	e=0;
	printf("\n 输入顶点序列 (以 #结束 ): \n");
	while((v=getchar())!='#'){
		g->adjlist[i].data=v;
		g->adjlist[i].link=NULL;
		g->adjlist[i].ind=0;
		i++;
	}
	g->vexnum=i;
	printf("\n 请输入弧的信息(顶点序号 ,顶点序号 ),以 (-1,-1) 结束 :\n");
	scanf("%d,%d",&i,&j);
	while(i!=-1) {
		s=(struct EdgeNode*)malloc(sizeof(EdgeNode));
		s->adjvex=j;
		s->next=g->adjlist[i].link;
		g->adjlist[i].link=s;
		g->adjlist[j].ind++;
		e++;
		scanf("%d,%d",&i,&j);
	}
	g->arcnum=e;
}

void topSort(ALGraph *g) {
	int i,j,k,top=0,m=0,s[N];
	EdgeNode *p;
	for(i=0; i<g->vexnum; i++)
		if(g->adjlist[i].ind==0)
			s[top++]=i;
	printf("\n 输出拓扑序列:");
	while(top>0) {
		j=s[--top];
		printf("%c",g->adjlist[j].data);
		m++;
		p=g->adjlist[j].link;
		while(p!=NULL) {
			k=p->adjvex;
			g->adjlist[k].ind--;
			if(g->adjlist[k].ind==0)
				s[top++]=k;
			p=p->next;
		}
	}
	printf("\n 共输出 %d 个顶点 \n",m);
	if(m<g->vexnum)
		printf(" 图中有环! ");
	else
		printf(" 图中无环! ");
}

int main(int argc ,char **argv){
	ALGraph g;
	int i;
	EdgeNode *s;
	printf("**********************\n");
	printf("\n1- 输入图的基本信息:\n");
	createGraph_list(&g);
	printf("\n2- 图的邻接表 :");
	for(i=0; i<g.vexnum; i++) {
		printf("\n%c,%d:",g.adjlist[i].data,g.adjlist[i].ind);
		s=g.adjlist[i].link;
		while(s!=NULL) {
			printf("->%d",s->adjvex);
			s=s->next;
		}
	}
	printf("\n");
	printf("\n3- 根据图的邻接表实现拓扑排序:\n");
	topSort(&g);
	return 0;
}
