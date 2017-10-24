#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc ,char **argv){
    char testOne[] = "Hello,jju!" ;
    char *testTwo = (char *)malloc(strlen("Hello,jju!")+ 1);
    strcpy(testTwo,"Hello,jju!");
   
    printf("The result of test one :\t");
    for(int i = 0 ;i < 10 ; i++){
	printf("%c",testOne[i]);
    }
    printf("\n");
    printf("The result of test two :\t");
    for(int i = 0 ;i < 10 ; i++){
	printf("%c",testTwo[i]);
    }
    printf("\n");

    free(testTwo);

    return 0;
}
