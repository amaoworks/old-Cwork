#include <stdio.h>

int add(int num1 , int num2){
    return num1 + num2 ;
}

int sub(int num1 , int num2){
    return num1 - num2 ;
}

int mul(int num1 , int num2){
    return num1 * num2 ;
}

int div(int num1 , int num2){
    return num1 / num2 ;
}

int rem(int num1 , int num2){
    return num1 % num2 ;
}

typedef int (*fptrOperation)(int , int);

int calculate( fptrOperation operation, int num1, int num2){
    return operation(num1 , num2);
}

int main(int argc ,char **argv){
    int var1 , var2;
    char sym ;
    printf("Please input the Formula,like '1,+,1'\n");
    scanf("%d,%c,%d", &var1, &sym, &var2);
    switch(sym) {
	case '+':
	    printf("The result is:%d %c %d = %d\n", var1, sym, var2, calculate(add,var1,var2));
	    break;
	case '-':
	    printf("The result is:%d %c %d = %d\n", var1, sym, var2, calculate(sub,var1,var2));
	    break;
	case '*':
	    printf("The result is:%d %c %d = %d\n", var1, sym, var2, calculate(mul,var1,var2));
	    break;
	case '/':
	    printf("The result is:%d %c %d = %d\n", var1, sym, var2, calculate(div,var1,var2));
	    break;
	case '%':
	    printf("The result is:%d %c %d = %d\n", var1, sym, var2, calculate(rem,var1,var2));
	    break;
	default:
	    printf("You input a error symbol !\n");
    }

    return 0 ;
}
