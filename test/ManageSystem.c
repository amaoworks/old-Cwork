#include"library.h"
#include<stdio.h>
extern Reader reader[RMAX];
extern int num;
extern struct bookinfo *head;
//导出操作
static void exportBook()
{
    FILE *fp;
    Book *link,*last;
    char choose;
    link=head;


    fp=fopen("book.dat","wb");
    while(link->next!=0)
    {
        last=link;
        link=link->next;
        fwrite(link,sizeof(Book),1,fp);
        last->next=link->next;
        free(link);
        link=last;
    }
    fclose(fp);
    num=0;
    system("cls");
    printf("\n\n\t\t图书信息导出成功！\n\n\t\t");
    system("pause");
}
static void exportReader()
{
    FILE *fp;
    int i;
    char choose;

    fp=fopen("reader.dat","wb");
    for(i=0;i<num;i++)
    {
        fwrite(&reader[i],sizeof(Reader),1,fp);
    }

    fclose(fp);

    system("cls");
    printf("\n\n\t\t读者信息导出成功！\n\n\t\t");
    system("pause");
}
void exportAll()
{
    exportReader();
    exportBook();

}

//导入操作
static void importBook()
{
    FILE *fp;
    Book *link,*body;
    link=head;
    fp=fopen("book.dat","rb");

    while(1)
    {
        body=(Book*)malloc(sizeof(Book));
        fread(body,sizeof(Book),1,fp);
        if(feof(fp))
        {
            free(body);
            break;
        }
        body->next=0;
        link->next=body;
        link=body;

    }

    fclose(fp);
    system("cls");
    printf("\n\n\t\t图书信息导入成功！\n\n\t\t");
    system("pause");
}
static void importReader()
{
    FILE *fp;
    int i;
    char choose;

    fp=fopen("reader.dat","rb");
    num=0;
    for(i=0;i<RMAX;i++)
    {
        fread(&reader[i],sizeof(Reader),1,fp);
        if(feof(fp))break;
        num++;
    }
    system("cls");
    printf("\n\n\t\t读者信息导入成功！\n\n\t\t");
    system("pause");

}
static void importAll()
{
    importReader();
    importBook();

}

//导出菜单
static void export()
{
    while(1)
    {
        int choose;
        //绘制菜单
        system("cls");
        printf("\n\n\t\t         导 出 到 文 件\n");
        printf("\t----------------------------------------------\n");
        printf("\t\t\t1.导 出 图 书 信 息\n\n");
        printf("\t\t\t2.导 出 读 者 信 息\n\n");
        printf("\t\t\t3.导 出 全 部 信 息\n\n");
        printf("\t\t\t0.返 回 上 级 菜 单\n");
        printf("\t----------------------------------------------\n");
        printf("\n\n\t请选择您想使用的功能<0-5>:");

        //选择功能
        scanf("%d",&choose);
        switch(choose)
        {
        case 1:exportBook();break;
        case 2:exportReader();break;
        case 3:exportAll();break;
        case 0:return;break;
        default:inputError();break;
        }
    }
}
//导入菜单
static void import()
{
    while(1)
    {
        int choose;
        //绘制菜单
        system("cls");
        printf("\n\n\t\t         导 入 到 系 统\n");
        printf("\t----------------------------------------------\n");
        printf("\t\t\t1.导 入 图 书 信 息\n\n");
        printf("\t\t\t2.导 入 读 者 信 息\n\n");
        printf("\t\t\t3.导 入 全 部 信 息\n\n");
        printf("\t\t\t0.返 回 上 级 菜 单\n");
        printf("\t----------------------------------------------\n");
        printf("\n\n\t请选择您想使用的功能<0-5>:");

        //选择功能
        scanf("%d",&choose);
        switch(choose)
        {
        case 1:importBook();break;
        case 2:importReader();break;
        case 3:importAll();break;
        case 0:return;break;
        default:inputError();break;
        }
    }
}
void manageSystem()
{
    while(1)
    {
        int choose;
        //绘制菜单
        system("cls");
        printf("\n\n\t\t         系 统 管 理\n");
        printf("\t----------------------------------------------\n");
        printf("\t\t\t1.导 出  到  文 件\n\n");
        printf("\t\t\t2.从 文  件  导 入 \n\n");
        printf("\t\t\t0.返回 上一级 菜单\n");
        printf("\t----------------------------------------------\n");
        printf("\n\n\t请选择您想使用的功能<0-5>:");

        //选择功能
        scanf("%d",&choose);
        switch(choose)
        {
        case 1:export();break;
        case 2:import();break;
        case 0:return;break;
        default:inputError();break;
        }
    }
}
