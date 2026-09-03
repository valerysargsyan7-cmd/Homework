#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "sentinel.h"

static void *allocated_pointers[1000];
static int pointer_count = 0;

void *safe_malloc(size_t size)
{

	void *temp = malloc(size);

	if(temp == NULL){

		perror("[ERROR] malloc failed in safe_malloc");
		return NULL;

	}

	if(pointer_count < 1000){

		allocated_pointers[pointer_count] = temp;
		pointer_count++;

	}

	return temp;

}

void safe_free(void *ptr)
{

	if(ptr == NULL){

		return;

	}

	for(int i = 0; i < pointer_count; i++){

		if(allocated_pointers[i] == ptr){

			free(ptr);
			allocated_pointers[i] = NULL;
			break;

		}

	}

}

void force_cleanup(void)
{

	int cleaned_leaks = 0;

	for(int i = 0; i < pointer_count; i++){

		if(allocated_pointers[i] != NULL){

			free(allocated_pointers[i]);
			allocated_pointers[i] = NULL;
			cleaned_leaks++;

		}

	}

	printf("\nForce cleanup status: DONE\n");
	printf("Leaks intercepted and cleaned: %d\n", cleaned_leaks);

}
