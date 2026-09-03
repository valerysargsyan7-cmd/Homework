#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <time.h>

int main()
{

	printf("\n\nParallel Dataset Max Search via Mmap & Shared Memory\n\n");

	const char *filepath = "search_dataset.bin";
	int total_elements = 10000;
	size_t dataset_bytes = (size_t)total_elements * sizeof(int);

	int fd = open(filepath, O_CREAT | O_RDWR | O_TRUNC, 0644);

	if(fd < 0){

		perror("[ERROR] Failed to create dataset file");
		return 1;

	}

	srand((unsigned int)time(NULL));

	for(int i = 0; i < total_elements; i++){

		int val = rand() % 100000;
		write(fd, &val, sizeof(int));

	}

	int *par_file = (int *)mmap(NULL, dataset_bytes, PROT_READ, MAP_SHARED, fd, 0);

	int *child_max = (int *)mmap(NULL, 2 * sizeof(int),
	                             PROT_READ | PROT_WRITE,
	                             MAP_SHARED | MAP_ANONYMOUS,
	                             -1, 0);

	if(par_file == MAP_FAILED || child_max == MAP_FAILED){

		perror("[ERROR] mmap failed");
		close(fd);
		return 1;

	}

	pid_t pid_1 = fork();

	if(pid_1 < 0){

		perror("[ERROR] fork child 1 failed");
		munmap(par_file, dataset_bytes);
		munmap(child_max, 2 * sizeof(int));
		close(fd);
		return 1;

	}

	if(pid_1 == 0){

		//CHILD 1
		int max_ch1 = par_file[0];

		for(int i = 1; i < 5000; i++){

			if(par_file[i] > max_ch1){

				max_ch1 = par_file[i];

			}

		}

		child_max[0] = max_ch1;
		printf("[CHILD 1] -> Max in partition 1 (0..4999): %d\n", max_ch1);
		exit(0);

	}

	pid_t pid_2 = fork();

	if(pid_2 < 0){

		perror("[ERROR] fork child 2 failed");
		wait(NULL);
		munmap(par_file, dataset_bytes);
		munmap(child_max, 2 * sizeof(int));
		close(fd);
		return 1;

	}

	if(pid_2 == 0){

		//CHILD 2
		int max_ch2 = par_file[5000];

		for(int i = 5001; i < 10000; i++){

			if(par_file[i] > max_ch2){

				max_ch2 = par_file[i];

			}

		}

		child_max[1] = max_ch2;
		printf("[CHILD 2] -> Max in partition 2 (5000..9999): %d\n", max_ch2);
		exit(0);

	}

	//PARENT
	wait(NULL);
	wait(NULL);

	printf("\n[PARENT] -> Both children finished searching.\n");

	int overall_max = (child_max[0] > child_max[1]) ? child_max[0] : child_max[1];
	int winner_partition = (child_max[0] > child_max[1]) ? 1 : 2;

	printf("[PARENT] -> Partition 1 Max: %d\n", child_max[0]);
	printf("[PARENT] -> Partition 2 Max: %d\n", child_max[1]);
	printf("\n[PARENT] -> Overall Global Maximum: %d (Found by Child %d)\n",
	       overall_max, winner_partition);

	munmap(par_file, dataset_bytes);
	munmap(child_max, 2 * sizeof(int));
	close(fd);

	return 0;

}
