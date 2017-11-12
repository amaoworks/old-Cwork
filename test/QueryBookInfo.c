#include"library.h"
extern struct bookinfo *head;

static int findstring(char s1[],char s2[])
{
    int i=0,j=0;
    while(s1[i]!='\0')
    {
        if(s2[j]=='\0') return i;
        if(s1[i+j]==s2[j])
        {
            j++;
        }else{
            i++;
            j=0;
        }

    }
    return -1;
}

static void byId()
{
    struct bookinfo *link,*body;
    int numb,count=0,choose;

    link=head;
    system("cls");

    printf("\n\n\t\t输入要查找的图书编号：");
    scanf("%d",&numb);
    while(link->next!=0)
    {
        body=link; 
        link=link->next;
        if(link->bookId==numb)
        {
            count++;
            //system("cls");
            printf("\n\n\t\t  查询结果\n");
            printf("\t\t****************\n");
            printf("\t\t图书编号：%d\n",link->bookId);
            printf("\t\t书    名：%s\n",link->name);
            printf("\t\t单    价：%.2lf\n",link->price);
            printf("\t\t作    者：%s\n",link->author);
            printf("\t\t是否借出：%c\n",link->borrowed);
            printf("\t\t读者编号：%d\n",link->readerID);
            printf("\t\t****************\n\n");
        }

    }
    if(count==0)
    {
        printf("\n\t\t未找到符合要求的图书，");
    }else{
        printf("\n\t\t共找到%d条结果，",count);
    } 
    printf("输入Y继续查找，其他字符视为放弃：");
    getchar();
    scanf("%c",&choose);
    if(choose=='Y') byId();
}
static void byName()
{
    struct bookinfo *link,*body;
    int count=0;
    char name[20],choose; 

    link=head;
    system("cls");
    //fflush(stdin);

    printf("\n\n\t\t输入要查找的书名关键字：");
    getchar();
    gets(name); 
    while(link->next!=0)
    {
        body=link; 
        link=link->next;
        if(findstring(link->name,name)!=-1)
        {
            count++;
            //system("cls");
            printf("\n\n\t\t  查询结果\n");
            printf("\t\t****************\n");
            printf("\t\t图书编号：%d\n",link->bookId);
            printf("\t\t书    名：%s\n",link->name);
            printf("\t\t单    价：%.2lf\n",link->price);
            printf("\t\t作    者：%s\n",link->author);
            printf("\t\t是否借出：%c\n",link->borrowed);
            printf("\t\t读者编号：%d\n",link->readerID);
            printf("\t\t****************\n\n");
        }

    }
    if(count==0)
    {
        printf("\n\t\t未找到符合要求的图书，");
    }else{
        printf("\n\t\t共找到%d条结果，",count);
    } 
    printf("输入Y继续查找，其他字符视为放弃：");
    scanf("%c",&choose);
    if(choose=='Y') byName();
} 
static void byAuthor()
{
    struct bookinfo *link,*body;
    int count=0;
    char author[20],choose;

    link=head;
    system("cls");

    printf("\n\n\t\t输入要查找的图书作者关键字：");
    getchar(); 
    gets(author); 
    while(link->next!=0)
    {
        body=link; 
        link=link->next;
        if(findstring(link->author,author)!=-1)
        {
            count++;
            //system("cls");
            printf("\n\n\t\t  查询结果\n");
            printf("\t\t****************\n");
            printf("\t\t图书编号：%d\n",link->bookId);
            printf("\t\t书    名：%s\n",link->name);
            printf("\t\t单    价：%.2lf\n",link->price);
            printf("\t\t作    者：%s\n",link->author);
            printf("\t\t是否借出：%c\n",link->borrowed);
            printf("\t\t读者编号：%d\n",link->readerID);
            printf("\t\t****************\n\n");
        }

    }
    if(count==0)
    {
        printf("\n\t\t未找到符合要求的图书，");
    }else{
        printf("\n\t\t共找到%d条结果，",count);
    } 
    printf("输入Y继续查找，其他字符视为放弃：");
    scanf("%c",&choose);
    if(choose=='Y') byAuthor();
} 
void queryBookInfo()
{
    while(1)
    {
        int choose;
        //绘制菜单
        system("cls");
        printf("\n\n\t\t             图书查询\n");
        printf("\t----------------------------------------------\n");
        printf("\t\t\t1.按图书编号查询\n\n");
        printf("\t\t\t2.按 书 名 查 询\n\n");
        printf("\t\t\t3.按 作 者 查 询\n\n");
        printf("\t\t\t0.返回上一级菜单\n");
        printf("\t----------------------------------------------\n");
        printf("\n\n\t请选择您想使用的功能<0-3>:");

        //选择功能
        scanf("%d",&choose);
        switch(choose)
        {
        case 1:byId();break;
        case 2:byName();break;
        case 3:byAuthor();break;
        case 0:return;break;
        default:inputError();break;
        }
    }

}
