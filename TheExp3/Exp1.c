#include <stdio.h>

int main(int argc , char **argv){
	//init the arrar
	int size , temp ;
	printf("Please input the size :\n");
	scanf("%d", &size );
	int arrar[size] ;
	int *ptr_arr = arrar ;
	printf("Please input an arrar :\n");
	for(int i = 0 ; i < size ; i++ ){
			scanf("%d", ptr_arr + i);
	}

	//the algorithm
	for(int i = 0 ; i < ( size - 1) ; i++ ){
		for(int j = 0 ; j < ( size - 1 - i) ; j++ )
			if ( arrar[j] > arrar[j+1]){
				temp = arrar[j] ;
				arrar[j] = arrar[j+1] ;
				arrar[j+1] = temp ;
			}
	}

	//display the result
	printf("The result is :");
	for(int i = 0 ; i < size ; i++ ){
		printf("%d\t", *(ptr_arr + i) );
	}
	printf("\n");

	return 0;
}
