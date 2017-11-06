#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc ,char **argv ){
	printf("The First Result:\n");
	int i = strcmp("Jiu Jiang" , "University");
	printf("%d\n",i );

	printf("The Second Result:\n");
	char *testOne = (char *)malloc(strlen("Jiu Jiang University")+ 1);
	strcpy(testOne ,"Jiu Jiang University");
	for(int i = 0 ;i < 20 ;i++ ){
		printf("%c",testOne[i] );
	}
	printf("\n");

	printf("The Third Result:\n");
	char *testTwo = (char *)malloc(strlen("Jiu Jiang University")+ 1);
	strcpy(testTwo ,"Jiu Jiang");
	char testThree [] = " University";
	strcat(testTwo ,testThree );
	for(int i = 0 ;i < 20 ;i++ ){
		printf("%c",testTwo[i] );
	}
	printf("\n");


	return 0 ;
}
