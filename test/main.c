#include<stdio.h>
#include<stdlib.h>
#include"library.h"

Book *head;
Reader reader[RMAX];
int num=0;
void esc()
{
    char choose;
    system("cls");
    printf("\n\n是否导出全部数据：<Y--是>：");
    getchar();
    scanf("%c",&choose);
    if(choose=='Y')exportAll();
}

int main()
{
    linkInit();
    while(1)
    {
        int choose;
        //绘制菜单
        system("cls");
        printf("\n\n\t\t     图书借阅管理信息系统\n");
        printf("\t----------------------------------------------\n");
        printf("\t\t\t1.图书信息查询\n\n");
        printf("\t\t\t2.图书信息管理\n\n");
        printf("\t\t\t3.读者信息管理\n\n");
        printf("\t\t\t4.借        书\n\n");
        printf("\t\t\t5.还        书\n\n");
        printf("\t\t\t6.系 统  管 理\n\n");
        printf("\t\t\t0.退 出  系 统\n");
        printf("\t----------------------------------------------\n");
        printf("\n\n\t请选择您想使用的功能<0-6>:");

        //选择功能
        scanf("%d",&choose);
        switch(choose)
        {
        case 1:queryBookInfo(head);break;
        case 2:manageBookInfo();break;
        case 3:manageReaderInfo();break;
        case 4:borrowBooks();break;
        case 5:returnBooks();break;
        case 6:manageSystem();break;
        case 0:esc();return 0;break;
        default:inputError();break;
        }
    }

    return 0;
}

void linkInit()
{
    Book *body1,*body2,*body3;

    head=(Book*)malloc(sizeof(Book));
    head->next=NULL;

    //测试数据



}


void inputError()
{
    printf("\n\t您输入的不是正确的序号，");
    system("PAUSE");
}
