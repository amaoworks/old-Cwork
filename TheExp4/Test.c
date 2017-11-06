#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* format(char *buffer ,size_t size ,const char* name ,size_t quantity ,size_t weight ){
	char *formatString = "Item: %s Quantity: %u Weight: %u";
	printf("fromatString length: %d\n",strlen(formatString));
	size_t formatStringLength = strlen(formatString) - 6;
	size_t nameLength = strlen(name);
	size_t length = formatStringLength + nameLength + 4 + 4 + 1;
	if(buffer == NULL){
		buffer = (char*)malloc(length);
		size = length;
	}
	snprintf(buffer ,size ,formatString ,name ,quantity ,weight);

	return buffer;
}

int main(int argc ,char **argv ){
	char* buffer = NULL;

	char name[10];
	printf("please input name:\t");
	scanf("%s",name );
	printf("please input quantity:\t");
	unsigned int quan;
	scanf("%u",&quan);
	unsigned int weig;
	printf("please input weight:\t");
	scanf("%u",&weig);

	printf("%s\n",format(buffer ,sizeof(buffer) ,name ,quan ,weig));

	return 0;
}
