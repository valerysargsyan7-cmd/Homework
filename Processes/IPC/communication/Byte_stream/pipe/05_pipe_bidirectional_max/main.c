#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

int main()
{

	printf("\n\nBidirectional Full-Duplex Dual Pipe IPC: Max Computation\n\n");

	int fds_1[2];
	int fds_2[2];

	if(pipe(fds_1) == -1 || pipe(fds_2) == -1){

		perror("[ERROR] pipe creation failed");
		return 1;

	}

	pid_t pid_1 = fork();

	if(pid_1 < 0){

		perror("[ERROR] fork failed");
		return 1;

	}

	if(pid_1 == 0){

		//CHILD
		close(fds_1[1]);
		close(fds_2[0]);

		int child_buffer[2];

		ssize_t bytes_read = read(fds_1[0], child_buffer, sizeof(child_buffer));

		if(bytes_read > 0){

			printf("[CHILD]  -> Received two numbers: [%d, %d]\n", child_buffer[0], child_buffer[1]);

			int max_val = (child_buffer[0] >= child_buffer[1]) ? child_buffer[0] : child_buffer[1];

			printf("[CHILD]  -> Computed maximum: %d. Sending back to parent via Pipe 2...\n", max_val);

			write(fds_2[1], &max_val, sizeof(int));

		}

		close(fds_1[0]);
		close(fds_2[1]);
		exit(0);

	}else{

		//PARENT
		close(fds_1[0]);
		close(fds_2[1]);

		srand((unsigned int)time(NULL));

		int parent_buffer[2];
		parent_buffer[0] = rand() % 1000;
		parent_buffer[1] = rand() % 1000;

		printf("[PARENT] -> Generated numbers: [%d, %d]\n", parent_buffer[0], parent_buffer[1]);
		printf("[PARENT] -> Sending numbers to child via Pipe 1...\n");

		write(fds_1[1], parent_buffer, sizeof(parent_buffer));
		close(fds_1[1]);

		int result = 0;
		read(fds_2[0], &result, sizeof(int));
		close(fds_2[0]);

		printf("[PARENT] -> Received Maximum from child via Pipe 2: %d\n", result);

		wait(NULL);
		printf("[PARENT] -> Bidirectional exchange finished.\n");

	}

	return 0;

}
