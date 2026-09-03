#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *two_sum(const int *nums, int size, int target);

int main()
{

	printf("\n\nDynamic Two Sum (Heap-Allocated Result)\n\n");

	int elements = 0;
	printf("Enter elements quantity: ");
	if(scanf("%d", &elements) != 1 || elements < 2){

		fprintf(stderr, "[ERROR] Elements count must be at least 2.\n");
		return 1;

	}

	int *arr_targ = (int *)malloc((size_t)elements * sizeof(int));
	if(arr_targ == NULL){

		perror("[ERROR] malloc failed");
		return 1;

	}

	srand((unsigned int)time(NULL));

	printf("\nArray elements: ");
	for(int i = 0; i < elements; i++){

		arr_targ[i] = rand() % 50 + 1;
		printf("%d ", arr_targ[i]);

	}
	printf("\n");

	int target = 0;
	printf("Enter target sum: ");
	if(scanf("%d", &target) != 1){

		fprintf(stderr, "[ERROR] Invalid target.\n");
		free(arr_targ);
		return 1;

	}

	int *result = two_sum(arr_targ, elements, target);

	if(result != NULL){

		printf("\n[SUCCESS] Pair found at indices: [%d, %d]\n", result[0], result[1]);
		printf("Values: nums[%d] (%d) + nums[%d] (%d) = %d\n",
		       result[0], arr_targ[result[0]],
		       result[1], arr_targ[result[1]],
		       target);

		free(result);

	}else{

		printf("\n[INFO] No pair found that sums to %d.\n", target);

	}

	free(arr_targ);
	printf("\nMemory deallocated successfully.\n");

	return 0;

}

int *two_sum(const int *nums, int size, int target)
{

	int *sum_index = (int *)malloc(2 * sizeof(int));
	if(sum_index == NULL){

		return NULL;

	}

	for(int i = 0; i < size; i++){

		for(int j = i + 1; j < size; j++){

			if(nums[i] + nums[j] == target){

				sum_index[0] = i;
				sum_index[1] = j;
				return sum_index;

			}

		}

	}

	free(sum_index);
	return NULL;

}
