#ifndef unit_h
#define unit_h

#include "iostream"
#include "string"
#include "fstream"
#include "conio.h"    //getch()
#include "algorithm"  //sort()
using namespace std;

#define Max_BookNum 10240    //最大存书数目
#define Max_MemberNum 10240  //最大会员数目

typedef enum{        //图书借阅状况
	Borrowed = 1 ,   //已被借阅
	available = 0    //当前可借
} Book_Status ;

typedef struct{        //图书信息
	char name[20] ;    //书名
	char author[20] ;  //图书编号
	string isbn ;      //价格
	string price ;     //出版社
	string pub ;       //出版时间
	string pubtime ;   //收录时间
	string addtime ;   //收录日期
	string Class ;     //分类号
	Book_Status Book_sta ;  //借阅状态，初始化为可借
} Book_Message ;

typedef struct{        //借阅人信息
	string name ;      //姓名
	string sex ;       //性别
	string number ;    //学号
	char login[20] ;   //登陆号码 以A1001开始
	char code[20] ;    //登陆密码
	Book_Message Borrow_Book[10] ;   //最大可借书本数目：10本
	int BorBook_Cnt ;  //借书数量
} Member_Message ;

void Show_WelMenu() ;   //Welcome菜单
void BookInfoInput() ;  //图书信息录入
void Book_InfoShow(Book_Message *Book_Info) ;  //输出图书信息
void Book_Search() ;    //搜索图书  0，按书名；1，按作者
void Book_Delete() ;    //删除图书信息
void Book_InfoChange() ;//修改图书信息
void Book_Sort() ;      //图书排序
void Book_RecordSave() ;//图书信息保存
int Book_RecordLoad() ; //读档

void Admin_Login() ;    //管理员登陆
void Member_WelMenu() ; //会员菜单界面
void Book_WelMenu() ;   //管理员菜单界面

void Member_Login() ;   //会员登陆
void Member_Reg() ;     //会员注册
void Member_Bor() ;     //借书手续
void Member_Ret() ;     //还书手续
void Member_Search() ;  //会员资料查询 0，按名字；1，按学号
void Member_Delete() ;  //会员资料注销
void Member_RecordSave() ; //会员信息保存
int Member_RecordLoad() ;  //会员信息读档
void Member_InfoChange() ; //会员信息修改

void Member_MsgShow(Member_Message *Member_Msg ) ; //信息显示
void Member_CodeAdjust() ; //会员修改密码

#endif
