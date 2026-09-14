#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{

	printf("\n\nFolder Creation\n\n");

	pid_t child_proc = fork();

	if(child_proc < 0){

		perror("[ERROR] fork failed");
		return 1;

	}else if(child_proc == 0){

		//CHILD
		execlp("mkdir", "mkdir", "-p", "NewHomework", NULL);

		perror("\n[ERROR] Creation failed");
		exit(1);

	}else{

		//PARENT
		int status;
		wait(&status);

		if(WIFEXITED(status) && WEXITSTATUS(status) == 0){

			printf("\n[PARENT] -> Folder created successfully!\n");

		}else{

			printf("\n[PARENT] -> Failed to create folder.\n");

		}

	}

	return 0;

}
