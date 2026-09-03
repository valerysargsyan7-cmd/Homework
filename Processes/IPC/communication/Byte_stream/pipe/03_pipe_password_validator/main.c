#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main()
{

	printf("\n\nUnnamed Pipe IPC: Process Password Validator\n\n");

	int fds_3[2];

	if(pipe(fds_3) == -1){

		perror("[ERROR] pipe failed");
		return 1;

	}

	pid_t child_3 = fork();

	if(child_3 < 0){

		perror("[ERROR] fork failed");
		return 1;

	}

	if(child_3 == 0){

		//CHILD
		close(fds_3[1]);

		const char *correct_pass = "password123";
		char child_3_buffer[100];
		memset(child_3_buffer, 0, sizeof(child_3_buffer));

		ssize_t bytes_read = read(fds_3[0], child_3_buffer, sizeof(child_3_buffer) - 1);

		if(bytes_read > 0){

			child_3_buffer[bytes_read] = '\0';

			if(strcmp(correct_pass, child_3_buffer) == 0){

				printf("[AUTHENTICATOR CHILD] -> Password match! Status: [ACCESS GRANTED]\n");

			}else{

				printf("[AUTHENTICATOR CHILD] -> Incorrect password! Status: [ACCESS DENIED]\n");

			}

		}

		close(fds_3[0]);
		exit(0);

	}else{

		//PARENT
		close(fds_3[0]);

		char password[100];
		printf("Enter password to authenticate: ");

		if(scanf("%99s", password) != 1){

			strncpy(password, "abdulhamid", sizeof(password));

		}

		printf("[PARENT] -> Sending password to Authenticator child process via pipe...\n");

		write(fds_3[1], password, strlen(password) + 1);
		close(fds_3[1]);

		wait(NULL);
		printf("[PARENT] -> Authentication verification concluded.\n");

	}

	return 0;

}
