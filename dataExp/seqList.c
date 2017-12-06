#include "seqList.h"

void initList(SeqList *List) {
	List->arr = (DataType *)malloc(sizeof(DataType) * initSize);
	if(NULL == List->arr){
		printf("Error!\n");
		return ;
	}
	List->maxSize = initSize;
	List->arrSize = 0;
}

//创建函数
void creatList(SeqList *List ) {
	int arrTmpSize;
	printf("Please input the list size: \n");
	scanf("%d",&arrTmpSize);
	for(int i = 0 ;i < arrTmpSize ;i++ ){
		printf("Please input the %dth number: ",i + 1 );
		scanf("%d",&List->arr[i] );
	}
	List->arrSize = arrTmpSize;

	return;
}

//插入函数
void insertList(SeqList *List ,DataType data ,int local ){
	if(local < 0 || local > List->arrSize - 1){
		printf("Error!\n");
		return;
	} else{
		for(int i = List->arrSize - 1; i > local - 1;i-- )
	}
}
void searchList(SeqList *List ,DataType data );		//查找函数
void deleteList(SeqList *List ,DataType data ,int local );	//删除函数
void displayList(SeqList *List);	//显示函数
