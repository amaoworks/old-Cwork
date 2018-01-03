/*************************************************************************
    > File Name: Exp43.c
    > Author: Yiyao Mao
    > Mail: amaoworks@gmail.com 
    > Created Time: 2017年12月24日 星期日 18时06分44秒
 ************************************************************************/

#include <stdio.h>
#define N 20
#define TRUE 1
#define INF 32766
#define INFIN 32767 

typedef struct{
	int vexnum,arcnum;
	char vexs[N];
	int arcs[N][N];
}MGraph;
void printPath(MGraph g, int startVex, int EndVex, int path[][N]);
void createMGraph_w(MGraph *g, int flag);
void prim(MGraph *g, int u);
void dijkstra(MGraph g, int v);
void createMGraph_w(MGraph *g, int flag){
	int i,j,w;
	char v;
	g->vexnum=0;
	g->arcnum=0;
	i=0;
	printf("\n 输入顶点序列 (以 #结束 ): \n");
	while((v=getchar())!='#'){
		g->vexs[i]=v;
		i++;
	}
	g->vexnum=i;
	for(i=0; i<6; i++)
	for(j=0; j<6; j++)
	g->arcs[i][j]=INF;
	printf("\n 输入边的信息:(顶点,顶点,权值),以 (-1,-1,-1) 结束 \n");
	scanf("%d,%d,%d",&i,&j,&w);
	while(i!=-1){
		g->arcs[i][j]=w;
		if(flag==1)
			g->arcs[j][i]=w;
			scanf("%d,%d,%d",&i,&j,&w);
		}
}

void prim(MGraph *g, int u){
	int lowcost[N],closest[N],i,j,k,min;
	for(i=0; i<g->vexnum; i++){
		lowcost[i]=g->arcs[u][i];
		closest[i]=u;
		}
	lowcost[u]=0;
	printf("\n 最小生成树: \n");
	for(i=1; i<g->vexnum; i++){
		min=INFIN;
		for(j=0; j<g->vexnum; j++)
			if(lowcost[j]!=0&&lowcost[j]<min){
				min=lowcost[j];
				k=j;
				}
			printf("(%c,%c)--%d\n",g->vexs[closest[k]],g->vexs[k],lowcost[k]); 
			lowcost[k]=0;
			for(j=0; j<g->vexnum; j++) 
				if(g->arcs[k][j]!=0&&g->arcs[k][j]<lowcost[j]){
					lowcost[j]=g->arcs[k][j];
					closest[j]=k;
				}
		}
}

void printPath(MGraph g, int startVex, int EndVex, int path[][N]){
	int stack[N],top=0;
	int i,k,j;
	int flag[N];
	k=EndVex;
	for (i=0;i<g.vexnum;i++) flag[i]=0;
	j=startVex;
	printf("%c",g.vexs[j]);
	flag[j]=1;
	stack[top++]=k;
	while(top>0){
		for (i=0;i<g.vexnum;i++){
			if (path[k][i]==1 && flag[i]==0 ){
				if (g.arcs[j][i]!=INF ){
					printf("-> %c(%d) ",g.vexs[i],g.arcs[j][i]);
					flag[i]=1;
					j=i;
					k=stack[--top];
					break;
					}
				else
					if (i!=k) stack[top++]=i;
				}
			}
		}
	if (flag[k]==0) printf("-> %c(%d)",g.vexs[k],g.arcs[j][k]);
}

void dijkstra(MGraph g, int v){
	int s[N], path[N][N],dist[N];
	int mindis,i,j,u,k;
	for(i=0; i<g.vexnum; i++){
	dist[i]=g.arcs[v][i];
	s[i]=0;
	for(j=0; j<g.vexnum; j++)
		path[i][j]=0;
		if(dist[i]<INF){
			path[i][v]=1;
			path[i][i]=1;
		}
	}
	dist[v]=0;
	s[v]=1;
	for(i=0,u=1; i<g.vexnum; i++){
		mindis=INFIN;
	for(j=0; j<g.vexnum; j++)
		if(s[j]==0)
			if(dist[j]<mindis){
				u=j;
				mindis=dist[j];
			}
	s[u]=1;
	for(j=0; j<g.vexnum; j++)
		if((s[j]==0)&&dist[u]+g.arcs[u][j]<dist[j]){
			dist[j]=dist[u]+g.arcs[u][j];
		for(k=0; k<g.vexnum; k++)
			path[j][k]=path[u][k];
			path[j][j]=1;
		}
	}
	printf("\n 顶点 %c->到各顶点的最短路径\n",g.vexs[v]);
	for (i=0;i<g.vexnum;i++){
		if(i==v)continue;
			printf("\n 顶点 %c-> 顶点 %c: ",g.vexs[v],g.vexs[i]);
		if (dist[i]==INF||dist[i]==0)
			printf(" 无路径 ");
		else {
			printf("%d",dist[i]);
		printf(" 经过顶点: ");
		printPath(g,v,i,path);
		}
	}
}

int main(int argc ,char **argv){
	int select;
	MGraph ga;
	do {
		printf("\n***************MENU******************\n");
		printf(" 1. 图的最小生成树 -Prim 算法 \n");
		printf(" 2. 图的单源最短路径-dijstra 算法 \n");
		printf(" 0. EXIT");
		printf("\n***************MENU******************\n");
		printf("\ninput choice:");
		scanf("%d",&select);
		getchar();
		switch(select){
			case 1:
				printf("\n1- 图的最小生成树 -Prim 算法 \n");
				printf("\n 输入带权图的基本信息:\n");
				createMGraph_w(&ga,1);
				prim(&ga,0);
				break;
			case 2:
				printf("\n2- 图的单源最短路径-dijstra 算法 \n");
				printf("\n 输入带权图的基本信息:\n");
				createMGraph_w(&ga,0);
				dijkstra(ga,0);
				break;
			default:
				break;
			}
		}while(select);
		return 0;
}
