#include <stdio.h>

int main()
{

	printf("\n\nMissing Number\n\n");

	int quantity = 10;
	int arr_mis[9];


	for(int i = 0; i < quantity - 1; i++){

		printf("Enter %dth number from 1 to %d: ", i + 1, quantity);

		if(scanf("%d", &arr_mis[i]) != 1){

			printf("\n[ERROR] Invalid input!\n");
			return 1;

		}


		if(arr_mis[i] < 1 || arr_mis[i] > quantity){

			printf("\n[ERROR] Number must be between 1 and %d!\n", quantity);
			return 1;

		}


		for(int j = 0; j < i; j++){

			if(arr_mis[i] == arr_mis[j]){

				printf("\n[ERROR] Duplicate number entered!\n");
				return 1;

			}

		}

	}


	int expected_sum = quantity * (quantity + 1) / 2;
	int sum_arr = 0;


	for(int i = 0; i < quantity - 1; i++){

		sum_arr += arr_mis[i];

	}


	int missing_num = expected_sum - sum_arr;


	printf("\nMissing number is: %d\n", missing_num);


	return 0;

}