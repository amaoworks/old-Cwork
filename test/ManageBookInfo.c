#include"library.h"
extern struct bookinfo *head;

static void sort()
{
    printf("\n\n\t\t任选功能暂不开发，");
    system("pause");
}
static void deldate()
{
    struct bookinfo *link,*body;
    int numb;
    char choose; 

    link=head;
    system("cls");

    printf("\n\n\t\t输入需要删除的图书编号：");
    scanf("%d",&numb);
    while(link->next!=0)
    {
        body=link; 
        link=link->next;
        if(link->bookId==numb)
        {
            system("cls");
            printf("\t\t  原书信息\n");
            printf("\t\t****************\n");
            printf("\t\t图书编号：%d\n",link->bookId);
            printf("\t\t书    名：%s\n",link->name);
            printf("\t\t单    价：%.2lf\n",link->price);
            printf("\t\t作    者：%s\n",link->author);
            printf("\t\t是否借出：%c\n",link->borrowed);
            printf("\t\t读者编号：%d\n",link->readerID);
            printf("\t\t****************\n\n");

            printf("\t\t确认删除（输入Y确认删除，其他字符视为放弃）："); 
            getchar(); 
            scanf("%c",&choose);
            if(choose=='Y')
            {
                body->next=0;
                free(link);
                printf("\n\n\t\t删除成功，");
                system("pause");
                return; 
            }
            return;
        }

    }
    printf("\n\t\t未找到该图书，");
    system("pause"); 
}
static void update()
{
    struct bookinfo *link,*body;
    int numb,newid;

    link=head;
    system("cls");

    printf("\n\n\t\t输入需要更改的图书编号：");
    scanf("%d",&numb);
    while(link->next!=0)
    {
        link=link->next;
        if(link->bookId==numb)
        {
            system("cls");
            printf("\t\t  原书信息\n");
            printf("\t\t****************\n");
            printf("\t\t图书编号：%d\n",link->bookId);
            printf("\t\t书    名：%s\n",link->name);
            printf("\t\t单    价：%.2lf\n",link->price);
            printf("\t\t作    者：%s\n",link->author);
            printf("\t\t是否借出：%c\n",link->borrowed);
            printf("\t\t读者编号：%d\n",link->readerID);
            printf("\t\t****************\n\n");

            printf("\t\t图书编号(非正数视为放弃)："); 
            scanf("%d",&newid);
            if(newid<=0)
            {
                return; 
            }
            link->bookId=newid;
            printf("\t\t书    名："); 
            getchar();
            gets(link->name);
            printf("\t\t单    价："); 
            scanf("%lf",&link->price);
            printf("\t\t作    者："); 
            getchar();
            gets(link->author);
            return;
        }

    }
    printf("\n\t\t未找到该图书，");
    system("pause"); 
}
static void add()
{
    struct bookinfo *link,*body;
    link=head;
    while(link->next!=0)
    {
            link=link->next;
    }

    system("cls");
    printf("\n\n\t\t输入图书信息(图书编号为非正数则结束)\n\n");
    while(1)
    {
        body=(Book*)malloc(sizeof(Book));
        printf("\t\t图书编号："); 
        scanf("%d",&body->bookId);
        if(body->bookId<=0)
        {
            free(body);
            break;
        }
        printf("\t\t书    名："); 
        getchar();
        gets(body->name);
        printf("\t\t单    价："); 
        scanf("%lf",&body->price);
        printf("\t\t作    者："); 
        getchar();
        gets(body->author);
        body->next=0;
        body->borrowed='N';
        body->readerID=0;
        link->next=body;
        link=body;
        printf("\n\n\t\t****************************\n\n"); 
    }



}
static void show()
{
    struct bookinfo *link;
    system("cls");
    printf("------------------------------图 书 信 息--------------------------------------\n\n");
    printf("图书编号\t书名\t\t单价\t作者\t\t是否借出\t读者编号\n\n");

    link=head;
    while(link->next!=0)
    {
            link=link->next;
            printf("%d\t\t%s\t\t%.2lf\t%s\t\t%c\t\t%d\n\n",link->bookId,link->name,link->price,link->author,link->borrowed,link->readerID);
    }
    system("pause");
}

void manageBookInfo()
{
    while(1)
    {
        int choose;
        //绘制菜单
        system("cls");
        printf("\n\n\t\t         图 书 信 息 管 理\n");
        printf("\t----------------------------------------------\n");
        printf("\t\t\t1.浏览所有图书信息\n\n");
        printf("\t\t\t2.新  增    图  书\n\n");
        printf("\t\t\t3.修 改 图 书 信息\n\n");
        printf("\t\t\t4.删 除 图 书 信息\n\n");
        printf("\t\t\t5.排            序\n\n");
        printf("\t\t\t0.返回 上一级 菜单\n");
        printf("\t----------------------------------------------\n");
        printf("\n\n\t请选择您想使用的功能<0-5>:");

        //选择功能
        scanf("%d",&choose);
        switch(choose)
        {
        case 1:show();break;
        case 2:add();break;
        case 3:update();break;
        case 4:deldate();break;
        case 5:break;
        case 0:return;break;
        default:inputError();break;
        }
    }

}
