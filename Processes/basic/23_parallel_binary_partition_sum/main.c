#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void reading_first_50(const char *filename);

int main()
{

	printf("\n\nParallel Binary Partition Summing\n\n");

	const char *data_filename = "data.bin";

	FILE *parent_data_file_fp = fopen(data_filename, "wb+");

	if(parent_data_file_fp == NULL){

		perror("[ERROR] File opening error in parent");
		return 1;

	}

	int nums[100];

	for(int i = 0; i < 100; i++){

		nums[i] = i + 1;

	}

	size_t written = fwrite(nums, sizeof(int), 100, parent_data_file_fp);
	fclose(parent_data_file_fp);

	if(written != 100){

		fprintf(stderr, "[ERROR] Failed to write 100 integers to %s\n", data_filename);
		return 1;

	}

	printf("[PARENT] -> Initialized '%s' with 100 integers (1..100).\n\n", data_filename);

	pid_t child_5 = fork();

	if(child_5 < 0){

		perror("[ERROR] fork child 5 failed");
		return 1;

	}

	if(child_5 == 0){

		//CHILD 5
		reading_first_50(data_filename);
		exit(0);

	}else{

		pid_t child_6 = fork();

		if(child_6 < 0){

			perror("[ERROR] fork child 6 failed");
			wait(NULL);
			return 1;

		}

		if(child_6 == 0){

			//CHILD 6
			FILE *child_data_file_fp = fopen(data_filename, "rb");

			if(child_data_file_fp == NULL){

				perror("[ERROR] File opening error in Child 6");
				exit(1);

			}

			if(fseek(child_data_file_fp, 50 * (long)sizeof(int), SEEK_SET) != 0){

				perror("[ERROR] fseek error in Child 6");
				fclose(child_data_file_fp);
				exit(1);

			}

			int child_buf[50];
			size_t read_count = fread(child_buf, sizeof(int), 50, child_data_file_fp);
			fclose(child_data_file_fp);

			if(read_count != 50){

				fprintf(stderr, "[ERROR] Child 6 failed to read 50 integers\n");
				exit(1);

			}

			int sec_res = 0;
			for(int i = 0; i < 50; i++){

				sec_res += child_buf[i];

			}

			printf("[CHILD 6] -> Sum of second partition (51..100): %d\n", sec_res);
			exit(0);

		}else{

			//PARENT
			wait(NULL);
			wait(NULL);

			printf("\n[PARENT] -> Both children finished processing partitions.\n");
			printf("[PARENT] -> Expected total sum (1..100) = 5050 (1275 + 3775).\n");

		}

	}

	return 0;

}

void reading_first_50(const char *filename)
{

	FILE *child_data_file_fp = fopen(filename, "rb");

	if(child_data_file_fp == NULL){

		perror("[ERROR] File opening error in Child 5");
		return;

	}

	int child_buf[50];
	size_t read_child = fread(child_buf, sizeof(int), 50, child_data_file_fp);
	fclose(child_data_file_fp);

	if(read_child != 50){

		fprintf(stderr, "[ERROR] Child 5 failed to read 50 integers\n");
		return;

	}

	int result = 0;
	for(int i = 0; i < 50; i++){

		result += child_buf[i];

	}

	printf("[CHILD 5] -> Sum of first partition (1..50): %d\n", result);

}
