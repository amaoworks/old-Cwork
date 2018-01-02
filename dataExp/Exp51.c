/*************************************************************************
    > File Name: Exp51.c
    > Author: Yiyao Mao
    > Mail: amaoworks@gmail.com 
    > Created Time: 2017年12月24日 星期日 18时18分35秒
 ************************************************************************/

#include<stdio.h>
#define N 100

typedef struct {
	int data[N];
	int length;
} SSTable;

int zbcz(SSTable s, int k ,int *p){
	int n = 0;
	int low , high , mid;
	low = 1;
	high = s.length;
	while(low<=high){
		n++;
		mid = (low + high) / 2;
		if(s.data[mid]==k){
			*p = n;
			return mid;
		}
		else if(s.data[mid]>k){
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	*p = n;
	return 0;
}

void show_zb(SSTable s, int k, int *p){
	int n;
	p = &n;
	if(zbcz(s,k,p)){
		printf("查找%d 成功\n",k);
		printf("查找%d 的比较次数为: %d\n",k , n);
	}
	else{
		printf("查找%d失败\n",k);
		printf("查找%d的比较次数为:%d\n",k,n);
	}
}

int sxcz(SSTable s ,int k ,int *p){
	int n = 1;
	int i;
	for(i = s.length;s.data[i]!=k&&i>0;i--)
		n++;
	*p=n;
	return i;
}

void show_sx(SSTable s, int k, int *p){
	int n;
	p=&n;
	if(sxcz(s,k,p)){
		printf("查找%d成功\n",k);
		printf("查找%d的比较次数为:%d\n",k,n);
	}
}

void main(){
	SSTable s;
	int i , n , *p;
	int k;
	do{
		printf("数据元素的个数:");
		scanf("%d",&s.length);
		printf("输入10个数据元素:");
		for(i=1;i<s.length;i++)
			scanf("%d",&s.data[i]);
		printf("输入要查找的数:");
		scanf("%d",&k);
		printf("\n---String---\n");
		printf("1.折半查找\n");
		printf("2.顺序查找\n");
		printf("0.EXIT\n");
		printf("\nInput choice:");
		scanf("%d",&n);

		switch(n){
			case 1:show_zb(s,k,p);break;
			case 2:show_sx(s,k,p);break;
			default:n = 0;break;
		}
	}while(n);
}
