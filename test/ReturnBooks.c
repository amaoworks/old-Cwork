#include"library.h"
extern Reader reader[RMAX];
extern int num;
extern struct bookinfo *head;
static Book* getBookById(int numb)
{
    struct bookinfo *link,*body;

    link=head;

    while(link->next!=0)
    {
        body=link; 
        link=link->next;
        if(link->bookId==numb)
        {
            if(link->borrowed=='N')
            {
                printf("\n错误：该图书尚未外借");
                return 0;
            }else{
                return link;
            }

        }

    }
    printf("\n错误：未找到符合要求的图书");
    return 0;
}
void returnBooks()
{
    int bookid,readerid,i;
    Book *node;
    char choose;

    system("cls");
    printf("\n\n\t\t    归还图书");
    printf("\n--------------------------------------\n");
    printf("\n图书编号：");
    scanf("%d",&bookid);
    node=getBookById(bookid);
    if(node!=0)
    {
        printf("\n读者编号：");
        scanf("%d",&readerid);
        for(i=0;i<num;i++)
        {
            if(reader[i].id==readerid)
            {
                if(node->readerID!=reader[i].id)
                {
                    printf("\n\n错误：该读者没有借此书");
                    break;
                }
                node->borrowed='N';
                node->readerID=0;
                reader[i].borrowedNumb--;
                printf("\n\n归还完成！");
                break;
            }
        }
        if(i==num)
        {
            printf("\n\n错误：未找到该读者");
        }

    }

    printf("\n\n是否继续借书：<Y--是>：");
    getchar();
    scanf("%c",&choose);
    if(choose=='Y')returnBooks();
}
