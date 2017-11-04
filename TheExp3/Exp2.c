#include <stdio.h>

void displayArrar(int arrar[] , int size ){
	for(int i = 0 ; i < size ; i++ ){
		printf("%d\t", arrar[i] );
	}
}

void Back(int *ptr_arr , int size , int temp ){
	for(int i = 0 ; i < (size - 1) ; i++ ){
		for(int j = 0 ; j < (size -1 -j) ; j++ )
			if(*(ptr_arr + j) > *(ptr_arr + j +1)){
				temp = *(ptr_arr + j) ;
				*(ptr_arr + j) = *(ptr_arr + j + 1) ;
				*(ptr_arr + j + 1) = temp ;
			}
	}
}

int main(int argc , char **argv){
	//init the arrar
	int size , temp ;
	printf("Please input size :\n");
	scanf("%d", &size);
	int arrar[size] ;
	int *ptr_arr = arrar ;
	printf("Please input an arrar :\n");
	for(int i = 0 ; i < size ; i++ ){
		scanf("%d", &arrar[i]);
	}
	
	//the algorithm
	Back(ptr_arr , size , temp );

	//display the result
	printf("The result is :");
	displayArrar(arrar , size );
	printf("\n");

	return 0 ;
}
