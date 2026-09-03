#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int main()
{

	printf("\n\nProcess Group Termination via killpg\n\n");

	pid_t child_1;
	pid_t child_2;
	pid_t child_3;
	pid_t child_4;

	child_1 = fork();

	if(child_1 < 0){

		perror("[ERROR] fork child 1 failed");
		return 1;

	}

	if(child_1 == 0){

		setpgid(0, 0);
		while(1){

			sleep(1);

		}

	}else{

		child_2 = fork();

		if(child_2 < 0){

			perror("[ERROR] fork child 2 failed");
			kill(child_1, SIGKILL);
			return 1;

		}

		if(child_2 == 0){

			setpgid(0, child_1);
			while(1){

				sleep(1);

			}

		}else{

			child_3 = fork();

			if(child_3 < 0){

				perror("[ERROR] fork child 3 failed");
				killpg(child_1, SIGKILL);
				return 1;

			}

			if(child_3 == 0){

				printf("[CHILD 3] -> Running in parent group (PID: %d)...\n", getpid());
				sleep(1);
				printf("[CHILD 3] -> Finished normally.\n");
				exit(0);

			}else{

				child_4 = fork();

				if(child_4 < 0){

					perror("[ERROR] fork child 4 failed");
					killpg(child_1, SIGKILL);
					return 1;

				}

				if(child_4 == 0){

					printf("[CHILD 4] -> Running in parent group (PID: %d)...\n", getpid());
					sleep(1);
					printf("[CHILD 4] -> Finished normally.\n");
					exit(0);

				}else{

					setpgid(child_1, child_1);
					setpgid(child_2, child_1);

					printf("\n[PARENT] -> Children 1 & 2 assigned to PGID %d.\n", child_1);
					printf("[PARENT] -> Sleeping for 3 seconds before killing Group %d...\n", child_1);

					sleep(3);

					printf("[PARENT] -> Sending SIGKILL to Process Group %d via killpg()...\n", child_1);
					killpg(child_1, SIGKILL);

					int status;
					for(int i = 0; i < 4; i++){

						pid_t reaped = wait(&status);
						if(WIFSIGNALED(status)){

							printf("[PARENT] -> Child %d terminated by signal: %d\n", reaped, WTERMSIG(status));

						}else if(WIFEXITED(status)){

							printf("[PARENT] -> Child %d exited normally with status: %d\n", reaped, WEXITSTATUS(status));

						}

					}

					printf("[PARENT] -> All 4 children reaped.\n");

				}

			}

		}

	}

	return 0;

}
