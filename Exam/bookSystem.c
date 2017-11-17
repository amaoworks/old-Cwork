#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<time.h> 
#define Max 100 

struct date{ //租借 &归还日期
	int year; 
	char ch1; 
	int month; 
	char ch2; 
	int day; 
};

struct library{ //音像图书库
	char bianhao[10]; 
	char name[100]; 
	int price; 
	int amount; 
	int shengyu; 
};

struct borrower{ //租借者信息
	char uname[100]; 
	char bianhao[10]; 
	struct date borrow; 
	int money; 
	struct date back; 
	int rent; 
};

struct tm * lt;

//struct tm *tmp_ptr = NULL;

void build_book();  //创建音像图书库
void borrow_book(); //租借音像图书
void back_book();   //归还音像图书
void buy_book();    //购进音像图书
void scrap_book();  //报废音像图书
void storage_book(); //图书库存储概况
int borrow_day(struct borrower e); //计算租借的天数

int main(void) 
{ 
	char choice;
	time_t t;
	//struct tm * lt;
	time (&t);//获取Unix时间戳。
	lt = localtime (&t);//转为时间结构
	//char op; 
	do{ 
		system("clear"); 
		printf(" \t\t--------------------------------------------\n"); 
		printf(" \t\t|             图书音像管理系统             |\n"); 
		printf(" \t\t|              今天是%d%d%d              |\n",lt->tm_year+1900,lt->tm_mon,lt->tm_mday); 
		printf(" \t\t|------------------------------------------|\n"); 
		printf(" \t\t|   1-- 创建音像图书库                     |\n"); 
		printf(" \t\t|   2-- 租借音像图书                       |\n"); 
		printf(" \t\t|   3-- 归还音像图书                       |\n"); 
		printf(" \t\t|   4-- 购进音像图书                       |\n"); 
		printf(" \t\t|   5-- 报废音像图书                       |\n"); 
		printf(" \t\t|   6-- 音像图书库概况                     |\n"); 
		printf(" \t\t|   7-- 显示音像图书                       |\n"); 
		printf(" \t\t|   0-- 退出系统                           |\n"); 
		printf(" \t\t|------------------------------------------|\n"); 
		printf(" \t\t|   请输入选项编号（ 0-6 ）                |\n"); 
		printf(" \t\t|------------------------------------------|\n"); 
		scanf(" %c",&choice); 
    	switch(choice) { 
		case '1':build_book(); break;
		case '2':borrow_book(lt); break; 
		case '3':back_book(); break; 
		case '4':buy_book(); break; 
		case '5':scrap_book(); break; 
		case '6':storage_book(); break; 
		case '7':display_book(); break; 
		case '0':break; 
		default:printf("\n 没有选项为 %c 的选项！ \n",choice); 
		printf("\n 请输入任意键继续！ "); 
		//op=getchar();
		//op=getchar();
		getchar();
		getchar();
		system("clear"); 
	} 
}
	while(choice!='0'); 
		printf("\n \t\t感谢使用本软件！已正常退出! \n"); 
	return 0; 
} 
//创建音像图书库
void build_book() { 
	char ch[10];
	//char op;
	struct library a; 
	FILE *fp1=NULL; 
	//fflush(stdin); 
	fp1=fopen("Library.txt","a"); 
	if(fp1==NULL) 
		{ 
			printf("\n \t\t文件打开错误！ \n"); 
			exit(0); 
	} 
	printf("\n\t\t 请输入音像图书的编号：(B/V/D_001) "); 
	scanf("%s",a.bianhao); 
	strcpy(ch,a.bianhao); 
	if(ch[0]!='B'&&ch[0]!='V'&&ch[0]!='D') 
	{ 
	printf("\t\t输入格式不正确！ \n"); 
	printf(" 请按任意键重新输入！ "); 
	//op=getchar();
	//op=getchar();
	getchar(); 
	getchar(); 
	build_book(); 
	} 
	printf(" \t\t请输入音像图书的名称： "); 
	scanf("%s",a.name); 
	printf(" \t\t请输入音像图书的价格： "); 
	scanf("%d",&a.price); 
	printf(" \t\t请输入音像图书的数量： "); 
	scanf("%d",&a.amount); 
	a.shengyu = a.amount;
	/*printf(" 请输入音像图书的剩余数量： "); 
	scanf("%d",&a.shengyu); 
	if(a.amount <=a.shengyu ) 
		{ 
			printf(" 原数量不得小于剩余数量！请重新输入！ \n"); 
			printf(" 请输入音像图书的原数量： "); 
			scanf("%d",&a.amount); 
			printf(" 请输入音像图书的剩余数量： "); 
			scanf("%d",&a.shengyu); 
	}*/ 
		fprintf(fp1,"%s\t%s\t%d\t%d\t%d\n",a.bianhao,a.name,a.price,a.amount,a.shengyu); 
		if(fclose(fp1)){ 
		printf(" 不能关闭文件 !\n"); 
		exit(0); 
	} 
	printf("\n\t\t创建音像图书《 %s》成功！ \n",a.name); 
	printf("\n\t\t输入任意键继续！ \n"); 
	//op=getchar();
	//op=getchar(); 
	getchar(); 
	getchar(); 
	system("clear"); 
	} 

//租借音像图书
void borrow_book(struct tm *lt) { 
	struct library a={0},b[Max]={0},*p1=NULL,*p2=NULL; //b 为结构数组
	struct borrower c={0}; 
	char ch[10]={0},op; 
	int n=0,m=0; 
	FILE *fp1; 
	FILE *fp2; 
	//fflush(stdin); 
	if((fp1=fopen("borrow.txt","a"))==NULL){ 
	printf("\t\t文件打开错误 !\n"); 
	exit(0); 
} 
	if((fp2=fopen("Library.txt","r"))==NULL){ 
	printf("\t\t文件打开错误 !\n"); 
	exit(0); 
} 
	printf("\t\t请输入您的姓名： "); 
	scanf("%s",c.uname); 
	printf("\t\t请输入租借的书的编号： "); 
	scanf("%s",c.bianhao); 
	//printf("\t\t请输入租借的日期（年 /月/日）： "); 
	//scanf("%d%c%d%c%d",&c.borrow.year,&c.borrow.ch1 ,&c.borrow.month,&c.borrow.ch2,&c.borrow.day); 
	c.borrow.year=lt->tm_year+1900;
	c.borrow.month=lt->tm_mon;
	c.borrow.day=lt->tm_mday;
	c.borrow.ch1=\
	c.borrow.ch2=\
	strcpy(ch,c.bianhao); 
	fprintf(fp1,"%s\t%s\t%d%c%d%c%d ",c.uname ,c.bianhao,c.borrow.year,c.borrow.ch1,c.borrow.month,c.borrow.ch2,c.borrow.day); 
	p1=b; 
	while(feof(fp2)==0) 
		{ 
			fscanf(fp2,"%s%s%d%d%d",p1->bianhao,p1->name,&p1->price,&p1->amount,&p1->shengyu); 
			p1++; 
			n++; 
	} 
	for(p1=b;p1<b+n;p1++) 
	if(strcmp(c.bianhao,p1->bianhao)==0) 
		{ 
			p2=p1; 
			m=1; 
			break; 
	} 
	if(m==0) 
		{ 
			printf("\t\t无此音像图书！ \n"); 
			printf("\t\t输入任意键继续！ \n"); 
			//op=getchar();
			//op=getchar(); 
			getchar(); 
			getchar(); 
	} 
	else 
	if((strcmp(ch,p2->bianhao)==0)&&(p2->shengyu==0)) 
		{ 
			printf("\n\t\t此音像图书已全部借出！ \n"); 
			printf("\n\t\t输入任意键继续！ \n"); 
			//op=getchar();
			//op=getchar();
			getchar(); 
			getchar(); 
	} 
	else 
	if((strcmp(ch,p2->bianhao)==0)&&(p2->shengyu!=0)) 
		{ 
			printf("\t\t应交的押金额为 %d 元！ ",(p2->price)*3); 
			c.money=(p2->price)*3; 
			p2->shengyu=p2->shengyu-1; 
			fprintf(fp1,"%d\n",c.money); 
			fclose(fp1); 
			fclose(fp2); 
	printf("\n\t\t输入任意键继续！ \n"); 
	//op=getchar();
	//op=getchar(); 
	getchar(); 
	getchar(); 
} 
	if((fp2=fopen("Library.txt","w"))==NULL){ 
		printf("\t\t文件打开错误 !\n"); 
		exit(0); 
} 
	for(p1=b;p1<b+n;p1++) 
		fprintf(fp2,"%s\t%s\t%d\t%d\t%d\n",p1->bianhao,p1->name,p1->price,p1->amount,p1->shengyu); 
		system("clear"); 
		fclose(fp2); 
} 

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
	printf("\t\t文件打开错误 !\n"); 
	exit(0); 
} 
	if((fp2=fopen("borrow.txt","r"))==NULL){ 
	printf("\t\t文件打开错误 !\n"); 
	exit(0); 
} 
	printf("\t\t请输入您的名字： "); 
	scanf("%s",c.uname); 
	printf("\t\t请输入归还的书的编号 : "); 
	scanf("%s",c.bianhao); 
	printf("\t\t请输入归还的日期（年 /月/日） : "); 
	scanf("%d%c%d%c%d",&c.back.year,&c.back.ch1,&c.back.month,&c.back.ch2,&c.back.day); 
	//时间
	//if(c.back.year<c.borrow.year)
	//	back_book();
		//else if(c.back.month<c.borrow.month)
		//back_book();
		//else if(c.back.day<c.borrow.day)
		//back_book();
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
			printf("\t\t您没有借书记录！ \n"); 
			printf("\t\t输入 y 重新填写资料，输入 n 返回上一菜单！ \n"); 
			scanf(" %c",&op); 
			if(op=='y') 
			back_book(); 
			if(op=='n') 
	{ 
	system("clear"); 
	main() ; 
	} 
} 
	printf("\n\t\t此音像图书名为《 %s》 \n",p2->name); 
	if((fp1=fopen("Library.txt","w"))==NULL){ 
		printf("\t\t文件打开错误！ \n"); 
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
		printf("\t\t一共租借了 %d 天！ \n",day); 
		if(ch[0]=='B') 
			rent=day*0.2; 
		if(ch[0]=='V') 
			rent=day*0.1; 
		if(ch[0]=='D') 
			rent=day*0.3; 
		if(rent>=p3->money) 
			money_1=0; 
		if(rent<p3->money) 
			money_1=p3->money-rent; 
			printf("\t\t已交押金 %d 元，应交租金 %d 元，应退金额 %d 元\n",p4->money,rent,money_1); 
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
				printf("\t\t文件打开错误 !\n"); 
				exit(0); 
		} 
		for(p3=d;p3<d+n1-1;p3++) 
			{ 
				if(strcmp(p4->uname,p3->uname)==0) 
				continue; 
				else 
						fprintf(fp1,"%s %s %d%c%d%c%d %d",p3->uname ,p3->bianhao,p3->borrow.year,p3->borrow.ch1,p3->borrow.month,p3->borrow.ch2,p3->borrow.day,p3->money); 
		} 
		printf("\t\t成功删除 %s 的信息！ \n",p4->uname); 
		printf("\t\t按任意键结束！ "); 
		//op=getchar();
		//op=getchar(); 
		getchar(); 
		getchar(); 
		system("clear"); 
		fclose(fp2); 
} 
//购进音像图书
void buy_book() { 
	struct library a={0},b[Max]={0},*p1=NULL,*p2=NULL; //b 为结构数组
	char ch[10]={0},ch1[100]={0},op; 
	int n=0,m=1,number; 
	FILE *fp1; 
	//fflush(stdin); 
	if((fp1=fopen("Library.txt","r"))==NULL){ 
		printf("\t\t文件打开错误 !\n"); 
		exit(0); 
	} 
	printf("\t\t请输入购进音像图书的编号： "); 
	scanf("%s",a.bianhao); 
	strcpy(ch,a.bianhao); 
	if(ch[0]!='B'&&ch[0]!='V'&&ch[0]!='D') { 
		printf("\t\t输入\n"); 
		printf(" 请按任意键重新输入！ "); 
		//op=getchar();
		//op=getchar(); 
		getchar();
		buy_book(); 
} 
	p1=b; 
	while(feof(fp1)==0) { 
		fscanf(fp1,"%s%s%d%d%d",p1->bianhao,p1->name,&p1->price,&p1->amount,&p1->shengyu); 
		p1++; 
		n++; 
	} 
	fclose(fp1); 
	for(p1=b;p1<b+n;p1++) 
		if(strcmp(a.bianhao,p1->bianhao)==0) { 
			p2=p1; 
			strcpy(ch1,p1->name ); 
			m=0; 
			break; 
	} 
	if(m) { 
		if((fp1=fopen("Library.txt","a"))==NULL){ 
			printf("\t\t文件打开错误 !\n"); 
			exit(0); 
} 
	printf("\t\t请输入要购进音像图书的名称： "); 
	scanf("%s",a.name); 
	printf("\t\t请输入要购进音像图书的原价： "); 
	scanf("%d",&a.price); 
	printf("\t\t请输入要购进音像图书的数量： "); 
	scanf("%d",&a.amount); 
	printf("\t\t购进音像图书《 %s 》成功！ ",a.name ); 
	a.shengyu=a.amount; 
	fprintf(fp1,"%s\t%s\t%d\t%d\t%d\n",a.bianhao,a.name,a.price,a.amount,a.shengyu); 
	fclose(fp1); 
} 
	else 
	{ 
		if((fp1=fopen("Library.txt","w"))==NULL){ 
			printf("\t\t文件打开错误 !\n"); 
			exit(0); 
	} 
		printf("\t\t此书已存在！ \n"); 
		printf("\t\t请输入要购进图书的数量： "); 
		scanf("%d",&number); 
		printf("\t\t购进音像图书《 %s》成功！ ",ch1); 
		p2->amount =p2->amount +number; 
		p2->shengyu=p2->shengyu+number; 
	for(p1=b;p1<b+n;p1++) 
		fprintf(fp1,"%s\t%s\t%d\t%d\t%d\n",p1->bianhao,p1->name,p1->price,p1->amount,p1->shengyu); 
	} 
	printf("\t\t按任意键结束！ "); 
	//op=getchar();
	//op=getchar(); 
	getchar(); 
	getchar(); 
	system("clear"); 
	fclose(fp1); 
} 
//报废音像图书
void scrap_book() { 
	struct library a={0},b[Max]={0},*p1=NULL,*p2=NULL; //b 为结构数组
	char ch[10]={0},op; 
	int n=0,m=1; 
	FILE *fp1; 
	//fflush(stdin); 
	if((fp1=fopen("Library.txt","r"))==NULL){ 
	printf("\t\t文件打开错误 !\n"); 
	exit(0); 
} 
	printf("\t\t请输入要报废的书的编号： "); 
	scanf("%s",a.bianhao ); 
	p1=b; 
	while(feof(fp1)==0) 
		{ 
			fscanf(fp1,"%s%s%d%d%d",p1->bianhao,p1->name,&p1->price,&p1->amount,&p1->shengyu); 
			p1++; 
			n++; 
} 
	for(p1=b;p1<b+n;p1++) 
		if(strcmp(a.bianhao,p1->bianhao)==0) 
			{ 
				p2=p1; 
				m=0; 
		break; 
} 
	fclose(fp1); 
	if(m) 
		printf("\t\t本音像图书库不存在此书！ \n"); 
	else 
		if (p1->amount!=p1->shengyu) 
			printf("\t\t《%s》已被借出，不能报废！ \n",p1->name); 
	else 
		if(p1->amount==p1->shengyu) 
			{ 
				if((fp1=fopen("Library.txt","w"))==NULL) 
		{ 
		printf("\t\t文件打开错误 !\n"); 
		exit(0); 
		} 
	for(p1=b;p1<b+n-1;p1++) 
		if(p1->bianhao ==p2->bianhao) 
			continue; 
		else 
			fprintf(fp1,"%s\t%s\t%d\t%d\t%d\n",p1->bianhao,p1->name,p1->price,p1->amount,p1->shengyu); 
			printf("\t\t《%s》已成功报废！ \n",p2->name); 
			fclose(fp1); 
	} 
	printf("\t\t按任意键结束！ "); 
   // op=getchar();
   // op=getchar(); 
    getchar(); 
    getchar(); 
	system("clear"); 
}
//显示音像图书信息
void display_book(){
	struct library a={0},b[Max]={0},*p1=NULL; //b 为结构数组
	char ch[10],op; 
	int n=0,X,Y,Z,x,y,z; 
	FILE *fp1; 
	X=Y=Z=x=y=z=0; 
	p1=b; 
	if((fp1=fopen("Library.txt","r"))==NULL){ 
		printf("\t\t文件打开错误 !\n"); 
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
				printf("\t\t图书编号：%s书名：《%s》租金：%d可借数量：%d\n",p1->bianhao,p1->name,p1->price*3,p1->shengyu);
			} 
			if(ch[0]=='V') 
			{ 
				printf("\t\tVCD编号：%s书名：《%s》租金：%d可借数量：%d\n",p1->bianhao,p1->name,p1->price*3,p1->shengyu);
				} 
			if(ch[0]=='D') 
			{
				printf("\t\tDVD编号：%s书名：《%s》租金：%d可借数量：%d\n",p1->bianhao,p1->name,p1->price*3,p1->shengyu);
				} 
	} 
	printf("\t\t按任意键结束！ "); 
	getchar();
	getchar();
	system("clear"); 
	fclose(fp1); 

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
		printf("\t\t文件打开错误 !\n"); 
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
	if(ch[0]=='D') 
	{ 
		Z=Z+p1->amount; 
		z=z+p1->amount-p1->shengyu; 
	} 
} 
	printf(" 本图书库一共有图书 %d 本，其中被借 %d 本； \n 本图书库一共有 VCD %d 个，其中被借 %d 个； \n 本图书库一共有DVD %d 卷，其中被借 %d 卷！ \n",X,x,Y ,y,Z,z); 
	printf(" 按任意键结束！ "); 
	//op=getchar(); 
	getchar();
	getchar();
	//scanf("%c",&op);
	system("clear"); 
	fclose(fp1); 
} 
