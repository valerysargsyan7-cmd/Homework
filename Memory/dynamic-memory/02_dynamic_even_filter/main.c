#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

	printf("\n\nDynamic Even Number Filtering\n\n");

	int size_of_rand_arr = 0;

	printf("Enter size of random numbers array: ");
	if(scanf("%d", &size_of_rand_arr) != 1 || size_of_rand_arr <= 0){

		fprintf(stderr, "[ERROR] Invalid array size.\n");
		return 1;

	}

	int *rand_num = (int *)malloc((size_t)size_of_rand_arr * sizeof(int));
	if(rand_num == NULL){

		perror("[ERROR] Failed to allocate random numbers array");
		return 1;

	}

	srand((unsigned int)time(NULL));

	printf("\nGenerated Random Array:\n");
	for(int i = 0; i < size_of_rand_arr; i++){

		rand_num[i] = rand() % 100 + 1;
		printf("%d ", rand_num[i]);

	}
	printf("\n");

	int even_count = 0;
	for(int j = 0; j < size_of_rand_arr; j++){

		if(rand_num[j] % 2 == 0){

			even_count++;

		}

	}

	printf("\nFound %d even numbers.\n", even_count);

	if(even_count > 0){

		int *even_arr = (int *)malloc((size_t)even_count * sizeof(int));

		if(even_arr == NULL){

			perror("[ERROR] Failed to allocate even numbers array");
			free(rand_num);
			return 1;

		}

		int index = 0;
		for(int k = 0; k < size_of_rand_arr; k++){

			if(rand_num[k] % 2 == 0){

				even_arr[index] = rand_num[k];
				index++;

			}

		}

		printf("Filtered Even Array:\n");
		for(int j = 0; j < even_count; j++){

			printf("%d ", even_arr[j]);

		}
		printf("\n");

		free(even_arr);

	}else{

		printf("No even numbers found in generated array.\n");

	}

	free(rand_num);
	printf("\nMemory cleaned up successfully.\n");

	return 0;

}
