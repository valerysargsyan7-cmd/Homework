#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{

	printf("\n\nChild Exit Status\n\n");

	pid_t child_proc = fork();

	if(child_proc < 0){

		perror("[ERROR] fork failed");
		return 1;

	}else if(child_proc == 0){

		//CHILD
		int exit_num = 0;

		printf("[CHILD] -> Enter number for exiting: ");

		if(scanf("%d", &exit_num) != 1){

			fprintf(stderr, "[ERROR] Invalid input. Defaulting exit code to 1.\n");
			exit(1);

		}

		exit(exit_num);

	}else{

		//PARENT
		int status;

		wait(&status);

		if(WIFEXITED(status)){

			printf("\n[PARENT] -> Child exited normally with status: %d\n", WEXITSTATUS(status));

		}else if(WIFSIGNALED(status)){

			printf("\n[PARENT] -> Child was terminated by signal: %d\n", WTERMSIG(status));

		}

	}

	return 0;

}
