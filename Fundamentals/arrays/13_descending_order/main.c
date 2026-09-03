#include <stdio.h>

int main()
{

	printf("\n\nDescending Order\n\n");

	int arr_des_ord[10];


	for(int i = 0; i < 10; i++){

		printf("Enter %dth number: ", i + 1);

		if(scanf("%d", &arr_des_ord[i]) != 1){

			printf("\n[ERROR] Invalid input!\n");
			return 1;

		}

	}


	for(int i = 1; i < 10; i++){

		if(arr_des_ord[i] > arr_des_ord[i - 1]){

			printf("\nNO\n");
			return 0;

		}

	}


	printf("\nYES\n");


	return 0;

}