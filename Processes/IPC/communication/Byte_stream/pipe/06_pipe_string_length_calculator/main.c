#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main()
{

	printf("\n\nUnnamed Pipe IPC: Character Stream Length Counter\n\n");

	int fds[2];

	if(pipe(fds) == -1){

		perror("[ERROR] pipe failed");
		return 1;

	}

	pid_t pid_1 = fork();

	if(pid_1 < 0){

		perror("[ERROR] fork failed");
		return 1;

	}

	if(pid_1 == 0){

		//CHILD
		close(fds[1]);

		char child_buffer[100];
		memset(child_buffer, 0, sizeof(child_buffer));

		ssize_t bytes_read = read(fds[0], child_buffer, sizeof(child_buffer) - 1);

		if(bytes_read > 0){

			child_buffer[bytes_read] = '\0';

			int counter = 0;

			while(child_buffer[counter] != '\0'){

				counter++;

			}

			printf("[CHILD]  -> Received stream: \"%s\"\n", child_buffer);
			printf("[CHILD]  -> Computed length: %d characters\n", counter);

		}

		close(fds[0]);
		exit(0);

	}else{

		//PARENT
		close(fds[0]);

		const char *parent_text = "Pipes are fun!";
		printf("[PARENT] -> Transmitting text string: \"%s\" via pipe...\n", parent_text);

		write(fds[1], parent_text, strlen(parent_text) + 1);
		close(fds[1]);

		wait(NULL);
		printf("[PARENT] -> Processing concluded.\n");

	}

	return 0;

}
