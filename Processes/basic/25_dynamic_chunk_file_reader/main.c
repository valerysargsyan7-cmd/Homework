#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{

	printf("\n\nDynamic Chunk File Reader with Realloc\n\n");

	const char *parent_fp_filename = "Parent_large_file.txt";
	FILE *parent_fp = fopen(parent_fp_filename, "w+");

	if(parent_fp == NULL){

		perror("[ERROR] Failed to create sample file");
		return 1;

	}

	fprintf(parent_fp, "This is a large file text that I create as a parent process. "
	                   "It contains multiple sentences to demonstrate dynamic buffer growth "
	                   "using 64-byte chunk reads and reallocation.\n");
	fflush(parent_fp);

	pid_t child_1 = fork();

	if(child_1 < 0){

		perror("[ERROR] fork failed");
		fclose(parent_fp);
		return 1;

	}

	if(child_1 == 0){

		//CHILD
		rewind(parent_fp);

		size_t capacity = 64;
		size_t total = 0;

		char *child_buf = (char *)malloc(capacity);

		if(child_buf == NULL){

			perror("[ERROR] malloc failed in child");
			fclose(parent_fp);
			exit(1);

		}

		size_t child_read_bytes;

		while((child_read_bytes = fread(child_buf + total, 1, 64, parent_fp)) != 0){

			total += child_read_bytes;

			if(total + 64 >= capacity){

				capacity += 64;
				char *new_buf = (char *)realloc(child_buf, capacity);

				if(new_buf == NULL){

					perror("[ERROR] realloc failed in child");
					free(child_buf);
					fclose(parent_fp);
					exit(1);

				}

				child_buf = new_buf;

			}

		}

		child_buf[total] = '\0';

		printf("\n[CHILD] -> Read %zu bytes dynamically:\n\"%s\"\n", total, child_buf);

		free(child_buf);
		fclose(parent_fp);

		printf("[CHILD] -> Work Status: DONE\n");
		exit(0);

	}else{

		//PARENT
		wait(NULL);
		fclose(parent_fp);
		printf("\n[PARENT] -> Child finished reading. File closed.\n");

	}

	return 0;

}
