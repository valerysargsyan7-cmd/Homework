#include <stdio.h>
#include <stdlib.h>

#include "parallel_math.h"

int main()
{

	printf("\n\nModular Parallel Chunk Summing (Map-Reduce)\n\n");

	int size = 20;
	int chunks = 4;

	int *array = (int *)malloc((size_t)size * sizeof(int));

	if(array == NULL){

		perror("[ERROR] malloc failed");
		return 1;

	}

	for(int i = 0; i < size; i++){

		array[i] = i + 1;

	}

	printf("Summing array of 20 elements (1..20) across %d worker processes:\n\n", chunks);

	long result = parallel_sum(array, size, chunks);

	printf("\n[PARENT] -> Combined Total Sum: %ld (Expected: 210)\n", result);

	free(array);

	return 0;

}
