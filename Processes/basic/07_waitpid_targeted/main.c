#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{

	printf("\n\nWaitpid Targeted\n\n");

	pid_t child_proc_1 = fork();

	if(child_proc_1 < 0){

		perror("[ERROR] First child fork failed");
		return 1;

	}else if(child_proc_1 == 0){

		//CHILD 1
		printf("[CHILD 1] -> Sleeping for 1 second...\n");
		sleep(1);
		printf("[CHILD 1] -> Done.\n");
		exit(0);

	}else{

		pid_t child_proc_2 = fork();

		if(child_proc_2 < 0){

			perror("[ERROR] Second child fork failed");
			wait(NULL);
			return 1;

		}else if(child_proc_2 == 0){

			//CHILD 2
			printf("[CHILD 2] -> Sleeping for 4 seconds...\n");
			sleep(4);
			printf("[CHILD 2] -> Done.\n");
			exit(0);

		}else{

			//PARENT
			printf("\n[PARENT] -> Waiting specifically for Child 2 (PID: %d)...\n", child_proc_2);
			waitpid(child_proc_2, NULL, 0);

			printf("[PARENT] -> Child 2 finished, now parent can exit\n");

			// Reaping Child 1
			waitpid(child_proc_1, NULL, 0);

		}

	}

	return 0;

}
