#include "book.h"

int main(void) 
{ 
	char choice;
	time_t t;
	time (&t);//获取Unix时间戳。
	lt = localtime (&t);//转为时间结构
	do{ 
		system("clear"); 
		printf(" \t\t--------------------------------------------\n"); 
		printf(" \t\t|             图书音像管理系统             |\n"); 
		printf(" \t\t|              今天是%d,%d,%d		   |\n",lt->tm_year+1900,lt->tm_mon +1,lt->tm_mday); 
		printf(" \t\t|------------------------------------------|\n"); 
		printf(" \t\t|   1-- 创建音像图书库                     |\n"); 
		printf(" \t\t|   2-- 租借音像图书                       |\n"); 
		printf(" \t\t|   3-- 归还音像图书                       |\n"); 
		printf(" \t\t|   4-- 购进音像图书                       |\n"); 
		printf(" \t\t|   5-- 报废音像图书                       |\n"); 
		printf(" \t\t|   6-- 显示音像图书                       |\n"); 
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
		case '6':display_book(); break; 
		case '0':break; 
		default:printf("\n 没有选项为 %c 的选项！ \n",choice); 
		printf("\n 请输入任意键继续！ "); 
		getchar();
		getchar();
		system("clear"); 
	} 
}
	while(choice!='0'); 
		printf("\n\t\t感谢使用！下次见 \n"); 
	return 0; 
} 
