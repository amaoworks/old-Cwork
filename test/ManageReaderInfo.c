#include"library.h"
extern Reader reader[RMAX];
extern int num;

static void sort()
{
    printf("\n\n\t\t任选功能暂不开发，");
    system("pause");
}
static void deldate()
{
    int i,j,temp;
    Reader newReader;
    char choose;

    system("cls");
    printf("\n\n\t\t输入需要删除的读者编号：");
    scanf("%D",&temp);
    for(i=0;i<num;i++)
    {
        if(reader[i].id==temp)
        {
            printf("\n\t\t读者编号：%d",reader[i].id);
            printf("\n\t\t读 者 名：%s",reader[i].name);
            printf("\n\t\t年    龄：%d",reader[i].age);
            printf("\n\t\t性别<F/M>：%c",reader[i].sex);
            printf("\n\t\t所 在 系：%s",reader[i].profess);
            getchar();
            printf("\n\n\t\t确认删除（输入Y确认，其他字符视为放弃）：");
            scanf("%c",&choose);
            if(choose=='Y')
            {
                for(j=i;j<num-1;j++);
                {
                    reader[j]=reader[j+1];
                }
                num--;
            }
            break;

        }
    }
    if(i==num)
    {
        printf("\n\t\t错误：该读者不存在！\n");
        printf("\t\t");
        system("pause");
    }


}
static void update()
{
    int i,temp;
    Reader newReader;
    char choose;

    system("cls");
    printf("\n\n\t\t输入需要更改的读者编号：");
    scanf("%D",&temp);
    for(i=0;i<num;i++)
    {
        if(reader[i].id==temp)
        {
            printf("\n\t\t读者编号：%d",reader[i].id);
            printf("\n\t\t读 者 名：%s",reader[i].name);
            printf("\n\t\t年    龄：%d",reader[i].age);
            printf("\n\t\t性别<F/M>：%c",reader[i].sex);
            printf("\n\t\t所 在 系：%s",reader[i].profess);
            printf("\n\n\t**************（新读者编号为非正数视为放弃）*************");

            printf("\n\n\t\t读者编号："); 
            scanf("%d",&newReader.id);
            if(newReader.id<=0)
            {
                return;
            }
            printf("\t\t读 者 名："); 
            getchar();
            gets(newReader.name);
            printf("\t\t年    龄："); 
            scanf("%d",&newReader.age);
            printf("\t\t性别<F/M>："); 
            getchar();
            scanf("%c",&newReader.sex);
            printf("\t\t所 在 系："); 
            getchar();
            gets(newReader.profess);
            newReader.borrowedNumb=0;
            printf("\n\t\t确认更改（输入Y确认，其他字符视为放弃）：");
            scanf("%c",&choose);
            if(choose=='Y')
            {
                reader[i]=newReader;
            }
            break;

        }
    }
    if(i==num)
    {
        printf("\n\t\t错误：该读者不存在！\n");
        printf("\t\t");system("pause");
    }


}
static void add()
{
    Reader newReader;

    system("cls");
    printf("\n\n\t\t输入读者信息(读者编号为非正数则结束)\n");
    while(1)
    {
        printf("\n\t\t----------------------------------------\n"); 
        printf("\t\t读者编号："); 
        scanf("%d",&newReader.id);
        if(newReader.id<=0)
        {
            break;
        }
        printf("\t\t读 者 名："); 
        getchar();
        gets(newReader.name);
        printf("\t\t年    龄："); 
        scanf("%d",&newReader.age);
        printf("\t\t性别<F/M>："); 
        getchar();
        scanf("%c",&newReader.sex);
        printf("\t\t所 在 系："); 
        getchar();
        gets(newReader.profess);
        newReader.borrowedNumb=0;
        reader[num++]=newReader;
    }

}
static void show()
{
    int i=0;
    system("cls");
    printf("------------------------------读 者 信 息--------------------------------------\n\n");
    printf("读者编号\t姓名\t性别\t年龄\t所在系\t\t借书数\n");
    for(i=0;i<num;i++)
    {
        printf("%d\t\t%s\t%c\t%d\t%s\t\t%d\n",reader[i].id,reader[i].name,reader[i].sex,reader[i].age,reader[i].profess,reader[i].borrowedNumb);
    }
    system("pause");
}

void manageReaderInfo()
{
    while(1)
    {
        int choose;
        //绘制菜单
        system("cls");
        printf("\n\n\t\t         读 者 信 息 管 理\n");
        printf("\t----------------------------------------------\n");
        printf("\t\t\t1.浏览所有读者信息\n\n");
        printf("\t\t\t2.新  增    读  者\n\n");
        printf("\t\t\t3.修 改 读 者 信息\n\n");
        printf("\t\t\t4.删 除 读 者 信息\n\n");
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
