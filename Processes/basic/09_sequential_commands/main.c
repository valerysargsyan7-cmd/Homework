#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{

	printf("\n\nSequential Commands Execution\n\n");

	pid_t child_proc_1 = fork();

	if(child_proc_1 < 0){

		perror("[ERROR] First child fork failed");
		return 1;

	}else if(child_proc_1 == 0){

		//CHILD 1
		execlp("ls", "ls", "-l", NULL);
		perror("[ERROR] First exec failed");
		exit(1);

	}else{

		//PARENT waits for Child 1
		waitpid(child_proc_1, NULL, 0);
		printf("\n[PARENT] -> First child done his work\n");

		printf("\n--------------------------------\n\n");

		pid_t child_proc_2 = fork();

		if(child_proc_2 < 0){

			perror("[ERROR] Second child fork failed");
			return 1;

		}else if(child_proc_2 == 0){

			//CHILD 2
			execlp("uname", "uname", "-a", NULL);
			perror("[ERROR] Second exec failed");
			exit(1);

		}else{

			//PARENT waits for Child 2
			waitpid(child_proc_2, NULL, 0);
			printf("\n[PARENT] -> Second child done his work\n");

		}

	}

	return 0;

}
