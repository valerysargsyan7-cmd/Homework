#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{

	printf("\n\nUnnamed Pipe IPC: Integer Dataset Stream & Filter\n\n");

	int fds_4[2];

	if(pipe(fds_4) == -1){

		perror("[ERROR] pipe failed");
		return 1;

	}

	pid_t child_4 = fork();

	if(child_4 < 0){

		perror("[ERROR] fork failed");
		return 1;

	}

	if(child_4 == 0){

		//CHILD
		close(fds_4[1]);

		int child_4_buffer[10];

		ssize_t bytes_read = read(fds_4[0], child_4_buffer, sizeof(child_4_buffer));
		int count = (int)(bytes_read / sizeof(int));

		printf("[CHILD FILTER] -> Received %d integers from stream.\n", count);
		printf("[CHILD FILTER] -> Filtering and printing even numbers: ");

		for(int i = 0; i < count; i++){

			if(child_4_buffer[i] % 2 == 0){

				printf("%d ", child_4_buffer[i]);

			}

		}

		printf("\n");
		close(fds_4[0]);
		exit(0);

	}else{

		//PARENT
		close(fds_4[0]);

		int numbers[10];

		for(int i = 0; i < 10; i++){

			numbers[i] = i + 1;

		}

		printf("[PARENT] -> Transmitting dataset {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} via pipe...\n");

		write(fds_4[1], numbers, sizeof(numbers));
		close(fds_4[1]);

		wait(NULL);
		printf("[PARENT] -> Child stream filtering finished.\n");

	}

	return 0;

}
