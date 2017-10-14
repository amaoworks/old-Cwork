#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int Var1 ,Var2 ,Var3 ;
    int *ptr_var1 = &Var1 ;
    int *ptr_var2 = &Var2 ;
    int *ptr_var3 = &Var3 ;

    printf("input three Var(use the','separate by the number)\n");
    scanf("%d,%d,%d",&Var1, &Var2, &Var3);
    output(ptr_var1 , ptr_var2 , ptr_var3);
    transfrom(ptr_var1 , ptr_var2 , ptr_var3);
    printf("The new thress numbers :%d , %d , %d .\n", *ptr_var1 , *ptr_var2 , *ptr_var3 );
    
    return 0;
}

void output(int *a, int *b, int *c)
{
    printf("The Num : %d and address : %p .\n", *a , a);
    printf("The Num : %d and address : %p .\n", *b , b);
    printf("The Num : %d and address : %p .\n", *c , c);
}

void transfrom(int *a , int *b , int *c){
    int tem ;
    tem = *a ;
    *a = *b ;
    *b = *c ;
    *c = tem ;
}
