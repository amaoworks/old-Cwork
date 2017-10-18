#include <stdio.h>

void swapOne(int *num1 , int *num2){
    int tem ;
    tem = *num1 ;
    *num1 = *num2 ;
    *num2 = tem ;
}

void swapTwo(int num1 , int num2){
    int tem ;
    tem = num1 ;
    num1 = num2 ;
    num2 = tem ;
}

int main(int argc , char **argv){
    int var1 , var2 , var3 , var4 ;
    int *ptr_var1 = &var1 ;
    int *ptr_var2 = &var2 ;
    int *ptr_var3 = &var3 ;
    int *ptr_var4 = &var4 ;
    printf("Please input four number for test and use the ',' separate it .\n");
    scanf("%d,%d,%d,%d",ptr_var1 , ptr_var2 , ptr_var3 , ptr_var4);

    swapOne(ptr_var1 , ptr_var2);
    printf("The Result of swapOne : %d , %d \n",var1 , var2 );
    
    swapTwo(var3 , var4 );
    printf("The Result of swaptwo : %d , %d \n",var3 , var4 );

    return 0 ;
}
