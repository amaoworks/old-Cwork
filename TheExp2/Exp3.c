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
    
fptrOperation select(char opcode){
	switch(opcode){
	    case '+': return add;
		      break;
	    case '-': return sub;
		      break;
	    case '*': return mul;
		      break;
	    case '/': return div;
		      break;
	    case '%': return rem;
		      break;
	    default: printf("you enter a error symbol !\n");
	}
    }

int evaluate(char opcode, int num1, int num2){
    fptrOperation operation = select(opcode);
    return operation(num1, num2);
}
    
int main(int argc,char **argv){
    int var1 , var2;
    char sym ;
    printf("Please input the Formula,like '1,+,1'\n");
    scanf("%d,%c,%d", &var1, &sym, &var2);
    printf("%d,%c,%d", var1, sym, var2);
    /*fptrOperation select(char opcode){
	switch(opcode){
	    case '+': return add;
	    case '-': return sub;
	    case '*': return mul;
	    case '/': return div;
	    case '%': return rem;
	}
    }*/
    printf("The result is:%d %c %d = %d\n", var1, sym, var2, evaluate('sym',var1,var2));
    

    return 0;
}
