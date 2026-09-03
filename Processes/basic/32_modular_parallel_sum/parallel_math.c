#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#include "parallel_math.h"

long parallel_sum(const int *arr, int size, int chunks)
{

	if(arr == NULL || size <= 0 || chunks <= 0){

		return 0;

	}

	if(chunks > size){

		chunks = size;

	}

	int chunk_size = size / chunks;

	pid_t *pids = (pid_t *)malloc((size_t)chunks * sizeof(pid_t));

	if(pids == NULL){

		perror("[ERROR] malloc failed in parallel_sum");
		return -1;

	}

	for(int i = 0; i < chunks; i++){

		int start_index = i * chunk_size;
		int end_index = (i == chunks - 1) ? size : (i + 1) * chunk_size;

		pid_t pid = fork();

		if(pid < 0){

			perror("[ERROR] fork failed in parallel_sum");
			free(pids);
			return -1;

		}

		if(pid == 0){

			//CHILD
			char filename[32];
			snprintf(filename, sizeof(filename), "tmp_chunk_%d.txt", i);

			FILE *fp = fopen(filename, "w");

			if(fp == NULL){

				perror("[ERROR] fopen error in child");
				free(pids);
				exit(1);

			}

			long sum_of_nums = 0;

			for(int j = start_index; j < end_index; j++){

				sum_of_nums += arr[j];

			}

			fprintf(fp, "%ld\n", sum_of_nums);
			fclose(fp);

			printf("[CHILD %d] -> Calculated chunk sum (%d..%d): %ld\n",
			       i, start_index, end_index - 1, sum_of_nums);

			free(pids);
			exit(0);

		}else{

			pids[i] = pid;

		}

	}

	for(int i = 0; i < chunks; i++){

		waitpid(pids[i], NULL, 0);

	}

	long total_sum = 0;

	for(int i = 0; i < chunks; i++){

		char filename[32];
		snprintf(filename, sizeof(filename), "tmp_chunk_%d.txt", i);

		FILE *fp = fopen(filename, "r");

		if(fp != NULL){

			long chunk_val = 0;

			if(fscanf(fp, "%ld", &chunk_val) == 1){

				total_sum += chunk_val;

			}

			fclose(fp);
			unlink(filename);

		}

	}

	free(pids);
	return total_sum;

}
