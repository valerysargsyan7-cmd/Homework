#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/wait.h>

int main()
{

	printf("\n\nUnnamed Pipe IPC: Uppercase Text Stream Converter\n\n");

	int fds_2[2];

	if(pipe(fds_2) == -1){

		perror("[ERROR] pipe failed");
		return 1;

	}

	pid_t child_2 = fork();

	if(child_2 < 0){

		perror("[ERROR] fork failed");
		return 1;

	}

	if(child_2 == 0){

		//CHILD
		close(fds_2[1]);

		char child_2_buffer[100];
		memset(child_2_buffer, 0, sizeof(child_2_buffer));

		ssize_t bytes_read = read(fds_2[0], child_2_buffer, sizeof(child_2_buffer) - 1);

		if(bytes_read > 0){

			child_2_buffer[bytes_read] = '\0';

			for(int i = 0; child_2_buffer[i] != '\0'; i++){

				child_2_buffer[i] = (char)toupper((unsigned char)child_2_buffer[i]);

			}

			printf("[CHILD]  -> Converted to UPPERCASE: \"%s\"\n", child_2_buffer);

		}

		close(fds_2[0]);
		exit(0);

	}else{

		//PARENT
		close(fds_2[0]);

		const char *lowercase_message = "game over";
		printf("[PARENT] -> Sending message: \"%s\" through pipe...\n", lowercase_message);

		write(fds_2[1], lowercase_message, strlen(lowercase_message) + 1);
		close(fds_2[1]);

		wait(NULL);
		printf("[PARENT] -> Processing completed.\n");

	}

	return 0;

}
