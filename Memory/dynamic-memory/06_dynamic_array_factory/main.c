#include <stdio.h>
#include <stdlib.h>

#include "mem_helper.h"

int main()
{

	printf("\n\nDynamic Array Factory Module\n\n");

	int size = 0;
	int default_val = 0;

	printf("Enter size of array: ");
	if(scanf("%d", &size) != 1 || size <= 0){

		fprintf(stderr, "[ERROR] Invalid size.\n");
		return 1;

	}

	printf("Enter default value to fill array: ");
	if(scanf("%d", &default_val) != 1){

		fprintf(stderr, "[ERROR] Invalid value.\n");
		return 1;

	}

	int *numbers = creat_and_fill(size, default_val);

	if(numbers == NULL){

		fprintf(stderr, "[ERROR] Allocation failed.\n");
		return 1;

	}

	printf("\n--- Array Elements (%d elements initialized with %d) ---\n", size, default_val);

	for(int i = 0; i < size; i++){

		printf("%d ", numbers[i]);

	}

	printf("\n");

	free(numbers);
	printf("Memory deallocated successfully.\n");

	return 0;

}
