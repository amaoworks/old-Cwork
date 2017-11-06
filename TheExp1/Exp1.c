#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    //指定内存空间并分配
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
    int *use = ptr_arr;
    for(int i = 0; i < size; i++){
	*(ptr_arr + i) = orinVal + i *addVal;
    }

    for(int i = 0; i < size; i++){
	printf("address: %p and value: %d\n", use + i, *(use + i));
    }

    return 0;
}
