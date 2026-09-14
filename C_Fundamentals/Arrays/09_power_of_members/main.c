#include <stdio.h>

void square_elements(int *arr, int *new_arr, int size);

int main()
{

	printf("\n\nArray Member's Power\n\n");

	int powering_arr[10];
	int powered_arr[10];


	for(int i = 0; i < 10; i++){

		printf("Enter %dth number: ", i + 1);

		if(scanf("%d", &powering_arr[i]) != 1){

			printf("\n[ERROR] Invalid input!\n");
			return 1;

		}

	}


	square_elements(powering_arr, powered_arr, 10);


	printf("\nPowered array:\n");


	for(int i = 0; i < 10; i++){

		printf("%d ", powered_arr[i]);

	}


	printf("\n");


	return 0;

}



void square_elements(int *arr, int *new_arr, int size){

	for(int i = 0; i < size; i++){

		new_arr[i] = arr[i] * arr[i];

	}

}

