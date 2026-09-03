#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/mman.h>

int *create_shared_int_array(int size);

int main()
{

	printf("\n\nAnonymous Shared Memory Array (IPC)\n\n");

	int size = 10;

	int *par_arr = create_shared_int_array(size);

	if(par_arr == NULL){

		fprintf(stderr, "[ERROR] Failed to allocate anonymous shared array.\n");
		return 1;

	}

	pid_t pid_1 = fork();

	if(pid_1 < 0){

		perror("[ERROR] fork failed");
		munmap(par_arr, (size_t)size * sizeof(int));
		return 1;

	}

	if(pid_1 == 0){

		//CHILD
		printf("[CHILD] -> Populating shared array in child process...\n");

		for(int i = 0; i < size; i++){

			par_arr[i] = (i + 1) * 5;

		}

		printf("[CHILD] -> Finished writing to shared memory. Exiting.\n");
		exit(0);

	}else{

		//PARENT
		wait(NULL);

		printf("\n[PARENT] -> Reading shared array populated by child:\n");

		for(int i = 0; i < size; i++){

			printf("Element[%d] = %d\n", i, par_arr[i]);

		}

		munmap(par_arr, (size_t)size * sizeof(int));
		printf("\n[PARENT] -> Memory unmapped cleanly.\n");

	}

	return 0;

}

int *create_shared_int_array(int size)
{

	if(size <= 0){

		return NULL;

	}

	int *array = (int *)mmap(NULL, (size_t)size * sizeof(int),
	                         PROT_READ | PROT_WRITE,
	                         MAP_SHARED | MAP_ANONYMOUS,
	                         -1, 0);

	if(array == MAP_FAILED){

		perror("[ERROR] mmap anonymous failed");
		return NULL;

	}

	return array;

}
