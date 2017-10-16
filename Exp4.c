#include <stdio.h>
#include <stdlib.h>

int main(int argc,char **argv){
    int var1;
    const int cvar1;
    int *ptr_var1 = (int *)malloc(sizeof(int));
    const int *ptr_cvar1 = (int *)malloc(sizeof(int));
    int *const cptr_var1 = (int *)malloc(sizeof(int));
    int const *const cptr_var2 = (int *)malloc(sizeof(int));

    printf("input the var1 \n");
    scanf("%d",&var1 );
    printf("input the cvar1 \n");
    scanf("%d",&cvar1 );

    //question one
    int times ;
    printf("请输入自增次数\n");
    scanf("%d",&times);
    int num ;
    printf("请输入加数\n");
    scanf("%d",&num);
    for(int i = 0; i < times ; i++){
	var1++;
	*ptr_var1 += num;
    }
    printf("the var1 : %d and the *ptr_var1 : %d\n", var1 , *ptr_var1);

    //question two
    ptr_cvar1 = &var1;
    for(int i = 0; i < times ; i++){
	*ptr_cvar1 += num;
    }
    printf("the *ptr_cvar1 :%d", *ptr_cvar1);

    //question three
    *cptr_var1 = var1 ;
    *cptr_var2 = cvar1 ;
    for(int i = 0; i < times ; i++){
	(*cptr_var1)++;
	(*cptr_var2)++;
    }
    printf("the *cptr_var1 : %d and the *cptr_var2 : %d \n",*cptr_var1 ,*cptr_var2);

    //question four



    return 0;
}
