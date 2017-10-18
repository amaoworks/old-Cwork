#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int size;
    printf("input the size: \n");
    scanf("%d", &size);
    int *ptr_arr = (int *)malloc(sizeof(int) * size);

    //初始化初始变量和增加量
    int orinVal;
    int addVal;
    printf("input the orinVal: \n");
    scanf("%d", &orinVal);
    printf("input the addVal: \n");
    scanf("%d", &addVal);
    int *start = ptr_arr;
    for(int i = 0; i < size; i++){
	*(ptr_arr + i) = orinVal + i *addVal;
    }

    for(int i = 0; i < size; i++){
	printf("address: %p and value: %d\n", start + i, *(start + i));
    }

    return 0;
}
