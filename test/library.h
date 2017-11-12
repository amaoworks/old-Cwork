#ifndef library_h
#define library_h
#define RMAX 40
typedef struct bookinfo
{
    int bookId;
    char name[20];
    double price;
    char borrowed;//Y or N
    char author[20];
    int readerID;
    struct bookinfo *next;
}Book;
typedef struct readerinfo
{
    //读者（读者编号，读者姓名，性别，年龄， 所在系，已借书数）；
    int id;
    char name[20];
    char sex;//F or M
    int age;
    char profess[80];
    int borrowedNumb;
}Reader;
//主菜单
void linkInit();
void inputError();
//图书查询模块
void queryBookInfo();
//图书管理模块
void manageBookInfo();
//读者管理模块
void manageReaderInfo(); 
//借书模块 
void borrowBooks();
//还书模块
void returnBooks();
//系统管理模块
void manageSystem();

#endif
