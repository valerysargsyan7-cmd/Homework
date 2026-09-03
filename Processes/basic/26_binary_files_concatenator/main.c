#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <time.h>

int main()
{

	printf("\n\nDual Binary Files Concatenator\n\n");

	srand((unsigned int)time(NULL));
	int count = 20 + (rand() % 30);

	char *parent_arr1 = (char *)malloc((size_t)count * sizeof(char));
	char *parent_arr2 = (char *)malloc((size_t)count * sizeof(char));

	if(parent_arr1 == NULL || parent_arr2 == NULL){

		perror("[ERROR] malloc failed in parent");
		free(parent_arr1);
		free(parent_arr2);
		return 1;

	}

	for(int i = 0; i < count; i++){

		parent_arr1[i] = 'A';
		parent_arr2[i] = 'B';

	}

	const char *parent_arr1_filename = "arr1.bin";
	const char *parent_arr2_filename = "arr2.bin";

	int arr1_fd = open(parent_arr1_filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if(arr1_fd < 0){

		perror("[ERROR] Failed to create arr1.bin");
		free(parent_arr1);
		free(parent_arr2);
		return 1;

	}

	int arr2_fd = open(parent_arr2_filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if(arr2_fd < 0){

		perror("[ERROR] Failed to create arr2.bin");
		close(arr1_fd);
		free(parent_arr1);
		free(parent_arr2);
		return 1;

	}

	write(arr1_fd, parent_arr1, (size_t)count);
	write(arr2_fd, parent_arr2, (size_t)count);

	close(arr1_fd);
	close(arr2_fd);

	free(parent_arr1);
	free(parent_arr2);

	printf("[PARENT] -> Created '%s' and '%s' (%d bytes each).\n",
	       parent_arr1_filename, parent_arr2_filename, count);

	pid_t child_2 = fork();

	if(child_2 < 0){

		perror("[ERROR] fork failed");
		return 1;

	}

	if(child_2 == 0){

		//CHILD
		FILE *child_fp1 = fopen(parent_arr1_filename, "rb");
		if(child_fp1 == NULL){

			perror("[ERROR] child fopen arr1");
			exit(1);

		}

		fseek(child_fp1, 0, SEEK_END);
		long size1 = ftell(child_fp1);
		rewind(child_fp1);

		FILE *child_fp2 = fopen(parent_arr2_filename, "rb");
		if(child_fp2 == NULL){

			perror("[ERROR] child fopen arr2");
			fclose(child_fp1);
			exit(1);

		}

		fseek(child_fp2, 0, SEEK_END);
		long size2 = ftell(child_fp2);
		rewind(child_fp2);

		char *full = (char *)malloc((size_t)(size1 + size2 + 1));
		if(full == NULL){

			perror("[ERROR] malloc failed in child");
			fclose(child_fp1);
			fclose(child_fp2);
			exit(1);

		}

		fread(full, 1, (size_t)size1, child_fp1);
		fread(full + size1, 1, (size_t)size2, child_fp2);
		full[size1 + size2] = '\0';

		printf("\n[CHILD] -> Concatenated Data (%ld + %ld = %ld bytes):\n%s\n",
		       size1, size2, size1 + size2, full);

		free(full);
		fclose(child_fp1);
		fclose(child_fp2);

		printf("\n[CHILD] -> Work Status: DONE\n");
		exit(0);

	}else{

		//PARENT
		waitpid(child_2, NULL, 0);
		printf("[PARENT] -> Child completed concatenation. Finishing.\n");

	}

	return 0;

}
