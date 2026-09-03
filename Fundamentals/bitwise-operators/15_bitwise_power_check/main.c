#include <stdio.h>

int main()
{

	printf("\n\nBitwise\n\n");

	int bitwise_num = 0;


	printf("Enter number: ");

	if(scanf("%d", &bitwise_num) != 1){

		printf("\n[ERROR] Invalid input!\n");
		return 1;

	}


	if(bitwise_num <= 0){

		printf("\nFALSE\n");

	}else if((bitwise_num & (bitwise_num - 1)) == 0){

		printf("\nTRUE\n");

	}else{

		printf("\nFALSE\n");

	}


	return 0;

}