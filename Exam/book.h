#ifndef book_h
#define book_h

#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <time.h> 
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

void build_book();  //创建音像图书库
void borrow_book(); //租借音像图书
void back_book();   //归还音像图书
void buy_book();    //购进音像图书
void scrap_book();  //报废音像图书
void storage_book(); //图书库存储概况
int borrow_day(struct borrower e); //计算租借的天数

#endif
