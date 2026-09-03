#include <stdio.h>
#include <stdlib.h>

#include "mem_helper.h"

int *creat_and_fill(int size, int default_val)
{

	if(size <= 0){

		return NULL;

	}

	int *numbers = (int *)malloc((size_t)size * sizeof(int));

	if(numbers == NULL){

		perror("[ERROR] malloc failed in creat_and_fill");
		return NULL;

	}

	for(int i = 0; i < size; i++){

		numbers[i] = default_val;

	}

	return numbers;

}
