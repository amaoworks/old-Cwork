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

//租借音像图书
//void borrowBook(Member *c) { 
void borrowBook() { 
	Library a={0},b[Max]={0},*p1=NULL,*p2=NULL; //b 为结构数组
	Member c ={0}; 
	char ch[10]={0}; 
	int n=0,m=0; 
	FILE *fp1; 
	FILE *fp2; 
	if((fp1=fopen("borrow.txt","a"))==NULL){ 
	printf(" 文件打开错误 !\n"); 
	exit(0); 
} 
	if((fp2=fopen("Library.txt","r"))==NULL){ 
	printf(" 文件打开错误 !\n"); 
	exit(0); 
} 
	printf(" 请输入您的姓名： "); 
	scanf("%s",c.memberName); 
	printf(" 请输入租借的书的编号： "); 
	scanf("%s",c.memberId); 
	printf(" 请输入租借的日期（年 /月/日）： "); 
	//scanf("%d%c%d%c%d",&c.borrow.year,&c.borrow.ch1 ,&c.borrow.month,&c.borrow.ch2,&c.borrow.day); 
	scanf("%d%c%d%c%d",c.borrow.year,c.borrow.ch1 ,c.borrow.month,c.borrow.ch2,c.borrow.day); 
	//scanf("%d%c%d%c%d",c->borrow->year,c->borrow->ch1 ,&c.borrow.month,&c.borrow.ch2,&c.borrow.day); 
	strcpy(ch,c.memberId); 
	fprintf(fp1,"%s\t%s\t%d%c%d%c%d ",c.memberName,c.memberId,c.borrow.year,c.borrow.ch1,c.borrow.month,c.borrow.ch2,c.borrow.day); 
	p1=b; 
	while(feof(fp2)==0) 
		{ 
			fscanf(fp2,"%s%s%f%d%d",p1->bookId,p1->bookName,&p1->bookPrice,&p1->bookNum,&p1->bookRent); 
			p1++; 
			n++; 
	} 
	for(p1=b;p1<b+n;p1++) 
	if(strcmp(c.memberId,p1->bookId)==0) 
		{ 
			p2=p1; 
			m=1; 
			break; 
	} 
	if(m==0) 
		{ 
			printf(" 无此音像图书！ \n"); 
			printf(" 输入任意键继续！ \n");  
			getchar(); 
			getchar(); 
	} 
	else 
	if((strcmp(ch,p2->bookId==0)&&(p2->bookRent==0)))
		{ 
			printf("\n 此音像图书已全部借出！ \n"); 
			printf(" 输入任意键继续！ \n"); 
			getchar(); 
			getchar(); 
	} 
	else 
	if((strcmp(ch,p2->bookId)==0)&&(p2->bookRent!=0)) 
		{ 
			printf(" 应交的押金额为 %f 元！ ",(p2->bookPrice)*3); 
			c.rent=(p2->bookPrice)*3; 
			p2->bookRent=p2->bookRent-1; 
			fprintf(fp1,"%f\n",c.rent); 
			fclose(fp1); 
			fclose(fp2); 
	printf("\n 输入任意键继续！ \n");  
	getchar(); 
	getchar(); 
} 
	if((fp2=fopen("Library.txt","w"))==NULL){ 
		printf(" 文件打开错误 !\n"); 
		exit(0); 
} 
	for(p1=b;p1<b+n;p1++) 
		fprintf(fp2,"%s\t%s\t%f\t%d\t%d\n",p1->bookId,p1->bookName,p1->bookPrice,p1->bookNum,p1->bookRent); 
		system("clear"); 
		fclose(fp2); 
}
/*
//归还音像图书
void back_book() { 
	struct library a={0},b[Max]={0},*p1=NULL,*p2=NULL; //b 为结构数组
	struct borrower c={0},d[Max]={0},*p3=NULL,*p4=NULL; 
	char ch[10]={0},ch1[100],op; 
	int day,n1=0,n2=0,m=0,rent,money_1; 
	int x,i; 
	int month_day[2][13]={ 
		{0,31,28,31,30,31,30,31,31,30,31,30,31}, 
		{0,31,29,31,30,31,30,31,31,30,31,30,31} 
		}; 
	FILE *fp1; 
	FILE *fp2; 
	//fflush(stdin); 
	if((fp1=fopen("Library.txt","r"))==NULL){ 
	printf(" 文件打开错误 !\n"); 
	exit(0); 
} 
	if((fp2=fopen("borrow.txt","r"))==NULL){ 
	printf(" 文件打开错误 !\n"); 
	exit(0); 
} 
	printf(" 请输入您的名字： "); 
	scanf("%s",c.uname); 
	printf(" 请输入归还的书的编号 : "); 
	scanf("%s",c.bianhao); 
	printf(" 请输入归还的日期（年 /月/日） : "); 
	scanf("%d%c%d%c%d",&c.back.year,&c.back.ch1,&c.back.month,&c.back.ch2,&c.back.day); 
	strcpy(ch,c.bianhao); 
	strcpy(ch1,c.uname); 
	//在文件中寻找被借的书
	p1=b; 
	p3=d; 
	while(feof(fp1)==0) 
		{ 
			fscanf(fp1,"%s%s%d%d%d",p1->bianhao,p1->name,&p1->price,&p1->amount,&p1->shengyu); 
			p1++; 
			n1++; 
			} 
		while(feof(fp2)==0) 
			{ 
				fscanf(fp2,"%s%s%d%c%d%c%d%d",p3->uname ,p3->bianhao,&p3->borrow.year,&p3->borrow.ch1,&p3->borrow.month,&p3->borrow.ch2,&p3->borrow.day,&p3->money); 
				p3++; 
				n2++; 
		} 
	for(p1=b;p1<b+n1;p1++) 
	if(strcmp(ch,p1->bianhao)==0) { 
		p2=p1; 
		break; 
} 
	for(p3=d;p3<d+n2;p3++) 
		if(strcmp(ch,p3->bianhao)==0&&strcmp(ch1,p3->uname)==0) 
			{ 
				p4=p3; 
				m=1; 
				break; 
		} 
	//当输入的姓名或者借书的编号错误时
	if(m==0) 
		{ 
			printf(" 您没有借书记录！ \n"); 
			printf(" 输入 y 重新填写资料，输入 n 返回上一菜单！ \n"); 
			scanf(" %c",&op); 
			if(op=='y') 
			back_book(); 
			if(op=='n') 
	{ 
	system("clear"); 
	main() ; 
	} 
} 
	printf("\n 此音像图书名为《 %s》 \n",p2->name); 
	if((fp1=fopen("Library.txt","w"))==NULL){ 
		printf(" 文件打开错误！ \n"); 
		exit(0); 
} 
		p2->shengyu =p2->shengyu+1; 
			for(p1=b;p1<b+n1;p1++) 
				fprintf(fp1,"%s\t%s\t%d\t%d\t%d\n",p1->bianhao ,p1->name,p1->price ,p1->amount ,p1->shengyu ); 
	//计算租借的总天数
	x=(p4->borrow.year%4==0&&p4->borrow.year%100!=0||p4->borrow.year%400==0); 
	if(p4->borrow.year==c.back.year) 
		{ 
			if(p4->borrow.month==c.back.month) 
				day=c.back.day-p4->borrow.day; 
			else 
	{ 
			day=month_day[x][p4->borrow.month]-p4->borrow.day; 
			for(i=p4->borrow.month+1;i<c.back.month;i++) 
					day=day+month_day[x][i]; 
					day=day+c.back.day; 
		} 
} 
		printf(" 一共租借了 %d 天！ \n",day); 
		if(ch[0]=='B') 
			rent=day; 
		if(ch[0]=='V') 
			rent=day*2; 
		if(ch[0]=='R') 
			rent=day*3; 
		if(rent>=p3->money) 
			money_1=0; 
		if(rent<p3->money) 
			money_1=p3->money-rent; 
			printf(" 已交押金 %d 元，应交租金 %d 元，应退金额 %d 元\n",p4->money,rent,money_1); 
			fclose(fp1); 
			fclose(fp2); 
	//删除租借者的信息
			p3=d; 
			n1=0; 
		if((fp2=fopen("borrow.txt","r"))==NULL){ 
			printf(" 文件打开错误 !\n"); 
			exit(0); 
	} 
		while(feof(fp2)==0) 
			{ 
				fscanf(fp2,"%s%s%d%c%d%c%d%d",p3->uname ,p3->bianhao,&p3->borrow.year,&p3->borrow.ch1,&p3->borrow.month,&p3->borrow.ch2,&p3->borrow.day,&p3->money); 
				p3++; 
				n2++; 
		} 
		fclose(fp2); 
		for(p3=d;p3<d+n1;p3++) 
				if(strcmp(ch1,p3->uname)==0) 
					{ 
						p4=p3; 
						break; 
				} 
		if((fp2=fopen("borrow.txt","w"))==NULL) 
			{ 
				printf(" 文件打开错误 !\n"); 
				exit(0); 
		} 
		for(p3=d;p3<d+n1-1;p3++) 
			{ 
				if(strcmp(p4->uname,p3->uname)==0) 
				continue; 
				else 
						fprintf(fp1,"%s %s %d%c%d%c%d %d",p3->uname ,p3->bianhao,p3->borrow.year,p3->borrow.ch1,p3->borrow.month,p3->borrow.ch2,p3->borrow.day,p3->money); 
		} 
		printf(" 成功删除 %s 的信息！ \n",p4->uname); 
		printf(" 按任意键结束！ "); 
		//op=getchar();
		//op=getchar(); 
		getchar(); 
		getchar(); 
		system("clear"); 
		fclose(fp2); 
} 

//图书库存储概况
void storage_book() { 
	struct library a={0},b[Max]={0},*p1=NULL; //b 为结构数组
	char ch[10],op; 
	int n=0,X,Y,Z,x,y,z; 
	FILE *fp1; 
	//fflush(stdin); 
	X=Y=Z=x=y=z=0; 
	p1=b; 
	if((fp1=fopen("Library.txt","r"))==NULL){ 
		printf(" 文件打开错误 !\n"); 
		exit(0); 
	} 
	while(feof(fp1)==0) 
		{ 
			fscanf(fp1,"%s%s%d%d%d",p1->bianhao,p1->name,&p1->price,&p1->amount,&p1->shengyu); 
			p1++; 
			n++; 
	} 
	for(p1=b;p1<b+n;p1++) 
		{ 
			strcpy(ch,p1->bianhao); 
			if(ch[0]=='B') 
			{ 
				X=X+p1->amount; 
				x=x+p1->amount-p1->shengyu; 
	} 
	if(ch[0]=='V') 
	{ 
		Y=Y+p1->amount; 
		y=y+p1->amount-p1->shengyu; 
} 
	if(ch[0]=='R') 
	{ 
		Z=Z+p1->amount; 
		z=z+p1->amount-p1->shengyu; 
	} 
} 
	printf(" 本图书库一共有图书 %d 本，其中被借 %d 本； \n 本图书库一共有 VCD %d 个，其中被借 %d 个； \n 本图书库一共有录像带 %d 卷，其中被借 %d 卷！ \n",X,x,Y ,y,Z,z); 
	printf(" 按任意键结束！ "); 
	//op=getchar(); 
	getchar();
	getchar();
	//scanf("%c",&op);
	system("clear"); 
	fclose(fp1); 
} 	




*/
