#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/mman.h>

int main()
{

	printf("\n\nMmap Shared Memory vs Malloc Heap (Process Isolation)\n\n");

	size_t count = 5;

	int *shared_mmap_arr = (int *)mmap(NULL, count * sizeof(int),
	                                   PROT_READ | PROT_WRITE,
	                                   MAP_SHARED | MAP_ANONYMOUS,
	                                   -1, 0);

	int *private_heap_arr = (int *)malloc(count * sizeof(int));

	if(shared_mmap_arr == MAP_FAILED || private_heap_arr == NULL){

		perror("[ERROR] Allocation failed");
		return 1;

	}

	for(size_t i = 0; i < count; i++){

		shared_mmap_arr[i] = 0;
		private_heap_arr[i] = 0;

	}

	printf("Initial states in parent: all elements = 0\n");

	pid_t pid = fork();

	if(pid < 0){

		perror("[ERROR] fork failed");
		munmap(shared_mmap_arr, count * sizeof(int));
		free(private_heap_arr);
		return 1;

	}

	if(pid == 0){

		//CHILD
		printf("[CHILD] -> Writing 10, 20, 30, 40, 50 to both buffers in child...\n");

		for(size_t i = 0; i < count; i++){

			shared_mmap_arr[i] = (int)(i + 1) * 10;
			private_heap_arr[i] = (int)(i + 1) * 10;

		}

		exit(0);

	}else{

		//PARENT
		wait(NULL);

		printf("\n[PARENT] -> Inspecting values in parent process after child exited:\n\n");

		printf("--- MAP_SHARED Array (Visible across processes) ---\n");
		for(size_t i = 0; i < count; i++){

			printf("  mmap[%zu] = %d\n", i, shared_mmap_arr[i]);

		}

		printf("\n--- Malloc Heap Array (Isolated in parent address space) ---\n");
		for(size_t i = 0; i < count; i++){

			printf("  malloc[%zu] = %d\n", i, private_heap_arr[i]);

		}

		printf("\nConclusion: 'malloc' heap memory is isolated per process.\n"
		       "            'mmap(MAP_SHARED)' shares physical memory across processes.\n");

		munmap(shared_mmap_arr, count * sizeof(int));
		free(private_heap_arr);

	}

	return 0;

}
