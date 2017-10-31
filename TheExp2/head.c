#include "head.h"

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
