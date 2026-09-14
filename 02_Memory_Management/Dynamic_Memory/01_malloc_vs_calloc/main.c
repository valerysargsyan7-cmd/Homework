#include <stdio.h>
#include <stdlib.h>

int main()
{

	printf("\n\nMalloc vs Calloc Memory Allocation\n\n");

	int size_mal = 0;
	printf("Enter size for malloc array: ");
	if(scanf("%d", &size_mal) != 1 || size_mal <= 0){

		fprintf(stderr, "[ERROR] Invalid size.\n");
		return 1;

	}

	int *arr_mal = (int *)malloc((size_t)size_mal * sizeof(int));
	if(arr_mal == NULL){

		perror("[ERROR] malloc failed");
		return 1;

	}

	int size_cal = 0;
	printf("Enter size for calloc array: ");
	if(scanf("%d", &size_cal) != 1 || size_cal <= 0){

		fprintf(stderr, "[ERROR] Invalid size.\n");
		free(arr_mal);
		return 1;

	}

	int *arr_cal = (int *)calloc((size_t)size_cal, sizeof(int));
	if(arr_cal == NULL){

		perror("[ERROR] calloc failed");
		free(arr_mal);
		return 1;

	}

	printf("\n--- Uninitialized malloc values (indeterminate) ---\n");
	for(int i = 0; i < size_mal; i++){

		printf("Malloc[%d]: %d\n", i, arr_mal[i]);

	}

	printf("\n--- Zero-initialized calloc values (guaranteed 0) ---\n");
	for(int j = 0; j < size_cal; j++){

		printf("Calloc[%d]: %d\n", j, arr_cal[j]);

	}

	for(int i = 0; i < size_mal; i++){

		arr_mal[i] = i + 1;

	}

	for(int j = 0; j < size_cal; j++){

		arr_cal[j] = (j + 1) * 10;

	}

	printf("\n--- Populated malloc array ---\n");
	for(int i = 0; i < size_mal; i++){

		printf("Malloc[%d]: %d\n", i, arr_mal[i]);

	}

	printf("\n--- Populated calloc array ---\n");
	for(int j = 0; j < size_cal; j++){

		printf("Calloc[%d]: %d\n", j, arr_cal[j]);

	}

	free(arr_mal);
	free(arr_cal);

	printf("\nMemory deallocated successfully.\n");

	return 0;

}
