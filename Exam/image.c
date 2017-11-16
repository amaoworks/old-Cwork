#include "image.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//主显示菜单
void showMain(){
	/*system("clear");
	char chioce;
	do{ */
		printf(" \t\t--------------------------------------------\n"); 
		printf(" \t\t|             图书音像管理系统             |\n"); 
		printf(" \t\t|------------------------------------------|\n"); 
		printf(" \t\t|   1-- 创建音像图书库                     |\n"); 
		printf(" \t\t|   2-- 租借音像图书                       |\n"); 
		printf(" \t\t|   3-- 归还音像图书                       |\n"); 
		printf(" \t\t|   4-- 购进音像图书                       |\n"); 
		printf(" \t\t|   5-- 报废音像图书库                     |\n"); 
		printf(" \t\t|   6-- 音像图书库概况                     |\n"); 
		printf(" \t\t|   0-- 退出系统                           |\n"); 
		printf(" \t\t|------------------------------------------|\n"); 
		printf(" \t\t|   请输入选项编号（ 0-6 ）                |\n"); 
		printf(" \t\t|------------------------------------------|\n"); 
		/*scanf(" %c",&choice);
		switch(choice){
			case '1' :
			default:printf("\n\t\t\033[40;31m本程序没有 %c 的选项，请检查后重试！\033[0m\n",choice);
			getchar();
			getchar();
			//system("clear");
		}
	}
	while(choice!='0');
		printf("\t\t程序即将退出，欢迎下次再次使用！");*/
	return ;
}

//创建音像图书文件
void buildBook(Library *part){
	char ch[20];
	//Library *part;
	FILE *fp1 = NULL;
	fp1 = fopen("Library.txt","a");
	if(fp1==NULL){
		printf("\t\t文件打开错误！\n");
		exit(0);
	} 
	printf("\n\t\t 请输入音像图书编号(格式如B/V/D_001)：");
	scanf("%s",part->bookId);
	//printf("%s",part->bookId);
	strcpy(ch,part->bookId);
	if(ch[0]!='B'&&ch[0]!='D'&&ch[0]!='V'){
		printf("\n\t\t 输入的编号不符合要求！");
		printf("\n\t\t 按任意键重新输入！");
		getchar();
		getchar();
		buildBook;
	}
	printf("\n\t\t 请输入音像图书的名称： ");
	scanf("%s",&part->bookName);
	printf("\n\t\t 请输入音像图书的价格： ");
	scanf("%f",&part->bookPrice);
	printf("\n\t\t 请输入音像图书的数量： ");
	scanf("%d",&part->bookNum);
	(part->bookRent) = (part->bookNum);
	fprintf(fp1,"%s\t%s\t%f\t%d\t%d\n",part->bookId,part->bookName,part->bookPrice,part->bookNum,part->bookRent);
	if(fclose(fp1)){
		printf("\n\t\t 不能关闭文件！\n");
		exit(0);
	}
	printf("\n\t\t 成功创建音像图书《 %s 》 \n",part->bookName);
	printf("\n\t\t 按任意键继续！ \n");
	getchar();
	getchar();
	system("clear");
}

//报废图书
void killBook(){
	Library a={0},b[Max]={0},*p1=NULL,*p2=NULL; //b 为结构数组
	char ch[10]={0};
	int n = 0 , m = 1 ;
	FILE *fp1;
	if((fp1=fopen("Library.txt","r"))==NULL){ 
	printf(" 文件打开错误 !\n"); 
	exit(0); 
	}
	printf(" 请输入要报废的书的编号： "); 
	scanf("%s",a.bookId); 
	p1=b; 
	while(feof(fp1)==0) { 
		fscanf(fp1,"%s%s%f%d%d",p1->bookId,p1->bookName,&p1->bookPrice,&p1->bookNum,&p1->bookRent); 
		p1++;
		n++;
		}
	for(p1=b;p1<b+n;p1++) 
		if(strcmp(a.bookId,p1->bookId)==0) 
			{ 
				p2=p1;
				m=0;
				break;
		}
	fclose(fp1); 
	if(m) 
		printf(" 本音像图书库不存在此书！ \n"); 
	else 
		if (p1->bookNum!=p1->bookRent) 
			printf(" 《%s》已被借出，不能报废！ \n",p1->bookName); 
	else 
		if(p1->bookNum==p1->bookRent) 
			{ 
				if((fp1=fopen("Library.txt","w"))==NULL) { 
				printf(" 文件打开错误 !\n"); 
				exit(0); 
				} 
				for(p1=b;p1<b+n-1;p1++) 
					if(p1->bookId==p2->bookId) 
						continue; 
					else 
						fprintf(fp1,"%s\t%s\t%f\t%d\t%d\n",p1->bookId,p1->bookName,p1->bookPrice,p1->bookNum,p1->bookRent); 
						printf(" 《%s》已成功报废！ \n",p2->bookName); 
						fclose(fp1); 
			} 
			printf(" 按任意键结束！ ");
			getchar();
			getchar();
			system("clear");
}		

//增加音像图书
void addBook() { 
	Library a={0},b[Max]={0},*p1=NULL,*p2=NULL; //b 为结构数组
	char ch[10]={0}, ch1[100]={0}; 
	int n=0,m=1,number; 
	FILE *fp1; 
	if((fp1=fopen("Library.txt","r"))==NULL){ 
		printf(" 文件打开错误 !\n"); 
		exit(0); 
		} 
	printf(" 请输入购进音像图书的编号： "); 
	scanf("%s",a.bookId); 
	strcpy(ch,a.bookId); 
	if(ch[0]!='B'&&ch[0]!='V'&&ch[0]!='D') { 
		printf(" 非法输入！ \n"); 
		printf(" 请按任意键重新输入！ "); 
		getchar();
		getchar();
		addBook(); 
		}
	p1=b; 
	while(feof(fp1)==0) { 
		fscanf(fp1,"%s%s%f%d%d",p1->bookId,p1->bookName,&p1->bookPrice,&p1->bookNum,&p1->bookRent); 
		p1++; 
		n++; 
		} 
	fclose(fp1); 
	for(p1=b;p1<b+n;p1++) 
		if(strcmp(a.bookId,p1->bookId)==0) { 
			p2=p1; 
			strcpy(ch1,p1->bookName ); 
			m=0; 
			break; 
		} 
		if(m) { 
			if((fp1=fopen("Library.txt","a"))==NULL){ 
				printf(" 文件打开错误 !\n"); 
				exit(0); 
			} 
	printf(" 请输入要购进音像图书的名称： "); 
	scanf("%s",a.bookName); 
	printf(" 请输入要购进音像图书的原价： "); 
	scanf("%f",&a.bookPrice); 
	printf(" 请输入要购进音像图书的数量： "); 
	scanf("%d",&a.bookNum); 
	printf(" 购进音像图书《 %s》成功！ ",a.bookName ); 
	a.bookRent=a.bookNum; 
	fprintf(fp1,"%s\t%s\t%f\t%d\t%d\n",a.bookId,a.bookName,a.bookPrice,a.bookNum,a.bookRent); 
	fclose(fp1); 
} 
	else 
	{ 
		if((fp1=fopen("Library.txt","w"))==NULL){ 
			printf(" 文件打开错误 !\n"); 
			exit(0); 
		} 
		printf(" 此书已存在！ \n"); 
		printf(" 请输入要购进图书的数量： "); 
		scanf("%d",&number); 
		printf(" 购进音像图书《 %s》成功！ ",ch1); 
		p2->bookNum =p2->bookNum +number; 
		p2->bookRent=p2->bookRent+number; 
		for(p1=b;p1<b+n;p1++) 
			fprintf(fp1,"%s\t%s\t%f\t%d\t%d\n",p1->bookId,p1->bookName,p1->bookPrice,p1->bookNum,p1->bookRent); 
	} 
	printf(" 按任意键结束！ "); 
	getchar(); 
	getchar(); 
	system("clear"); 
	fclose(fp1); 
} 	





