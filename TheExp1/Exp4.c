#include <stdio.h>
#include <stdlib.h>
#define TIMES 4
#define NUM 1

int main(int argc,char **argv){
    int var1;
    const int cvar1;
    int *ptr_var1 = (int *)malloc(sizeof(int));
    const int *ptr_cvar1 = (int *)malloc(sizeof(int));
    int *const cptr_var1 = (int *)malloc(sizeof(int));
    int *const cptr_var2 = (int *)malloc(sizeof(int));
    int const *const cptr_cvar1 = (int *)malloc(sizeof(int));
    
    printf("input the var1 \n");
    scanf("%d",&var1 );
    printf("input the cvar1 \n");
    scanf("%d",&cvar1 );

    //question one
    printf("The answer of test one: \n");
    for(int i = 0; i < TIMES ; i++){
	(var1) ++;
	*ptr_var1 += NUM;
    }
    printf("the var1 : %d and the *ptr_var1 : %d\n", var1 , *ptr_var1);

    //question two
    printf("The answer of test two: \n");
    ptr_cvar1 = &cvar1;
    for(int i = 0; i < TIMES ; i++){
	var1 += NUM;
    }
    printf("the *ptr_cvar1 :%d\n", *ptr_cvar1);

    //question three
    printf("The answer of test three: \n");
    int var2 = 2;
    *cptr_var1 = var1 ;
    *cptr_var2 = var2 ;
    for(int i = 0; i < TIMES ; i++){
	(*cptr_var1) ++;
	(*cptr_var2) ++;
    }
    printf("the *cptr_var1 : %d  and the *cptr_var2 : %d \n",*cptr_var1 ,*cptr_var2 );
    
    //question four
    
    free(ptr_var1);
    free(cptr_var1);
    free(cptr_var2);
    free(cptr_cvar1);

    return 0;
}
