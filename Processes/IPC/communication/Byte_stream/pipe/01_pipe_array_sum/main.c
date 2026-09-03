#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int sum_array(const int *arr, int size);

int main()
{

	printf("\n\nUnnamed Pipe IPC: Integer Array Summation\n\n");

	int fds_1[2];

	if(pipe(fds_1) == -1){

		perror("[ERROR] pipe failed");
		return 1;

	}

	pid_t child_1 = fork();

	if(child_1 < 0){

		perror("[ERROR] fork failed");
		return 1;

	}

	if(child_1 == 0){

		//CHILD
		close(fds_1[1]);

		int child_1_buffer[5];
		int size = 5;

		ssize_t bytes_read = read(fds_1[0], child_1_buffer, sizeof(child_1_buffer));

		if(bytes_read > 0){

			int result = sum_array(child_1_buffer, size);
			printf("[CHILD] -> Received %zd bytes from pipe.\n", bytes_read);
			printf("[CHILD] -> Calculated sum: %d\n", result);

		}

		close(fds_1[0]);
		exit(0);

	}else{

		//PARENT
		close(fds_1[0]);

		int message[] = {1, 2, 3, 4, 5};
		printf("[PARENT] -> Sending array {1, 2, 3, 4, 5} through pipe write-end...\n");

		write(fds_1[1], message, sizeof(message));
		close(fds_1[1]);

		wait(NULL);
		printf("[PARENT] -> Child processing complete. Exiting.\n");

	}

	return 0;

}

int sum_array(const int *arr, int size)
{

	int sum = 0;

	for(int i = 0; i < size; i++){

		sum += arr[i];

	}

	return sum;

}
