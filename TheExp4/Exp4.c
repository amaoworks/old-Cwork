#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const char* s1 ,const char* s2 ){
	return strcmp(s1,s2);
}

char* stringToLower(const char* string ){
	char *tmp = (char*)malloc(strlen(string) + 1);
	char *start = tmp;
	while (*string != 0){
		*tmp++ = tolower(*string++);
	}
	*tmp = 0;
	return start;
}

int compareIgnoreCase(const char* s1 ,const char* s2 ){
	char* t1 = stringToLower(s1);
	char* t2 = stringToLower(s2);
}

typedef int (fptrOperation)(const char* ,const char* );

void sort(char *array[] ,int size ,fptrOperation operation ){
	int swap = 1;
	while(swap){
		swap = 0 ;
		for(int i = 0 ;i < size - 1 ;i++ ){
			if(operation(array[i],array[i+1]) > 0){
				swap = 1;
				char *tmp = array[i];
				array[i]= array[i+1];
				array[i+1] = tmp;
			}
		}
	}
}

void displayNames(char* name[] ,int size ){
	for(int i = 0 ;i < size ;i++ ){
		printf("%s\t",name[i] );
	}
	printf("\n");
}

int main(int argc , int **argv ){
	char* nameOne[] = {"Bob","Ted","Carol","Alice","alice"};
	char* nameTwo[] = {"Bob","Ted","Carol","Alice","alice"};
	sort(nameOne,5,compare);
	sort(nameTwo,5,compareIgnoreCase);
	printf("The result of first question:\n");
	displayNames(nameOne,5);
	printf("The result of second question:\n");
	displayNames(nameTwo,5);

	return 0 ;
}
