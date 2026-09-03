#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{

	printf("\n\nChild Wait\n\n");

	pid_t child_proc = fork();

	if(child_proc < 0){

		perror("[ERROR] fork failed");
		return 1;

	}else if(child_proc == 0){

		//CHILD
		printf("\n[CHILD] -> Loading...\n");
		sleep(3);
		exit(0);

	}else{

		//PARENT
		wait(NULL);
		printf("\n[PARENT] -> CHILD ended, I am ending too...\n");

	}

	return 0;

}
