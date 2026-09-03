#include <stdio.h>

int main()
{

	printf("\n\nUnique Member of Array\n\n");

	int numbers[10];


	for(int i = 0; i < 10; i++){

		printf("Enter %dth member of array: ", i + 1);

		if(scanf("%d", &numbers[i]) != 1){

			printf("\n[ERROR] Invalid input!\n");
			return 1;

		}

	}


	int unique_index = -1;


	for(int i = 0; i < 10; i++){

		int count = 0;


		for(int j = 0; j < 10; j++){

			if(numbers[i] == numbers[j]){

				count++;

			}

		}


		if(count == 1){

			unique_index = i;
			break;

		}

	}


	if(unique_index == -1){

		printf("\n[ERROR] Unique number was not found!\n");
		return 1;

	}


	printf("\nUnique number is: %d\n", numbers[unique_index]);


	return 0;

}