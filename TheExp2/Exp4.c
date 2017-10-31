#include <stdio.h>
#include "head.h"

int main(int argc, char **argv){
    int var1 , var2;
    char sym ;
    printf("Please input the Formula,like '1,+,1'\n");
    scanf("%d,%c,%d", &var1, &sym, &var2);
    printf("The result is:%d %c %d = %d\n", var1, sym, var2, evaluate(sym,var1,var2));


	return 0 ;
}
