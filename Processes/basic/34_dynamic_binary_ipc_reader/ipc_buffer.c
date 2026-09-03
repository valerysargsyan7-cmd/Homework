#include <stdio.h>
#include <stdlib.h>

#include "ipc_buffer.h"

int *read_dynamic_numbers(const char *file, int *out_count)
{

	if(out_count == NULL){

		return NULL;

	}

	FILE *file_fp = fopen(file, "rb");

	if(file_fp == NULL){

		perror("[ERROR] fopen error in read_dynamic_numbers");
		*out_count = 0;
		return NULL;

	}

	size_t capacity = 5;
	size_t nums_read = 0;

	int *buffer = (int *)malloc(capacity * sizeof(int));

	if(buffer == NULL){

		perror("[ERROR] malloc failed in read_dynamic_numbers");
		fclose(file_fp);
		*out_count = 0;
		return NULL;

	}

	int temp_val;

	while(fread(&temp_val, sizeof(int), 1, file_fp) == 1){

		if(nums_read >= capacity){

			capacity *= 2;
			int *temp_ptr = (int *)realloc(buffer, capacity * sizeof(int));

			if(temp_ptr == NULL){

				perror("[ERROR] realloc failed in read_dynamic_numbers");
				break;

			}

			buffer = temp_ptr;

		}

		buffer[nums_read] = temp_val;
		nums_read++;

	}

	fclose(file_fp);
	*out_count = (int)nums_read;

	return buffer;

}
