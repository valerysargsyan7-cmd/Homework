#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{

	printf("\n\nFailed Exec\n\n");

	pid_t child_pid = fork();

	if(child_pid < 0){

		perror("[ERROR] fork failed");
		return 1;

	}else if(child_pid == 0){

		//CHILD
		execlp("fake_command", "fake_command", NULL);
		perror("\nError: command doesn't exist!");
		exit(1);

	}else{

		//PARENT
		wait(NULL);

	}

	return 0;

}
