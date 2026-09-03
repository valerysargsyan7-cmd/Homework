#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int main()
{

	printf("\n\nKilling Process\n\n");

	pid_t child_process = fork();

	if(child_process < 0){

		perror("[ERROR] fork failed");
		return 1;

	}else if(child_process == 0){

		//CHILD

		while(1){

			printf("\nChild is running...\n");
			fflush(stdout);
			sleep(1);

		}

	}else{

		//PARENT

		sleep(3);
		printf("\nSending SIGKILL to child...\n");

		if(kill(child_process, SIGKILL) == -1){

			perror("[ERROR] kill failed");
			return 1;

		}

		int status;
		waitpid(child_process, &status, 0);

		if(WIFSIGNALED(status)){

			printf("Child terminated by signal: %d\n", WTERMSIG(status));

		}

		printf("Program finished.\n");

	}

	return 0;

}
