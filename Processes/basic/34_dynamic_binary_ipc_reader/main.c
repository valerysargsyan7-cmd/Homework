#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#include "ipc_buffer.h"

int main()
{

	printf("\n\nDynamic Binary IPC Reader with Geometric Realloc\n\n");

	const char *filename = "rand_numbers.bin";

	FILE *fp = fopen(filename, "wb");

	if(fp == NULL){

		perror("[ERROR] Failed to create rand_numbers.bin");
		return 1;

	}

	int buffer[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120};
	int count = sizeof(buffer) / sizeof(buffer[0]);

	fwrite(buffer, sizeof(int), (size_t)count, fp);
	fclose(fp);

	printf("[PARENT] -> Wrote %d integers to '%s'.\n", count, filename);

	pid_t child = fork();

	if(child < 0){

		perror("[ERROR] fork failed");
		return 1;

	}

	if(child == 0){

		//CHILD
		int out_count = 0;
		int *numbers = read_dynamic_numbers(filename, &out_count);

		if(numbers != NULL){

			printf("\n[CHILD] -> Read %d elements dynamically:\n", out_count);

			for(int i = 0; i < out_count; i++){

				printf("  Element[%d] = %d\n", i, numbers[i]);

			}

			free(numbers);

		}

		exit(0);

	}else{

		//PARENT
		wait(NULL);
		printf("\n[PARENT] -> Child read finished. Exiting.\n");

	}

	return 0;

}
